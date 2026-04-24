#include "task.h"

int task::_ID = 1000;

task::task() : _status(pending){
    ID = _ID;
    _ID++;
}