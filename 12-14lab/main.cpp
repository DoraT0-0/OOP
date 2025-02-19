#include <iostream>
using namespace std;

int number_pi = 3.1415;

class Point{
    public:
        Point(int ax = 0, int ay = 0, int az = 0) : x(ax), y(ay), z(az) {}
        void print(){
            cout << "x:" << x << " " << "y:" << y << " " << "z:" << z << " " << endl;
        }

        int getX(){return x;}
        void setX(int ax){x = ax;}
        int getY(){return y;}
        void setY(int ay){y = ay;}
        int getZ(){return z;}
        void setZ(int az){z = az;}
    private:
        int x, y, z;
};

class Circle : public Point{
    public:
        Circle(double aradius): radius(aradius) {};
        Circle(int ax, int ay, int az, double aradius) : Point(ax,ay,az), radius(aradius){};
        void print(){
            Point::print();
            cout << "Radius: " << radius << endl;
        };
        double squareCircle(){
            return (radius*radius)*number_pi;
        }

        double getRadius(){return radius;}
        void setRadius(double aradius){radius = aradius;}

    private:
        double radius;
};

class Cone : public Circle{
    public:
        Cone(double aradius, double aheight): Circle(aradius), height(aheight) {};
        Cone(int ax, int ay, int az, double aradius, double aheight): Circle(ax,ay,az,aradius), height(aheight) {};
        void print(){
            Circle::print();
            cout << "Height: " << height << endl;
        }
        double volumeCone(){
            double r = Circle::getRadius();
            return 0.3333*number_pi*r*r*height;
        }

        double getHeight(){return height;}
        void setHeight(double aheight){height = aheight;}
    private:
        double height;
};

int main(){
    Cone cone1 = {23, 2, 1, 5, 5};
    Cone cone2 = {5, 5};

    cone1.print();
    cout << "Volume of Cone: " << cone1.volumeCone() << endl << "Square Circle: " << cone1.squareCircle() << endl;

    cone2.print();
    cout << "Volume of Cone: " << cone2.volumeCone() << endl << "Square Circle: " << cone2.squareCircle() << endl;
    return 0;
}