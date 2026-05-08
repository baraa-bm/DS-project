#ifndef ADS_PROJECT_TASK_H
#define ADS_PROJECT_TASK_H

#include "AppTime.h"
#include <string>

enum status{pending, current ,completed, hold};

class task {
public:
    static int _ID;
    int ID;
    std::string name;
    int priority;
    Time excution_duration;
    Time arrival_time;
    Time start_time;
    status _status;

    task();
};


#endif //ADS_PROJECT_TASK_H