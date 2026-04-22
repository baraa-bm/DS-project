#ifndef ADS_PROJECT_TASK_H
#define ADS_PROJECT_TASK_H

#include "Time.h"

class task {
private:
    int id;
public:
    int priority;
    Time excution_duration;
    Time arrival_time;
    Time waiting_time;

    task();
    task(int,int,int,int);
    int getid() const {
        return id;
    }
};


#endif //ADS_PROJECT_TASK_H