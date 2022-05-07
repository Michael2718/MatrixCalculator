#include <iostream>
#include "Matrix.h"

using std::cout, std::cin;

Matrix matrix_input() {
    unsigned int m, n;

    cout << "Размеры матрицы через пробел: ";
    cin >> m >> n;
    cout << "Матрица:\n";
    Matrix a = Matrix(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a(i, j);
        }
    }

    return a;
}

int main() {
/*    char op;
    Matrix a = matrix_input();
    cout << "Оператор(+, -, *, T(транспонирование), D(определитель):\n";
    cin >> op;

    if (op == '+') {
        Matrix b = matrix_input();
        Matrix c = a + b;
        cout << "Результат:\n";
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
    }*/
/*    Matrix a({{2, -3, 1}, {1, 0, 3}});
    Matrix b({{-6, 5, 1, 1}, {2, 1, 0, 4}, {7, 1, 2, 5}});*/
    Matrix a({{1,1}, {1,1}});
    Matrix c = a * 3;
    cout << c;
    //b.print();
    return 0;
}