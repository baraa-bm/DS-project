#include <iostream>
#include <fstream>
#include "manager.h"
#include "persistence.h"
#include "user.h"

#include <string>
#include <limits>

using namespace std;

Time globalTime(0, 0);
int x;
void advanceTime(int h, int m){
    globalTime.hours += h;
    globalTime.minutes += m;
}

static void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static bool readInt(const char* prompt, int& out) {
    cout << prompt;
    if (!(cin >> out)) {
        clearBadInput();
        return false;
    }
    return true;
}

static bool readTwoInts(const char* prompt, int& a, int& b) {
    cout << prompt;
    if (!(cin >> a >> b)) {
        clearBadInput();
        return false;
    }
    return true;
}

static void readWord(const char* prompt, string& out) {
    cout << prompt;
    cin >> out; // one-word names (no spaces)
}

const string USERS_FILE = "users.txt";

// helper function to register a new user
static bool registerUser(const string& username, const string& password) {
    ifstream inFile(USERS_FILE);
    string u, p;

    // check if the username already exists
    if (inFile.is_open()) {
        while (inFile >> u >> p) {
            if (u == username) {
                inFile.close();
                return false; // User already exists!
            }
        }
        inFile.close();
    }

    // if it doesn't exist, append the new user to the file
    ofstream outFile(USERS_FILE, ios::app);
    if (outFile.is_open()) {
        outFile << username << " " << password << "\n";
        outFile.close();
        return true;
    }
    return false;
}

// helper function to verify login
static bool loginUser(const string& username, const string& password) {
    ifstream inFile(USERS_FILE);
    string u, p;

    if (inFile.is_open()) {
        while (inFile >> u >> p) {
            if (u == username && p == password) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
    }
    return false;
}

int main(){
    bool loggedIn = false;
    // system login (happens only once when application is started up)
    string currentLoggedUser = ""; // store who is logged in here for the future

    cout << "--- Welcome to the Task Manager ---\n";

    while (!loggedIn) {
        cout << "\n1. Sign Up\n";
        cout << "2. Login\n";
        cout << "0. Exit\n";

        int authChoice;
        if (!readInt("Choice: ", authChoice)) continue;

        if (authChoice == 0) {
            cout << "Goodbye!\n";
            return 0; // exit the program entirely
        }

        string uName, pwd;
        if (authChoice == 1) {
            // sign up logic
            readWord("Enter new username (one word): ", uName);
            readWord("Enter new password (one word): ", pwd);

            if (registerUser(uName, pwd)) {
                cout << "Sign up successful! You can now log in.\n";
            } else {
                cout << "Error: Username already exists. Please choose another.\n";
            }

        } else if (authChoice == 2) {
            // login logic
            readWord("Username: ", uName);
            readWord("Password: ", pwd);

            if (loginUser(uName, pwd)) {
                cout << "\nLogin successful! Welcome, " << uName << ".\n";
                currentLoggedUser = uName;
                loggedIn = true; // This breaks the loop and enters the main application
            } else {
                cout << "Incorrect credentials. Try again.\n";
            }
        } else {
            cout << "Invalid choice. Please select 1, 2, or 0.\n";
        }
    }
    manager* mgr = new manager();
    mgr->currentTask = nullptr;
    bool isRunning = true;
    while(isRunning){

        //load data

        //options
        cout << "\n========== Options ============\n";
        cout << "1- Add a task\n";
        cout << "2- Show all tasks\n";
        //cout << "3- Show next task\n";
        cout << "4- Show current task\n";
        cout << "5- Average waiting time\n";
        cout << "6- Total excecution time\n";
        cout << "7- Tasks throughput\n";
        cout << "8- Advance time\n";
        cout << "9- Save to file (.json or .txt)\n";
        cout << "10- Load from file (.json or .txt)\n";
        cout << "0- Exit\n";

        int choice;
        if (!readInt("Choice: ", choice)) {
            cout << "Invalid choice. Please enter a number.\n";
            continue;
        }
        string name;
        int h,m,p;
        switch (choice)
        {
        case 1:
        readWord("Task Name (one word): ", name);
        if (!readTwoInts("Hours, Minutes: ", h, m)) {
            cout << "Invalid time input. Example: 1 30\n";
            break;
        }
        if (!readInt("Priority: ", p)) {
            cout << "Invalid priority. Example: 5\n";
            break;
        }
        {
            task* newTask = new task();
            newTask->name = name;
            newTask->arrival_time = globalTime;
            newTask->excution_duration = Time(h, m);
            newTask->priority = p;

            mgr->addtask(newTask, p);
            //update tasks
        }
            break;
        case 2:
            mgr->printAllTasks();
            break;
        case 3:
            //mgr->printNextTask();
            break;
         case 4:
            mgr->printCurrentTask();
            break;
        case 8:
            if (!readTwoInts("Advance by (hours minutes): ", h, m)) {
                cout << "Invalid input. Example: 0 15\n";
                break;
            }
            advanceTime(h, m);
            cout << "Time is now: " << globalTime.hours << "h " << globalTime.minutes << "m\n";

            mgr->updateTasks(globalTime);
            break;
        case 9: {
            cout << "Enter save path (e.g. data.json or data.txt): ";
            string path;
            cin >> path;
            string err;
            if (PersistenceManager::saveToFile(path, *mgr, globalTime, &err)) {
                cout << "Saved successfully to " << path << "\n";
            } else {
                cout << "Save failed: " << err << "\n";
            }
            break;
        }
        case 10: {
            cout << "Enter load path (e.g. data.json or data.txt): ";
            string path;
            cin >> path;
            PersistedState st;
            st.globalTime = Time(0, 0);
            string err;
            manager* fresh = PersistenceManager::loadNewFromFile(path, st, &err);
            if (!fresh) {
                cout << "Load failed: " << err << "\n";
                break;
            }
            delete mgr;
            mgr = fresh;
            globalTime = st.globalTime;
            cout << "Loaded successfully from " << path << "\n";
            cout << "Time restored to: " << globalTime.hours << "h " << globalTime.minutes << "m\n";
            break;
        }
        case 0:
            isRunning = false;
            break;
        default:
            cout << "Unknown option.\n";
            break;
        }

    }

    delete mgr;
    return 0;
}
