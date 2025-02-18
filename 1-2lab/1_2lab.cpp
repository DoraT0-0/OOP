#include <string>
#include <iostream>
using namespace std;

class Worker {
    public:
        string fio;
        string post;
        int year_of_admission_to_work;
        int salary;
};

class Customer {
    public:
        string surname;
        string name;
        string middle_name;
        string address;
        string phone_number;
        string number_of_the_nerdy_card;
        string bank_account_number;
};

class Point {
    public:
        double x, y, z;
};

class Time {
    public:
        int hours, minutes, seconds;

        void normalize(){
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

        void print(){
            cout << hours << ":" << minutes << ":" << seconds << endl;
        }
};

int main(){
    Time _time = {123, 234, 61};
    _time.print();
    _time.normalize();
    _time.print();
    return 0;
}