#ifndef MATRIXCALCULATOR_MATRIX_H
#define MATRIXCALCULATOR_MATRIX_H

#include <vector>

using std::vector;

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

    Matrix transpose();
    Matrix inverse();

    double determinant();
    double minor(int a, int b);

    double& operator()(const unsigned& row, const unsigned& col);
    const double& operator()(const unsigned& row, const unsigned& col) const;

    void print();
};

#endif
