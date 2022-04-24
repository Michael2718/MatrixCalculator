#include <iostream>
#include <cmath>
#include "Matrix.h"

// Parameter constructor
Matrix::Matrix(unsigned int _rows, unsigned int _cols) {
    matrix.resize(_rows);
    for (auto & i : matrix) {
        i.resize(_cols);
    }
    rows = _rows;
    cols = _cols;
}

// Vector constructor
Matrix::Matrix(std::vector<std::vector<double>> v) {
    matrix.resize(v.size());
    for (auto & i : matrix) {
        i.resize(v[0].size());
    }

    rows = matrix.size();
    cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = v[i][j];
        }
    }
}

// Copy Constructor
Matrix::Matrix(const Matrix& rhs) {
    matrix = rhs.matrix;
    rows = rhs.rows;
    cols = rhs.cols;
}

// (Virtual) Destructor
Matrix::~Matrix() = default;

// Assignment Operator
Matrix &Matrix::operator=(const Matrix &rhs) {
    if (&rhs == this) {
        return *this;
    }

    unsigned int new_rows = rhs.rows;
    unsigned int new_cols = rhs.cols;

    matrix.resize(new_rows);
    for (auto & i : matrix) {
        i.resize(new_cols);
    }

    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            matrix[i][j] = rhs(i, j);
        }
    }

    rows = new_rows;
    cols = new_cols;

    return  *this;
}

// Addition of two matrices
Matrix Matrix::operator+(const Matrix &rhs) {
    Matrix result (rows, cols);

    for (int i = 0;  i < rows; i++){
        for (int j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] + rhs(i, j);
        }
    }

    return result;
}

// Subtraction of two matrices
Matrix Matrix::operator-(const Matrix &rhs) {
    Matrix result (rows, cols);

    for (int i = 0;  i < rows; i++){
        for (int j = 0; j < cols; j++) {
            result(i, j) = this->matrix[i][j] - rhs(i, j);
        }
    }

    return result;
}

// Multiplication of two matrices
Matrix Matrix::operator*(const Matrix &rhs) {
    if (cols != rhs.rows) {
        std::cerr << "Impossible to calculate multiplication, columns of first matrix != rows of second\n";
    }
    Matrix result (rows, rhs.cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result(i, j) += this->matrix[i][k] * rhs(k, j);
            }
        }
    }

    return result;
}

// Transpose of matrix
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
