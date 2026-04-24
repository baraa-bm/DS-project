#ifndef ADS_PROJECT_TASK_H
#define ADS_PROJECT_TASK_H

#include "Time.h"
#include <string>

enum status{pending, current ,completed};

class task {
public:
    static int _ID;
    int ID;
    std::string name;
    int priority;
    Time excution_duration;
    Time arrival_time;
    status _status;

    task();
};


#endif //ADS_PROJECT_TASK_H