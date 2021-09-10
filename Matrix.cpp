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

// Access the individual elements
double &Matrix::operator()(const unsigned int &row, const unsigned int &col) {
    return this->matrix[row][col];
}

// Access the individual elements (const)
const double &Matrix::operator()(const unsigned int &row, const unsigned int &col) const {
    return this->matrix[row][col];
}
