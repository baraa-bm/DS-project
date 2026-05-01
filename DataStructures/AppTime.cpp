#include "AppTime.h"

Time::Time(){}

Time::Time(int h, int m){
    hours = h;
    minutes = m;
    normalize();
}