#include <iostream>
#include "Matrix.h"


void input() {

}

int main() {
    int m1, n1, m2, n2;
    char op;


    std::cout << "Размеры первой матрицы через пробел: ";
    std::cin >> m1 >> n1;
    std::cout << "Первая матрица:\n";

    Matrix a = Matrix(m1, n1);
    for (int i = 0; i < m1; ++i) {
        for (int j = 0; j < n1; ++j) {
            std::cin >> a(i, j);
        }
    }

    std::cout << "Оператор(+, -, *, T):\n";
    std::cin >> op;

    if (op == '+') {
        std::cout << "Размеры второй матрицы через пробел: ";
        std::cin >> m2 >> n2;
        std::cout << "Вторая матрица:\n";

        Matrix b = Matrix(m2, n2);
        for (int i = 0; i < m2; ++i) {
            for (int j = 0; j < n2; ++j) {
                std::cin >> b(i, j);
            }
        }

        Matrix c = a + b;
        std::cout << "Результат:\n";
        c.print();
    } else if (op == '-') {
        std::cout << "Размеры второй матрицы через пробел: ";
        std::cin >> m2 >> n2;
        std::cout << "Вторая матрица:\n";

        Matrix b = Matrix(m2, n2);
        for (int i = 0; i < m2; ++i) {
            for (int j = 0; j < n2; ++j) {
                std::cin >> b(i, j);
            }
        }

        Matrix c = a - b;
        std::cout << "Результат:\n";
        c.print();
    } else if (op =='*') {
        std::cout << "Умножение на матрицу или на число? (1 - Матрица, 2 - Число)\n";
        char c;
        std::cin >> c;
        if (c == '1') {

        } else if (c == '2') {

        } else {
            //
        }
    } else if (op == 'T') {

    } else {

    }
    return 0;
}