#include "worker.h"

Worker::Worker()
{
}

Worker::Worker(string afio, string apost, int ayear_of_admission_to_work, int asalary)
{
    fio = afio;
    post = apost;
    year_of_admission_to_work = ayear_of_admission_to_work;
    salary = asalary;
}
