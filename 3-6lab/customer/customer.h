#ifndef customer_H
#define customer_H
#include <string>

class Customer {
    public:
        Customer();
    private:
        string surname;
        string name;
        string middle_name;
        string address;
        string phone_number;
        string number_of_the_nerdy_card;
        string bank_account_number;
}


#endif