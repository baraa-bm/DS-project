#include "persistence.h"

#include <fstream>
#include <sstream>
#include <mutex>
#include <cstdio>
#include <vector>

namespace {
    std::mutex g_persistMutex;

    bool endsWithInsensitive(const std::string& s, const std::string& suffix) {
        if (s.size() < suffix.size()) return false;
        for (size_t i = 0; i < suffix.size(); i++) {
            char a = s[s.size() - suffix.size() + i];
            char b = suffix[i];
            if (a >= 'A' && a <= 'Z') a = char(a - 'A' + 'a');
            if (b >= 'A' && b <= 'Z') b = char(b - 'A' + 'a');
            if (a != b) return false;
        }
        return true;
    }

    std::string escapeJson(const std::string& in) {
        std::string out;
        out.reserve(in.size() + 8);
        for (size_t i = 0; i < in.size(); i++) {
            char c = in[i];
            switch (c) {
                case '\\': out += "\\\\"; break;
                case '"': out += "\\\""; break;
                case '\n': out += "\\n"; break;
                case '\r': out += "\\r"; break;
                case '\t': out += "\\t"; break;
                default: out += c; break;
            }
        }
        return out;
    }

    std::string statusToString(status s) {
        if (s == pending) return "pending";
        if (s == current) return "current";
        return "completed";
    }

    bool stringToStatus(const std::string& s, status& out) {
        if (s == "pending") { out = pending; return true; }
        if (s == "current") { out = current; return true; }
        if (s == "completed") { out = completed; return true; }
        return false;
    }

    // --- very small, structure-specific JSON reader helpers ---
    bool findKey(const std::string& json, const std::string& key, size_t& pos) {
        std::string needle = "\"" + key + "\"";
        pos = json.find(needle);
        if (pos == std::string::npos) return false;
        pos = json.find(':', pos + needle.size());
        return pos != std::string::npos;
    }

    bool readIntAfterColon(const std::string& json, size_t colonPos, int& out) {
        size_t i = colonPos + 1;
        while (i < json.size() && (json[i] == ' ' || json[i] == '\n' || json[i] == '\r' || json[i] == '\t')) i++;
        bool neg = false;
        if (i < json.size() && json[i] == '-') { neg = true; i++; }
        if (i >= json.size() || json[i] < '0' || json[i] > '9') return false;
        long long v = 0;
        while (i < json.size() && json[i] >= '0' && json[i] <= '9') {
            v = v * 10 + (json[i] - '0');
            i++;
        }
        out = neg ? int(-v) : int(v);
        return true;
    }

    bool readStringAfterColon(const std::string& json, size_t colonPos, std::string& out) {
        size_t i = colonPos + 1;
        while (i < json.size() && (json[i] == ' ' || json[i] == '\n' || json[i] == '\r' || json[i] == '\t')) i++;
        if (i >= json.size() || json[i] != '"') return false;
        i++;
        std::string s;
        while (i < json.size()) {
            char c = json[i++];
            if (c == '"') break;
            if (c == '\\' && i < json.size()) {
                char e = json[i++];
                if (e == 'n') s += '\n';
                else if (e == 'r') s += '\r';
                else if (e == 't') s += '\t';
                else s += e;
            } else {
                s += c;
            }
        }
        out = s;
        return true;
    }

    bool acquireLockFile(const std::string& path, std::string* error, std::string& lockPathOut) {
        lockPathOut = path + ".lock";
        std::ifstream exists(lockPathOut.c_str(), std::ios::in);
        if (exists.good()) {
            if (error) *error = "Another save/load seems in progress (lock file exists): " + lockPathOut;
            return false;
        }
        std::ofstream lock(lockPathOut.c_str(), std::ios::out | std::ios::trunc);
        if (!lock.is_open()) {
            if (error) *error = "Failed to create lock file: " + lockPathOut;
            return false;
        }
        lock << "locked\n";
        return true;
    }

    void releaseLockFile(const std::string& lockPath) {
        std::remove(lockPath.c_str());
    }
}

bool PersistenceManager::saveToFile(const std::string& path, const manager& mgr, const Time& globalTime, std::string* error) {
    std::lock_guard<std::mutex> guard(g_persistMutex);

    std::string lockPath;
    if (!acquireLockFile(path, error, lockPath)) return false;

    bool ok = false;
    if (endsWithInsensitive(path, ".json")) ok = saveAsJson(path, mgr, globalTime, error);
    else ok = saveAsTxt(path, mgr, globalTime, error);

    releaseLockFile(lockPath);
    return ok;
}

manager* PersistenceManager::loadNewFromFile(const std::string& path, PersistedState& outState, std::string* error) {
    std::lock_guard<std::mutex> guard(g_persistMutex);

    std::string lockPath;
    if (!acquireLockFile(path, error, lockPath)) return false;

    manager* fresh = new manager();
    // Important: your current code doesn't initialize this pointer.
    fresh->currentTask = nullptr;

    bool ok = false;
    if (endsWithInsensitive(path, ".json")) ok = loadFromJson(path, *fresh, outState, error);
    else ok = loadFromTxt(path, *fresh, outState, error);

    releaseLockFile(lockPath);
    if (!ok) {
        delete fresh;
        return nullptr;
    }
    return fresh;
}

bool PersistenceManager::saveAsTxt(const std::string& path, const manager& mgr, const Time& globalTime, std::string* error) {
    std::ofstream out(path.c_str(), std::ios::out | std::ios::trunc);
    if (!out.is_open()) {
        if (error) *error = "Failed to open file for writing: " + path;
        return false;
    }

    out << "VERSION 1\n";
    out << "GLOBAL_TIME " << globalTime.hours << " " << globalTime.minutes << "\n";
    out << "COMPLETED_TASKS " << mgr.completedTasks << "\n";
    out << "TASK_COUNT " << mgr.l_tasks.sizeOfList() << "\n";

    for (int i = 0; i < mgr.l_tasks.sizeOfList(); i++) {
        const task& t = mgr.l_tasks[i];
        out << "TASK "
            << t.ID << "|"
            << t.name << "|"
            << t.priority << "|"
            << statusToString(t._status) << "|"
            << t.arrival_time.hours << "|" << t.arrival_time.minutes << "|"
            << t.excution_duration.hours << "|" << t.excution_duration.minutes << "|"
            << t.start_time.hours << "|" << t.start_time.minutes
            << "\n";
    }

    return true;
}

static bool splitByChar(const std::string& s, char delim, std::vector<std::string>& parts) {
    parts.clear();
    std::string cur;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == delim) {
            parts.push_back(cur);
            cur.clear();
        } else cur += s[i];
    }
    parts.push_back(cur);
    return true;
}

bool PersistenceManager::loadFromTxt(const std::string& path, manager& mgr, PersistedState& outState, std::string* error) {
    std::ifstream in(path.c_str(), std::ios::in);
    if (!in.is_open()) {
        if (error) *error = "Failed to open file for reading: " + path;
        return false;
    }

    std::string line;
    int version = 0;
    int expectedTasks = -1;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string tag;
        iss >> tag;

        if (tag == "VERSION") {
            iss >> version;
        } else if (tag == "GLOBAL_TIME") {
            iss >> outState.globalTime.hours >> outState.globalTime.minutes;
        } else if (tag == "COMPLETED_TASKS") {
            iss >> mgr.completedTasks;
        } else if (tag == "TASK_COUNT") {
            iss >> expectedTasks;
        } else if (tag == "TASK") {
            std::string rest;
            std::getline(iss, rest);
            if (!rest.empty() && rest[0] == ' ') rest = rest.substr(1);

            std::vector<std::string> parts;
            splitByChar(rest, '|', parts);
            if (parts.size() != 10) {
                if (error) *error = "Invalid TASK line format (expected 10 fields): " + line;
                return false;
            }

            task t;
            t.ID = std::atoi(parts[0].c_str());
            t.name = parts[1];
            t.priority = std::atoi(parts[2].c_str());
            {
                status st;
                if (!stringToStatus(parts[3], st)) {
                    if (error) *error = "Invalid task status: " + parts[3];
                    return false;
                }
                t._status = st;
            }
            t.arrival_time = Time(std::atoi(parts[4].c_str()), std::atoi(parts[5].c_str()));
            t.excution_duration = Time(std::atoi(parts[6].c_str()), std::atoi(parts[7].c_str()));
            t.start_time = Time(std::atoi(parts[8].c_str()), std::atoi(parts[9].c_str()));

            task* heapTask = new task();
            *heapTask = t;
            mgr.addtask(heapTask, heapTask->priority);
        }
    }

    if (version != 1) {
        if (error) *error = "Unsupported save version: " + std::to_string(version);
        return false;
    }

    if (expectedTasks >= 0 && expectedTasks != mgr.l_tasks.sizeOfList()) {
        if (error) *error = "TASK_COUNT mismatch: expected " + std::to_string(expectedTasks) + ", got " + std::to_string(mgr.l_tasks.sizeOfList());
        return false;
    }

    return true;
}

bool PersistenceManager::saveAsJson(const std::string& path, const manager& mgr, const Time& globalTime, std::string* error) {
    std::ofstream out(path.c_str(), std::ios::out | std::ios::trunc);
    if (!out.is_open()) {
        if (error) *error = "Failed to open file for writing: " + path;
        return false;
    }

    out << "{\n";
    out << "  \"version\": 1,\n";
    out << "  \"globalTime\": { \"hours\": " << globalTime.hours << ", \"minutes\": " << globalTime.minutes << " },\n";
    out << "  \"completedTasks\": " << mgr.completedTasks << ",\n";
    out << "  \"tasks\": [\n";

    for (int i = 0; i < mgr.l_tasks.sizeOfList(); i++) {
        const task& t = mgr.l_tasks[i];
        out << "    {\n";
        out << "      \"ID\": " << t.ID << ",\n";
        out << "      \"name\": \"" << escapeJson(t.name) << "\",\n";
        out << "      \"priority\": " << t.priority << ",\n";
        out << "      \"status\": \"" << statusToString(t._status) << "\",\n";
        out << "      \"arrival_time\": { \"hours\": " << t.arrival_time.hours << ", \"minutes\": " << t.arrival_time.minutes << " },\n";
        out << "      \"excution_duration\": { \"hours\": " << t.excution_duration.hours << ", \"minutes\": " << t.excution_duration.minutes << " },\n";
        out << "      \"start_time\": { \"hours\": " << t.start_time.hours << ", \"minutes\": " << t.start_time.minutes << " }\n";
        out << "    }" << (i + 1 == mgr.l_tasks.sizeOfList() ? "\n" : ",\n");
    }

    out << "  ]\n";
    out << "}\n";
    return true;
}

bool PersistenceManager::loadFromJson(const std::string& path, manager& mgr, PersistedState& outState, std::string* error) {
    std::ifstream in(path.c_str(), std::ios::in);
    if (!in.is_open()) {
        if (error) *error = "Failed to open file for reading: " + path;
        return false;
    }

    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string json = buffer.str();

    int version = 0;
    {
        size_t pos;
        if (!findKey(json, "version", pos) || !readIntAfterColon(json, pos, version)) {
            if (error) *error = "Invalid JSON: missing/invalid version";
            return false;
        }
        if (version != 1) {
            if (error) *error = "Unsupported save version: " + std::to_string(version);
            return false;
        }
    }

    {
        // globalTime.hours / globalTime.minutes
        size_t gtPos;
        if (!findKey(json, "globalTime", gtPos)) {
            if (error) *error = "Invalid JSON: missing globalTime";
            return false;
        }
        // Search inside the globalTime object region (rough but sufficient for this fixed schema)
        size_t objStart = json.find('{', gtPos);
        size_t objEnd = json.find('}', objStart);
        if (objStart == std::string::npos || objEnd == std::string::npos) {
            if (error) *error = "Invalid JSON: malformed globalTime object";
            return false;
        }
        std::string gtObj = json.substr(objStart, objEnd - objStart + 1);
        size_t hPos, mPos;
        if (!findKey(gtObj, "hours", hPos) || !readIntAfterColon(gtObj, hPos, outState.globalTime.hours)) return false;
        if (!findKey(gtObj, "minutes", mPos) || !readIntAfterColon(gtObj, mPos, outState.globalTime.minutes)) return false;
    }

    {
        size_t pos;
        if (!findKey(json, "completedTasks", pos) || !readIntAfterColon(json, pos, mgr.completedTasks)) {
            if (error) *error = "Invalid JSON: missing/invalid completedTasks";
            return false;
        }
    }

    size_t tasksKeyPos;
    if (!findKey(json, "tasks", tasksKeyPos)) {
        if (error) *error = "Invalid JSON: missing tasks";
        return false;
    }
    size_t arrStart = json.find('[', tasksKeyPos);
    size_t arrEnd = json.find(']', arrStart);
    if (arrStart == std::string::npos || arrEnd == std::string::npos) {
        if (error) *error = "Invalid JSON: malformed tasks array";
        return false;
    }

    std::string arr = json.substr(arrStart + 1, arrEnd - arrStart - 1);
    size_t i = 0;
    while (i < arr.size()) {
        size_t objS = arr.find('{', i);
        if (objS == std::string::npos) break;
        size_t objE = arr.find('}', objS);
        if (objE == std::string::npos) {
            if (error) *error = "Invalid JSON: unterminated task object";
            return false;
        }
        std::string obj = arr.substr(objS, objE - objS + 1);
        i = objE + 1;

        task t;
        {
            size_t pos;
            if (!findKey(obj, "ID", pos) || !readIntAfterColon(obj, pos, t.ID)) {
                if (error) *error = "Invalid JSON: task missing ID";
                return false;
            }
        }
        {
            size_t pos;
            std::string s;
            if (!findKey(obj, "name", pos) || !readStringAfterColon(obj, pos, s)) {
                if (error) *error = "Invalid JSON: task missing name";
                return false;
            }
            t.name = s;
        }
        {
            size_t pos;
            if (!findKey(obj, "priority", pos) || !readIntAfterColon(obj, pos, t.priority)) {
                if (error) *error = "Invalid JSON: task missing priority";
                return false;
            }
        }
        {
            size_t pos;
            std::string s;
            if (!findKey(obj, "status", pos) || !readStringAfterColon(obj, pos, s)) {
                if (error) *error = "Invalid JSON: task missing status";
                return false;
            }
            status st;
            if (!stringToStatus(s, st)) {
                if (error) *error = "Invalid JSON: unknown status " + s;
                return false;
            }
            t._status = st;
        }

        auto readTimeObject = [&](const std::string& key, Time& outTime) -> bool {
            size_t keyPos;
            if (!findKey(obj, key, keyPos)) return false;
            size_t oS = obj.find('{', keyPos);
            size_t oE = obj.find('}', oS);
            if (oS == std::string::npos || oE == std::string::npos) return false;
            std::string tObj = obj.substr(oS, oE - oS + 1);
            size_t hPos, mPos;
            int h = 0, m = 0;
            if (!findKey(tObj, "hours", hPos) || !readIntAfterColon(tObj, hPos, h)) return false;
            if (!findKey(tObj, "minutes", mPos) || !readIntAfterColon(tObj, mPos, m)) return false;
            outTime = Time(h, m);
            return true;
        };

        if (!readTimeObject("arrival_time", t.arrival_time)) {
            if (error) *error = "Invalid JSON: task missing arrival_time";
            return false;
        }
        if (!readTimeObject("excution_duration", t.excution_duration)) {
            if (error) *error = "Invalid JSON: task missing excution_duration";
            return false;
        }
        if (!readTimeObject("start_time", t.start_time)) {
            if (error) *error = "Invalid JSON: task missing start_time";
            return false;
        }

        task* heapTask = new task();
        *heapTask = t;
        mgr.addtask(heapTask, heapTask->priority);
    }

    return true;
}

