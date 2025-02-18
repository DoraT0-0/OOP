#ifndef time_H
#define time_H
#include <iostream>
using namespace std;

class Time {
    public:
        Time();
        Time(int, int, int);
        ~Time();
        void normalize();

        bool operator>(const Time &time);
        bool operator>=(const Time &time);

        bool operator<(const Time &time);
        bool operator<=(const Time &time);

        bool operator==(const Time &time);
        bool operator!=(const Time &time);


        int getHours();
        void setHours(int);
        int getMinutes();
        void setMinutes(int);
        int getSeconds();
        void setSeconds(int);
    private:
        int hours, minutes, seconds;
        friend ostream & operator<<(ostream &out, const Time &time);
};

#endif