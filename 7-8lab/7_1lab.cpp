#include "3lab/point/point.h"

int main(){
    const int l = 3;
    Point c[l];
    for(int i = 0;i<4;i++){
        c[i].setX(i+1);
        c[i].setY(i+2);
        c[i].setZ(i+3);

        c[i].print();
    }

    return 0;
}