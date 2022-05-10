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

Matrix& Matrix::operator=(const Matrix& rhs) {
    if (this == &rhs) return *this;

    this->matrix = rhs.matrix;
    this->rows = rhs.rows;
    this->cols = rhs.cols;
    return *this;
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

Matrix Matrix::operator*(const double &rhs) {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = this->matrix[i][j] * rhs;
        }
    }

    return result;
}

ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix(i, j);
            if (j < matrix.cols-1) os << " ";
        }
        if (i < matrix.rows-1) os << "\n";
    }
    return os;
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

double Matrix::determinant() {
    double det = 1, coefficient;

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

double Matrix::minor(int a, int b) {
    matrix.erase(matrix.begin()+a);
    for (vector<double> &i: matrix) {
        i.erase(i.begin() + b);
    }
    return this->determinant();
}
