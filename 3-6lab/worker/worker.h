#ifndef worker_H
#define worker_H
#include <string>

class Worker {
    public:
        Worker();
        Worker(string, string, int, int);
    private:
        string fio;
        string post;
        int year_of_admission_to_work;
        int salary;
}


#endif