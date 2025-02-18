#include <iostream>
#include "time/time.h"
using namespace std;

int main(){

    Time t1(23, 3, 44);
    Time t2(23, 3, 44);
    
    bool tb1 = t1 >= t2;
    bool tb2 = t1 == t2;
    bool tb3 = t1 != t2;

    cout << tb1 << " " << tb2 << " " << tb3 << endl;

    cout << t1;

    return 0;
}