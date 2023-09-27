#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include "Time.cpp"
using namespace std;

class DateTime {
private:
    int year;
    int month;
    int date;
    Time time;
public:
    DateTime() :time(0, 0, 0) {
        this->year = 1900;
        this->month = 1;
        this->date = 1;
    }
    DateTime(int date, int month, int year) :time(0, 0, 0) {
        this->year = year;
        this->month = month;
        this->date = date;
        this->fix();
    }
    DateTime(int date, int month, int year, Time time) {
        this->year = year;
        this->month = month;
        this->date = date;
        this->time = time;
        this->fix();
    }
    DateTime(int date, int month, int year, int hour, int min, int second) :time(hour, min, second) {
        this->year = year;
        this->month = month;
        this->date = date;
        this->fix();
    }
    void fix() {
        bool LeapYear = 0; int mm[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (this->year % 4 == 0)
        {
            if (this->year % 100 == 0)
            {
                if (this->year % 400 == 0)
                    LeapYear = 1;
                else
                    LeapYear = 0;
            }
            else
                LeapYear = 1;
        }
        else
            LeapYear = 0;
        if (LeapYear) {
            mm[1] = 29;
        }

        while (this->month > 12) {
            this->year++;
            this->month -= 12;
        }
        while (this->date > mm[this->month - 1]) {
            this->date -= mm[this->month - 1];
            this->month++;
            if (this->month > 12) {
                this->year++;
                this->month -= 12;
            }
        }
        while (this->date < 1) {
            this->date += mm[this->month - 2];
            this->month--;
            if (this->month < 1) {
                this->year--;
                this->month += 12;
            }
        }
    }
    int getDate() {
        return this->date;
    }
    int getMonth() {
        return this->month;
    }
    int getYear() {
        return this->year;
    }
    int getSecond() {
        return this->time.getSecond();
    }
    int getMinute() {
        return this->time.getMinute();
    }
    int getHour() {
        return this->time.getHour();
    }
    void setDate(int date) {
        this->date = date;
    }
    void setMonth(int month) {
        this->month = month;
    }
    void setYear(int year) {
        this->year = year;
    }
    void setSecond(int second) {
        this->time.setSecond(second);
    }
    void setMinute(int minute) {
        this->time.setMinute(minute);
    }
    void setHour(int hour) {
        this->time.setHour(hour);
    }
    void add(int amount, string unit) {
        if (unit == "year") {
            this->year += amount;
        }
        else if (unit == "month") {
            this->month += amount;
        }
        else if (unit == "date") {
            this->date += amount;
        }
        else {
            this->time.add(amount, unit);
        }
        this->fix();
    }

    int dateOfMonth() {
        int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return m[this->month - 1];
    }
    int dateOfYear() {
        int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int d = 0;
        for (int i = 0; i < this->month - 1; i++) {
            d += m[i];
        }
        d += this->date;
        return d;
    }
    string dateOfWeek() {
        int d = this->date, m = this->month, y = this->year;
        if (m == 1 || m == 2) {
            m += 12;
            y--;
        }
        int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
        switch (iWeek)
        {
        case 0: return "Monday";
        case 1: return "Tuesday";
        case 2: return "Wednesday";
        case 3: return "Thursday";
        case 4: return "Firday";
        case 5: return "Saturday";
        case 6: return "Sunday";
        }
    }
    int weekOfYear() {
        int mm[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int d = this->date, m = this->month, y = this->year, day = 0;
        day += this->date;
        for (int i = 0; i < this->month - 1; i++) {
            day += mm[i];
        }
        return (day / 7) + 1;
    }
    int quaterOfYear() {
        DateTime temp(31, 12, this->year);
        float a = temp.weekOfYear(), b = this->weekOfYear();
        float c = b / a;
        if (c < 0.25) {
            return 1;
        }
        else if (c > 0.25 && c < 0.5) {
            return 2;
        }
        else if (c > 0.5 && c < 0.75) {
            return 3;
        }
        else
            return 4;
    }
    bool operator<(const DateTime& t) {
        if (this->year < t.year) {
            return true;
        }
        else if (this->year > t.year) {
            return false;
        }
        else if (this->month < t.month) {
            return true;
        }
        else if (this->month > t.month) {
            return false;
        }
        else if (this->date < t.date) {
            return true;
        }
        else if (this->date > t.date) {
            return false;
        }
        return false;
    }

    bool operator>(const DateTime& t) {
        if (this->year > t.year) {
            return true;
        }
        else if (this->year < t.year) {
            return false;
        }
        else if (this->month > t.month) {
            return true;
        }
        else if (this->month < t.month) {
            return false;
        }
        else if (this->date > t.date) {
            return true;
        }
        else if (this->date < t.date) {
            return false;
        }
        return false;
    }

    bool operator!=(const DateTime& t) {
        if (this->year != t.year) {
            return true;
        }
        else if (this->month != t.month) {
            return true;
        }
        else if (this->date != t.date) {
            return true;
        }
        return false;
    }
    bool operator==(const DateTime& t) {
        if (this->year != t.year) {
            return false;
        }
        else if (this->month != t.month) {
            return false;
        }
        else if (this->date != t.date) {
            return false;
        }
        return true;
    }


    DateTime operator++(int) {
        DateTime T(this->date, this->month, this->year);
        ++this->date;
        this->fix();
        return T;
    }
    DateTime operator++ () {
        ++this->date; // increment this object
        this->fix();
        return DateTime(this->date, this->month, this->year);
    }
    DateTime operator--(int) {
        DateTime T(this->date, this->month, this->year);
        --this->date;
        this->fix();
        return T;
    }
    DateTime operator-- () {
        --this->date;
        this->fix();
        return DateTime(this->date, this->month, this->year);
    }
    float duration(const DateTime& t) {
        int mm[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, tt;
        Time a = this->time, b = t.time;
        float total = 0;
        tt = a.duration(b);
        if (*this > t) {
            if (this->time > t.time) {
                total = float(tt) / 86400;
            }
            else {
                total = -float(tt) / 86400;
            }
            float d = this->date - t.date;
            float m = this->month - t.month;
            float y = this->year - t.year;
            total += d;
        }
        else if (*this < t) {
            if (this->time > t.time) {
                total = -float(tt) / 86400;
            }
            else {
                total = float(tt) / 86400;
            }
            float d = t.date - this->date;
            float m = t.month - this->month;
            float y = t.year - this->year;
            total += d;
        }
        return total;
    }

    float operator-(const DateTime& t) {
        int mm[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, tt;
        Time a = this->time, b = t.time;
        float total = 0;
        tt = a.duration(b);
        if (this->time > t.time) {
            total = float(tt) / 86400;
        }
        else {
            total = -float(tt) / 86400;
        }
        float d = this->date - t.date;
        float m = this->month - t.month;
        float y = this->year - t.year;
        total += d;
        return total;
    }
    void display() {
        cout << this->year << "\t" << this->month << "\t" << this->date << endl;
    }
};
#endif
