#include <string>
#include <iostream>
#include "./time/time.h"
#include "./point/point.h"
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



int main(){
    Point _point;
    _point.setX(12.3);
    _point.print();
    // Time _time = {60, 234, 61};
    // cout << _time.getHours() << endl;
    // _time.setHours(23);
    // cout << _time.getHours() << endl;
    // _time.print();
    return 0;
}