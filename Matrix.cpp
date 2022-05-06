#include "Matrix.h"
#include <iostream>
#include <cmath>

using std::invalid_argument;

Matrix::Matrix() : rows(0), cols(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols)
    : matrix(vector<vector<double>>(rows, vector<double>(cols))), rows(rows), cols(cols) {
    if (rows < 0 || cols < 0) throw invalid_argument("Invalid matrix size.");
}

Matrix::Matrix(vector<vector<double>> v) : matrix(v), rows(v.size()), cols(v[0].size()){
    if (rows < 0 || cols < 0) throw invalid_argument("Invalid matrix size.");
}

Matrix Matrix::operator+(const Matrix &rhs) {
    if(rows != rhs.rows || cols != rhs.cols) throw invalid_argument("Invalid matrix size.");

    Matrix result (rows, cols);

    for (int i = 0;  i < rows; i++){
        for (int j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] + rhs(i, j);
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix &rhs) {
    if(rows != rhs.rows || cols != rhs.cols) throw invalid_argument("Invalid matrix size.");

    Matrix result (rows, cols);

    for (int i = 0;  i < rows; i++){
        for (int j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] - rhs(i, j);
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) {
    if (cols != rhs.rows) throw invalid_argument("Invalid matrix size.");

    Matrix result (rows, rhs.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rhs.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result(i, j) += this->matrix[i][k] * rhs(k, j);
            }
        }
    }

    return result;
}

Matrix Matrix::transpose() {
    Matrix result (cols, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(j, i) = this->matrix[i][j];
        }
    }

    return result;
}

// Determinant
double Matrix::determinant() {
    double det = 1, coefficient = 0;

    if (matrix.size() == 1) {
        return matrix[0][0];
    } else if (matrix.size() == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    } else {
        for(int i = 0; i < matrix.size()-1; i++)
        {
            for(int j = i+1; j < matrix.size(); j++)
            {
                coefficient = -matrix[j][i] / matrix[i][i];
                for(int k = 0; k < matrix.size(); k++)
                {
                    matrix[j][k] = matrix[j][k] + coefficient * matrix[i][k];
                }
            }
        }
    }

    for (int i = 0; i < matrix.size(); ++i) {
        det *= matrix[i][i];
    }

    return (int)det;
}

// Scalar multiplication
Matrix Matrix::operator*(const double &rhs) {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = this->matrix[i][j] * rhs;
        }
    }

    return result;
}

// Access the individual elements
double &Matrix::operator()(const unsigned int &row, const unsigned int &col) {
    return this->matrix[row][col];
}

// Access the individual elements (const)
const double &Matrix::operator()(const unsigned int &row, const unsigned int &col) const {
    return this->matrix[row][col];
}

// Print
void Matrix::print() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Invertible Matrix
Matrix Matrix::inverse() {
    Matrix adjugateMatrix(rows, cols);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            adjugateMatrix(i, j) = pow(-1, i+j)*this->minor(i, j);
        }
    }
    return adjugateMatrix.transpose();
}

// Extra minor
double Matrix::minor(int a, int b) {
    matrix.erase(matrix.begin()+a);
    for (std::vector<double> &i: matrix) {
        i.erase(i.begin() + b);
    }
    return this->determinant();
}
