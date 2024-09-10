#include "TimeSpan.h"
#include <iostream>
#include <cmath>
using namespace std;

//Friend stream input/output
ostream& operator<<(ostream &outStream, const TimeSpan &time)
{
    outStream << "Hours: " << time.hours << ", Minutes: " << time.minutes << ", Seconds: " << time.seconds;
    return outStream;
}

istream& operator>>(istream &inStream, TimeSpan &time)
{
    double hours, minutes, seconds;
    inStream >> hours >> minutes >> seconds;
    time.setTime(hours, minutes, seconds);
    return inStream;
}

//Constructors
TimeSpan::TimeSpan()
{

}
        
TimeSpan::TimeSpan(double const &hours, double const &minutes, double const &seconds)
{
    reduce(hours, minutes, seconds);
}

TimeSpan::TimeSpan(double const &minutes, double const &seconds)
{   
    double hours = 0; 
    reduce(hours, minutes, seconds);
}

TimeSpan::TimeSpan(double const &seconds)
{
    double hours = 0;
    double minutes = 0;
    reduce(hours, minutes, seconds);
}

//Getters and setters
int TimeSpan::getHours()const
{
    return this->hours;
}

int TimeSpan::getMinutes()const
{
    return this->minutes;
}
       
int TimeSpan::getSeconds()const
{
    return this->seconds;
}
       
bool TimeSpan::setTime(double const &hours, double const &minutes, double const &seconds)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    reduce(hours, minutes, seconds);
    return true; 
}

//Operators 
TimeSpan TimeSpan::operator+(const TimeSpan &time)const
{
    double h = this->hours + time.getHours();
    double m = this->minutes + time.getMinutes();
    double s = this->seconds + time.getSeconds();
    TimeSpan time3(h, m, s);
    return time3;
}
       
TimeSpan TimeSpan::operator-(const TimeSpan &time)const
{
    double h = this->hours - time.getHours();
    double m = this->minutes - time.getMinutes();
    double s = this->seconds - time.getSeconds();
    TimeSpan time3(h, m, s);
    return time3;
}

TimeSpan TimeSpan::operator-()const
{
    double h = -this->hours;
    double m = -this->minutes;
    double s = -this->seconds;
    TimeSpan time3(h, m, s);
    return time3;
}
       
TimeSpan& TimeSpan::operator+=(const TimeSpan &time)
{
    this->hours += time.getHours();
    this->minutes += time.getMinutes();
    this->seconds += time.getSeconds();
    return *this;
}
       
TimeSpan& TimeSpan::operator-=(const TimeSpan &time)
{
    this->hours -= time.getHours();
    this->minutes -= time.getMinutes(); 
    this->seconds -= time.getSeconds();
    return *this;
}

bool TimeSpan::operator==(const TimeSpan &time)const
{
    if(time.getHours() == this->hours && time.getMinutes() == this->minutes && time.getSeconds() == this->seconds)
    {
        return true;
    }
    return false;
}

bool TimeSpan::operator!=(const TimeSpan &time)const
{
    if(*this == time)
    {
        return false;
    }
    return true;
}

/*Helper method:
Sets total seconds equal to hours * sqrt 60 + minutes * 60 + seconds, rounds answer and casts to int.
Sets hours equal to total seconds divided by sqrt 60.
Sets remainder of seconds equal to remainder of total seconds divided by sqrt 60.
Sets minutes equal to remainder of seconds divided by 60.
Sets seconds equal to remainder of the remainder of seconds divided by 60.*/
void TimeSpan::reduce(double const &hours, double const &minutes, double const &seconds)
{
    int tSeconds = static_cast<int>(round(hours * 3600 + minutes * 60 + seconds));
    this->hours = tSeconds /3600;
    int rSeconds = tSeconds %3600;
    this->minutes = rSeconds /60;
    this->seconds = rSeconds %60;
}
