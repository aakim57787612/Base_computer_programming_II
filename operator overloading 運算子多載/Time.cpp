#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time {
private:
    int second;
    int minute;
    int hour;
public:
    Time() {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
    Time(int hour, int minute, int second) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
        while (this->second >= 60) {
            this->minute++;
            this->second -= 60;
        }
        while (this->minute >= 60) {
            this->hour++;
            this->minute -= 60;
        }
        while (this->hour >= 24) {
            this->hour -= 24;
        }
    }
    void fix() {
        while (this->second >= 60) {
            this->minute++;
            this->second -= 60;
        }
        while (this->minute >= 60) {
            this->hour++;
            this->minute -= 60;
        }
        while (this->hour >= 24) {
            this->hour -= 24;
        }
        while (this->second < 0) {
            --this->minute;
            this->second += 60;
        }
        while (this->minute < 0) {
            --this->hour;
            this->minute += 60;
        }
        while (this->hour < 0) {
            this->hour += 24;
        }
    }
    int getSecond() {
        return  this->second;
    }
    int getMinute() {
        return this->minute;
    }
    int getHour() {
        return this->hour;
    }
    void setSecond(int second) {
        this->second = second;
    }
    void setMinute(int minute) {
        this->minute = minute;
    }
    void setHour(int hour) {
        this->hour = hour;
    }
    void add(int amount, string unit) {
        if (unit == "second") {
            this->second += amount;
        }
        else if (unit == "minute") {
            this->minute += amount;
        }
        else if (unit == "hour") {
            this->hour += amount;
        }
        this->fix();
    }

    int duration(const Time& t) {
        int s = 0;
        if (*this > t) {
            s += 60 * 60 * (this->hour - t.hour);
            s += 60 * (this->minute - t.minute);
            s += (this->second - t.second);
        }
        else if (*this < t) {
            s += 60 * 60 * (t.hour - this->hour);
            s += 60 * (t.minute - this->minute);
            s += (t.second - this->second);
        }
        return s;

    }

    bool operator<(const Time& t) {
        if (this->hour < t.hour) {
            return true;
        }
        else if (this->hour > t.hour) {
            return false;
        }
        else if (this->minute < t.minute) {
            return true;
        }
        else if (this->minute > t.minute) {
            return false;
        }
        else if (this->second < t.second) {
            return true;
        }
        else if (this->second > t.second) {
            return false;
        }
        return false;
    }

    bool operator>(const Time& t) {
        if (this->hour > t.hour) {
            return true;
        }
        else if (this->hour < t.hour) {
            return false;
        }
        else if (this->minute > t.minute) {
            return true;
        }
        else if (this->minute < t.minute) {
            return false;
        }
        else if (this->second > t.second) {
            return true;
        }
        else if (this->second < t.second) {
            return false;
        }
        return false;
    }
    bool operator<=(const Time& t) {
        if (this->hour < t.hour) {
            return true;
        }
        else if (this->hour > t.hour) {
            return false;
        }
        else if (this->minute < t.minute) {
            return true;
        }
        else if (this->minute > t.minute) {
            return false;
        }
        else if (this->second < t.second) {
            return true;
        }
        else if (this->second > t.second) {
            return false;
        }
        return true;
    }
    bool operator>=(const Time& t) {
        if (this->hour > t.hour) {
            return true;
        }
        else if (this->hour < t.hour) {
            return false;
        }
        else if (this->minute > t.minute) {
            return true;
        }
        else if (this->minute < t.minute) {
            return false;
        }
        else if (this->second > t.second) {
            return true;
        }
        else if (this->second < t.second) {
            return false;
        }
        return true;
    }
    bool operator!=(const Time& t) {
        if (this->hour != t.hour) {
            return true;
        }
        else if (this->minute != t.minute) {
            return true;
        }
        else if (this->second != t.second) {
            return true;
        }
        return false;
    }
    bool operator==(const Time& t) {
        if (this->hour != t.hour) {
            return false;
        }
        else if (this->minute != t.minute) {
            return false;
        }
        else if (this->second != t.second) {
            return false;
        }
        return true;
    }
    Time operator++(int) {
        Time T(this->hour, this->minute, this->second);
        ++this->second;
        this->fix();
        return T;
    }
    Time operator++ () {
        ++this->second; // increment this object
        this->fix();
        return Time(this->hour, this->minute, this->second);
    }
    Time operator--(int) {
        Time T(this->hour, this->minute, this->second);
        --this->second;
        this->fix();
        return T;
    }
    Time operator-- () {
        --this->second;
        this->fix();
        return Time(this->hour, this->minute, this->second);
    }
    Time operator+=(int s) {
        this->second += s;
        this->fix();
        return Time(this->hour, this->minute, this->second);
    }
    Time operator-=(int s) {
        this->second -= s;
        this->fix();
        return Time(this->hour, this->minute, this->second);
    }
    Time operator+(Time t) {
        this->second += t.second;
        this->minute += t.minute;
        this->hour += t.hour;
        this->fix();
        return Time(this->hour, this->minute, this->second);
    }/*
    Time operator-(Time t) {
        this->second -= t.second;
        this->minute -= t.minute;
        this->hour -= t.hour;
        while (this->second < 0) {
            --this->minute;
            this->second += 60;
        }
        while (this->minute < 0) {
            --this->hour;
            this->minute += 60;
        }
        while (this->hour < 0) {
            this->hour += 24;
        }
        return Time(this->hour, this->minute, this->second);
    }*/
    int operator-(const Time& t) {
        int s = 0;
        s += 60 * 60 * (this->hour - t.hour);
        s += 60 * (this->minute - t.minute);
        s += (this->second - t.second);
        return s;
    }
};
#endif