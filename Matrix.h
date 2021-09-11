#ifndef MATRIXCALCULATOR_MATRIX_H
#define MATRIXCALCULATOR_MATRIX_H

#include <vector>

class Matrix{
private:
    std::vector<std::vector<double> > matrix;
    unsigned int rows;
    unsigned int cols;
public:
    Matrix(unsigned int _rows, unsigned int _cols);
    explicit Matrix(std::vector<std::vector<double> > v);
    Matrix(const Matrix& rhs);
    virtual ~Matrix();

    // Operator overloading for "standard" mathematical matrix operations
    Matrix& operator=(const Matrix& rhs);

    // Mathematical operations
    Matrix operator+(const Matrix& rhs);
    Matrix operator-(const Matrix& rhs);
    Matrix operator*(const Matrix& rhs);
    Matrix transpose();

    // Scalar operations
    Matrix operator*(const double& rhs);
//    Matrix operator+(const double& rhs);
//    Matrix operator-(const double& rhs);

    // Access the individual elements
    double& operator()(const unsigned& row, const unsigned& col);
    const double& operator()(const unsigned& row, const unsigned& col) const;
};

#endif
