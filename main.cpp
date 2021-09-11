#include <iostream>
#include "Matrix.h"



int main() {
    int m = 3, n = 3;
    std::vector<std::vector<double> > v1 = {{1, -1},
                                            {2, 0},
                                            {3, 0}};
    Matrix a = Matrix(v1);
    Matrix b = a * 3;
    //Matrix b = a.transpose();
    //Matrix b = Matrix(m,n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            //b(i, j) = 2;
        }
    }
    //Matrix c = a * b;
    //std::cout << c;
    return 0;
}