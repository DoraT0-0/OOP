#include "point.h"
#include <iostream>
using namespace std;

Point::Point() : x(0), y(0), z(0) {}


Point::~Point()
{
    cout << "Destructor called";
}

void Point::print()
{
    cout << "x:" << x << " y:" << y << " z:" << z << endl;
}

double Point::getX(){return x;}
void Point::setX(double ax){x = ax;}

double Point::getY(){return y;}
void Point::setY(double ay){y = ay;}

double Point::getZ(){return z;}
void Point::setZ(double az){z = az;}


