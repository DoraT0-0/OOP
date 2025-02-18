#include <iostream>
#include "time.h"
using namespace std;

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

Time::~Time()
{
    cout << "ram clear";
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

void Time::print(){
    cout << hours << ":" << minutes << ":" << seconds << endl;
}