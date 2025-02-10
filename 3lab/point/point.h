#ifndef point_H
#define point_H

class Point {
    public:
        Point();
        ~Point();

        void print();

        double getX();
        void setX(double);

        double getY();
        void setY(double);

        double getZ();
        void setZ(double);
    private:
        double x, y, z;
};

#endif

