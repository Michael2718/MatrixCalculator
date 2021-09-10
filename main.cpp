#include <iostream>
#include "Matrix.h"



int main() {
    Matrix a = Matrix(3,4);
    Matrix b = Matrix(1,1);
    a = b;
    std::cout << a(0,0);
    return 0;
}