#include <iostream>
#include "time.h"
using namespace std;

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::~Time()
{
    cout << "ram clear :" << this << endl;
}



int Time::getHours(){return hours;}
void Time::setHours(int ah){hours = ah;}
int Time::getMinutes(){return minutes;}
void Time::setMinutes(int am){minutes = am;}
int Time::getSeconds(){return seconds;}
void Time::setSeconds(int as){seconds = as;}

void Time::normalize(){
    if(seconds >= 60){
            minutes += seconds/60;
            seconds %= 60;
        }
        if(minutes >= 60){
            hours += minutes/60;
            minutes %= 60;
        }
        hours = (hours + 24) % 24;
}

bool Time::operator>(const Time &time)
{
    if (this->hours > time.hours) {
        return true;
    } else if (this->hours == time.hours && this->minutes > time.minutes) {
        return true;
    } else if (this->hours == time.hours && this->minutes == time.minutes && this->seconds > time.seconds) {
        return true;
    }
    return false;
}

bool Time::operator>=(const Time &time)
{
    if (this->hours >= time.hours) {
        return true;
    } else if (this->hours == time.hours && this->minutes >= time.minutes) {
        return true;
    } else if (this->hours == time.hours && this->minutes == time.minutes && this->seconds >= time.seconds) {
        return true;
    }
    return false;
}

bool Time::operator<(const Time &time)
{
    if (this->hours < time.hours) {
        return true;
    } else if (this->hours == time.hours && this->minutes < time.minutes) {
        return true;
    } else if (this->hours == time.hours && this->minutes == time.minutes && this->seconds < time.seconds) {
        return true;
    }
    return false;
}

bool Time::operator<=(const Time &time)
{
    if (this->hours <= time.hours) {
        return true;
    } else if (this->hours == time.hours && this->minutes <= time.minutes) {
        return true;
    } else if (this->hours == time.hours && this->minutes == time.minutes && this->seconds <= time.seconds) {
        return true;
    }
    return false;
}

bool Time::operator==(const Time &time)
{
    return this->hours == time.hours && this->minutes == time.minutes && this->seconds == time.seconds;
}

bool Time::operator!=(const Time &time)
{
    return !(this->hours == time.hours && this->minutes == time.minutes && this->seconds == time.seconds);
}

ostream & operator <<(ostream & out, const Time& time){
    out << time.hours << ":" << time.minutes << ":" << time.seconds << endl;
    return out;
}
