#ifndef matrix_H
#define matrix_H
#include <iostream>
using namespace std;


class Matrix{
    public:
        Matrix();
        Matrix(int rows, int cols);
        Matrix(const Matrix &other);
        ~Matrix();
        Matrix& operator=(const Matrix &other);
        Matrix operator-(const Matrix &other);
        Matrix operator*(int scalar);
        int& operator()(int row, int col);
    private:
        int rows, cols;
        int **matrix;
        friend ostream &operator<<(ostream& out, Matrix& matrix);
};


#endif