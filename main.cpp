#include <iostream>
#include "Matrix.h"
#include <vector>

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
    Matrix a = matrix_input();
    std::cout << "Оператор(+, -, *, T(транспонирование):\n";
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
    } else if (op =='*') {
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
    }
    return 0;
}