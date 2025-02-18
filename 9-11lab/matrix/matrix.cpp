#include "matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix() : rows(0), cols(0){}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    matrix = new int*[rows];
    for(int i = 0;i < rows; ++i){
        matrix[i] = new int[cols];
    }
}

Matrix::Matrix(const Matrix &other)
{
    matrix = new int*[rows];
    for(int i = 0;i < rows;++i){
        matrix[i] = new int[cols];
        for(int j = 0;j < cols; ++j){
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for(int i = 0;i < rows; ++i){
        delete [] matrix[i];
    }
    delete [] matrix;
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if(this != &other){
        for(int i = 0;i < rows; ++i){
            delete [] matrix[i];
        }
        delete [] matrix;

        rows = other.rows;
        cols = other.cols;
        matrix = new int*[rows];
        for(int i = 0;i < rows;++i){
            matrix[i] = new int[cols];
            for(int j = 0 ;j < cols;++j){
                matrix[i][j] = other.matrix[i][j];
            }
        }

    }
    return *this;
}

int &Matrix::operator()(int row, int col)
{
    if(row < 0 && row >= rows && col < 0 && col >= cols){
        cout << "error row > rows / col > cols";
    }
    return matrix[row][col];
}

Matrix Matrix::operator-(const Matrix &other)
{

    Matrix _matrix(rows, cols);
    for(int i = 0;i < rows;++i){
        for(int j = 0;j < cols;++j){
            _matrix.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return _matrix;
}

Matrix Matrix::operator*(int scalar)
{
    Matrix _matrix(rows, cols);
    for(int i = 0;i < rows;++i){
        for(int j = 0;j < cols;++j){
            _matrix.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return _matrix;

}


ostream &operator<<(ostream& out, Matrix& matrix){
    for(int i = 0;i < matrix.rows;++i){
        for(int j = 0;j < matrix.cols;++j){
            out << matrix.matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}