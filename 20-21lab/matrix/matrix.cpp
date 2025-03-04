#include <iostream>
#include <string>
using namespace std;


template<class T>
class Matrix{
    public:
        Matrix(): rows(0), cols(0){}
        Matrix(int rows, int cols): rows(rows), cols(cols){
            this->matrix = new T*[rows];
            for(int i = 0; i < rows; i++){
                this->matrix[i] = new T[cols];
            }
        }
        ~Matrix(){
            for(int i = 0;i < rows; i++){
                delete [] this->matrix[i];
            }
            delete [] this->matrix;
        }

        Matrix(const Matrix &other)
        {
            matrix = new T*[rows];
            for(int i = 0;i < rows;++i){
                matrix[i] = new T[cols];
                for(int j = 0;j < cols; ++j){
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }

        Matrix &operator=(const Matrix &other)
        {
            if(this != &other){
                for(int i = 0;i < rows; ++i){
                    delete [] matrix[i];
                }
                delete [] matrix;

                rows = other.rows;
                cols = other.cols;
                matrix = new T*[rows];
                for(int i = 0;i < rows;++i){
                    matrix[i] = new T[cols];
                    for(int j = 0 ;j < cols;++j){
                        matrix[i][j] = other.matrix[i][j];
                    }
                }

            }
            return *this;
        }

        T &operator()(int row, int col)
        {
            if(row < 0 && row >= rows && col < 0 && col >= cols){
                cout << "error row > rows / col > cols";
            }
            return this->matrix[row][col];
        }

        Matrix operator+(const Matrix &other){
            Matrix result(rows,cols);
            for(int i = 0;i < rows;++i){
                for(int j = 0;j < cols;++j){
                    result.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
                }
            }
            return result;
        }

        Matrix operator*(int scalar){
            Matrix result(rows,cols);
            for(int i = 0;i < rows;++i){
                for(int j = 0;j < cols;++j){
                    result.matrix[i][j] = this->matrix[i][j] * scalar;
                }
            }
            return result;
        }

        
    int getRows(){return this->rows;}
    int getCols(){return this->cols;}
    T getElement(int row, int col){ return this->matrix[row][col]; }

    private:
        T **matrix;
        int rows,cols;
        template<typename U>
        friend ostream &operator<<(ostream& out, Matrix<U>& matrix);
};

template<typename T>
ostream &operator<<(ostream& out, Matrix<T>& matrix){
    for(int i = 0;i < matrix.getRows();++i){
        for(int j = 0;j < matrix.getCols();++j){
            out << matrix.getElement(i, j) << " ";
        }
        out << endl;
    }
    return out;
}

template<>
Matrix<string> Matrix<string>::operator+(const Matrix<string>& other) {
    Matrix<string> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

template<>
Matrix<string> Matrix<string>::operator*(int scalar) {
    Matrix<string> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            string repeatedString = "";
            for (int k = 0; k < scalar; ++k) {
                repeatedString += this->matrix[i][j];
            }
            result.matrix[i][j] = repeatedString;
        }
    }
    return result;
}

int main(){
    // Matrix<int> m1(2, 3);
    // m1(0, 0) = 1;
    // m1(0, 1) = 2;
    // m1(0, 2) = 3;
    // m1(1, 0) = 4;
    // m1(1, 1) = 5;
    // m1(1, 2) = 6;

    // Matrix<int> m2(2, 3);
    // m2(0, 0) = 1;
    // m2(0, 1) = 2;
    // m2(0, 2) = 3;
    // m2(1, 0) = 4;
    // m2(1, 1) = 5;
    // m2(1, 2) = 6;

    // cout << "Matrix m1:" << endl;
    // cout << m1 << endl;
    // cout << "Matrix m2:" << endl;
    // cout << m2 << endl;

    // Matrix<int> m3 = m1 + m2;
    // cout << "Matrix m3:" << endl;
    // cout << m3 << endl;

    // Matrix<int> m4 = m1 * 2;
    // cout << "Matrix m4:" << endl;
    // cout << m4 << endl;

    Matrix<string> strM1(2, 3);
    strM1(0, 0) = "A";
    strM1(0, 1) = "B";
    strM1(0, 2) = "C";
    strM1(1, 0) = "D";
    strM1(1, 1) = "E";
    strM1(1, 2) = "F";

    Matrix<string> strM2(2, 3);
    strM2(0, 0) = "a";
    strM2(0, 1) = "b";
    strM2(0, 2) = "c";
    strM2(1, 0) = "d";
    strM2(1, 1) = "e";
    strM2(1, 2) = "f";

    cout << "Matrix strM1:" << endl;
    cout << strM1 << endl;
    cout << "Matrix strM2:" << endl;
    cout << strM2 << endl;

    Matrix<string> strM3 = strM1 + strM2;
    cout << "Matrix strM3" << endl;
    cout << strM3 << endl;

    Matrix<string> strM4 = strM1 * 3;
    cout << "Matrix strM4:" << endl;
    cout << strM4 << endl;

    return 0;
}