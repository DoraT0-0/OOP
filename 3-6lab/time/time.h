#ifndef time_H
#define time_H

class Time {
    public:
        Time();
        Time(int, int, int);
        ~Time();
        void normalize();
        void print();

        int getHours();
        void setHours(int);

        int getMinutes();
        void setMinutes(int);

        int getSeconds();
        void setSeconds(int);
    private:
        int hours, minutes, seconds;
};

#endif