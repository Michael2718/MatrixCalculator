#include <iostream>
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
    if (cols != rhs.rows && cols) {
        std::cerr << "Impossible to calculate multiplication, columns of first matrix != rows of second\n";
    }

    Matrix result (rows, cols);

    for (int i = 0; i < rhs.rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            for (int k = 0; k < rhs.rows; ++k) {
                result(i, j) += this->matrix[i][k] * rhs(k, j);
            }
        }
    }

    return result;
}

// Transpose of matrix
Matrix Matrix::transpose() {
    Matrix result (rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = this->matrix[j][i];
        }
    }

    return result;
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
