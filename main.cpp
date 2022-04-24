#include <iostream>
#include "Matrix.h"

Matrix matrix_input() {
    unsigned int m, n;

    std::cout << "Размеры матрицы через пробел: ";
    std::cin >> m >> n;
    std::cout << "Матрица:\n";
    Matrix a = Matrix(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a(i, j);
        }
    }

    return a;
}

int main() {
    char op;
    //Matrix a = Matrix({{1, 2, 3, 4, 2}, {-5, 2, 1, 2, -3}, {2, 1, 4, -1, 1}, {3, 2, 1, 5, 2}, {1, 4, 1, 2, 5}});
    //Matrix a = Matrix({{2, 7, 3}, {3, 9, 4}, {1, 5, 3}});
    //std::cout << "Determinant: " << a.determinant();
    //Matrix a = Matrix({{1, 2, 3}, {-1, 0, 2}, {0, 1, 4}});
    // std::cout << a.determinant() << std::endl;
    //a.invertible().print();
    Matrix a = matrix_input();
    std::cout << "Оператор(+, -, *, T(транспонирование), D(определитель):\n";
    std::cin >> op;

    if (op == '+') {
        Matrix b = matrix_input();;
        Matrix c = a + b;
        std::cout << "Результат:\n";
        c.print();
    } else if (op == '-') {
        Matrix b = matrix_input();
        Matrix c = a - b;
        std::cout << "Результат:\n";
        c.print();
    } else if (op == '*') {
        char ch;
        std::cout << "Умножение на матрицу или на число? (1 - Матрица, 2 - Число)\n";
        std::cin >> ch;
        if (ch == '1') {
            Matrix b = matrix_input();
            Matrix c = a * b;
            std::cout << "Результат:\n";
            c.print();
        } else if (ch == '2') {
            int num;
            std::cout << "Введите число:\n";
            std::cin >> num;
            Matrix b = a * num;
            std::cout << "Результат:\n";
            b.print();
        }
    } else if (op == 'T') {
        Matrix b = a.transpose();
        std::cout << "Результат:\n";
        b.print();
    } else if (op == 'D') {
        std::cout << a.determinant();
    } else if (op == 'I') {
        Matrix b = a.inverse();
        b.print();
    }
    return 0;
}