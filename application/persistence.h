#ifndef DS_PROJECT_PERSISTENCE_H
#define DS_PROJECT_PERSISTENCE_H

#include <string>

#include "../DataStructures/time.h"
#include "manager.h"

struct PersistedState {
    Time globalTime;
};

class PersistenceManager {
public:
    static bool saveToFile(const std::string& path, const manager& mgr, const Time& globalTime, std::string* error);
    // Loads into a brand-new manager (avoids overlaps/duplication without requiring
    // manager.clearAll() or copying internal data structures).
    static manager* loadNewFromFile(const std::string& path, PersistedState& outState, std::string* error);

private:
    static bool saveAsJson(const std::string& path, const manager& mgr, const Time& globalTime, std::string* error);
    static bool loadFromJson(const std::string& path, manager& mgr, PersistedState& outState, std::string* error);

    static bool saveAsTxt(const std::string& path, const manager& mgr, const Time& globalTime, std::string* error);
    static bool loadFromTxt(const std::string& path, manager& mgr, PersistedState& outState, std::string* error);
};

#endif
