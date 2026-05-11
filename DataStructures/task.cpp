#include "task.h"

int task::_ID = 1000;

task::task() : _status(pending){
    ID = _ID++;
}

task::task(Time arrival_time, Time execution_duration, std::string name, int priority) : _status(pending){
    ID = _ID++;
    this->arrival_time = arrival_time;
    this->excution_duration = execution_duration;
    this->name = name;
    this->priority = priority;
}