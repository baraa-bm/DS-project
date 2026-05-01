#ifndef ADS_PROJECT_TIME_H
#define ADS_PROJECT_TIME_H

#include <cstdlib> // std::abs

class Time{
    public:
    int hours;
    int minutes;
    
    Time();
    Time(int h, int m);

    void normalize() {
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        } else if (minutes < 0) {
            // Handle negative minutes for subtraction
            int hourBorrow = (std::abs(minutes) / 60) + 1;
            hours -= hourBorrow;
            minutes += hourBorrow * 60;
        }
    }

    int toTotalMinutes() const {
        return (hours * 60) + minutes;
    }

    Time operator-(const Time& other) const {
        int diff = toTotalMinutes() - other.toTotalMinutes();
        return Time(0, diff); 
    }

    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes);
    }

    bool operator>(const Time& other) const {
        if(hours > other.hours) return true;
        else if(hours < other.hours) return false;
        else if(minutes > other.minutes) return true;
        else return false;
    }

    bool operator==(const Time& other) const {
        if(hours == other.hours && minutes == other.minutes) return true;
        return false;
    }

    bool operator>=(const Time& other){
        if(*this > other || *this == other) return true;
        return false;
    }
};

#endif //ADS_PROJECT_TIME_H