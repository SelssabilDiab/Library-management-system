#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

class date
{
private:
    int day;
    int month;
    int year;

public:
    date(int d, int m, int y)
    {
        if (d < 32 && d > 0 && m > 0 && m < 13 && y > 2024)
        {
            day = d;
            month = m;
            year = y;
        }
    }

    date() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_time);

        day = local_time->tm_mday;
        month = local_time->tm_mon + 1;      // months are 0-based
        year = local_time->tm_year + 1900;   // years since 1900
    }

    void printDate() const
    {
        cout << day << " / " << month << " / " << year;
    }

    //to store the date in a file
    void printDate(ostream& os) const {
        os << day << " / " << month << " / " << year;
    }

    bool operator < (const date& d2) const
    {
        if (year < d2.getyear())
            return true;
        else if (year == d2.getyear() && month < d2.getmonth())
            return true;
        else if (month == d2.getmonth() && day < d2.getday())
            return true;
        else
            return false;
    }

    int getday() const { return day; }
    int getmonth() const { return month; }
    int getyear() const { return year; }
};

#endif
