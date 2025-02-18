#include <iostream>
using namespace std;
#include "matrix.h"


int main(){
    Matrix m1(2, 3);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;

    Matrix m2(2, 3);
    m2(0, 0) = 7;
    m2(0, 1) = 8;
    m2(0, 2) = 9;
    m2(1, 0) = 10;
    m2(1, 1) = 11;
    m2(1, 2) = 12;

    cout << "Matrix m1:" << endl;
    cout << m1 << endl;

    cout << "Matrix m2:" << endl;
    cout << m2 << endl;

    Matrix m3 = m2 - m1;
    cout << "Matrix m3:" << endl;
    cout << m3 << endl;

    Matrix m4 = m1 * 2;
    cout << "Matrix m4:" << endl;
    cout << m4 << endl;


    return 0;
}