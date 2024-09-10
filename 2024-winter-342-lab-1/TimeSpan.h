#ifndef TIME_SPAN_H
#define TIME_SPAN_H
#include <iostream>
using namespace std;

class TimeSpan
{
    //Friend stream input/ouput
    friend ostream& operator<<(ostream &outStream, const TimeSpan &time);
    friend istream& operator>>(istream &inStream, TimeSpan &time);

    public:
        //Constructors
        TimeSpan();
        TimeSpan(double const &hours, double const &minutes, double const &seconds);
        TimeSpan(double const &minutes, double const &seconds);
        TimeSpan(double const &seconds);
        //Getters and setters
        int getHours()const;
        int getMinutes()const;
        int getSeconds()const;
        bool setTime(double const &hours, double const &minutes, double const &seconds);
        //Operators 
        TimeSpan operator+(const TimeSpan &time)const;
        TimeSpan operator-(const TimeSpan &time)const;
        TimeSpan operator-()const;
        TimeSpan& operator+=(const TimeSpan &time);
        TimeSpan& operator-=(const TimeSpan &time);
        bool operator==(const TimeSpan &time)const;
        bool operator!=(const TimeSpan &time)const;

    private:
        int hours;
        int minutes;
        int seconds;
        void reduce(double const &hours, double const &minutes, double const &seconds);
};
#endif