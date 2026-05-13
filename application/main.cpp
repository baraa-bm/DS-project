#include <iostream>
#include <fstream>
#include "manager.h"
#include "persistence.h"
#include "user.h"
#include <string>
#include <limits>
#include<QFile>
#include<QApplication>
#include"mainwindow.h"
#include "login_window/logindialog.h"


using namespace std;

Time *globalTime = new Time (5,0);
void advanceTime(int h, int m){
    globalTime->hours += h;
    globalTime->minutes += m;
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
                return false; // User already exists
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    manager *mgr = new manager();

    // 1. Point to your resource file (the colon ':' is vital!)
    QFile styleFile(":/style.qss");

    // 2. Try to open it
    if(styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        a.setStyleSheet(styleSheet);
    } else {
        // If you see this in the output, your resource path is wrong
        qDebug() << "Style sheet not found!";
    }

    MainWindow w;
    w.Task_Manager = mgr;
    w.currentTime = globalTime;
    LoginDialog L;
    //L.show();
    w.show();
    return a.exec();
}