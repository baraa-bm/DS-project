#include "task.h"

task::task() : id(-1), excution_duration(0), priority(0),
                arrival_time(0), waiting_time(0){}

task::task(int ID, int duration, int prior, int arrive): id(ID), excution_duration(duration), priority(prior),
				 arrival_time(arrive), waiting_time(0) {}
