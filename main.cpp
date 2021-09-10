#include <iostream>
#include "Matrix.h"



int main() {
    int m = 3, n = 3;
    Matrix a = Matrix(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a(i, j) = 1;
        }
    }
    Matrix b = Matrix(m,n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b(i, j) = 2;
        }
    }
    Matrix c = a + b;
    //std::cout << c;
    return 0;
}