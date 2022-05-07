#ifndef MATRIXCALCULATOR_MATRIX_H
#define MATRIXCALCULATOR_MATRIX_H

#include <vector>
#include <iostream>

using std::vector, std::ostream;

class Matrix{
private:
    vector<vector<double> > matrix;
    unsigned int rows;
    unsigned int cols;
public:
    Matrix();
    Matrix(unsigned int rows, unsigned int cols);
    explicit Matrix(vector<vector<double> > v);
    Matrix(const Matrix& rhs) = default;

    unsigned int getRows() const {return rows;}
    unsigned int getCols() const {return cols;}

    Matrix& operator=(const Matrix& rhs) {return *this;}
    Matrix operator+(const Matrix& rhs);
    Matrix operator-(const Matrix& rhs);
    Matrix operator*(const Matrix& rhs);

    Matrix operator*(const double& rhs);

    friend ostream& operator<<(ostream& os, const Matrix& matrix);

    double& operator()(const unsigned& row, const unsigned& col) {return this->matrix[row][col];}
    const double& operator()(const unsigned& row, const unsigned& col) const {return this->matrix[row][col];}

    Matrix transpose();
    Matrix inverse();

    double determinant();
    double minor(int a, int b);


};

#endif
