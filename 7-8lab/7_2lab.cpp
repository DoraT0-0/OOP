#include "3lab/time/time.h"

int main(){
    Time *j = new Time(12, 32, 43);
    j->print();
    delete j;

    return 0;
}