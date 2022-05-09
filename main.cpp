#include <iostream>
#include "Matrix.h"

using std::cout, std::cin, std::cerr, std::exception;

void TestAddition() {
    Matrix m1({{1, 2}, {3, 4}, {5, 6}});
    Matrix m2({{0, 1}, {0, -1}, {1, 2}});
    Matrix correct_sum({{1, 3}, {3, 3},{6,8}});
    Matrix diff_size({{1, 2, 3}, {3, 4, 2}});

    try {
        Matrix result = m1 + m2;
        if (result == correct_sum) {
            cout << "Test passed: addition test." << "\n";
        } else {
            cerr << "Test failed: addition test. Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during addition test." << "\n";
        cerr << ex.what();
    }

    try {
        Matrix result;
        result = m1 + diff_size;
        if (result.empty()) {
            cout << "Test passed: addition test with matrices of different size." << "\n";
        }
        else {
            cerr << "Test failed: addition test with matrices of different size. Wrong Result." << "\n";
        }
    }
    catch (exception& ex) {
        cout << "Test passed: addition test with matrices of different size." << "\n";
    }
}

void TestSubtraction() {
    Matrix m1({{1, 2}, {3, 4}, {5, 6}});
    Matrix m2({{0, 1}, {0, -1}, {1, 2}});
    Matrix correct_subtraction({{1, 1}, {3, 5}, {4, 4}});
    Matrix diff_size({{1, 2, 3}, {3, 4, 2}});

    try {
        Matrix result = m1 - m2;
        if (result == correct_subtraction) {
            cout << "Test passed: subtraction test." << "\n";
        } else {
            cerr << "Test failed: subtraction test. Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during subtraction test." << "\n";
        cerr << ex.what();
    }

    try {
        Matrix result;
        result = m1 - diff_size;
        if (result.empty()) {
            cout << "Test passed: subtraction test with matrices of different size." << "\n";
        }
        else {
            cerr << "Test failed: subtraction test with matrices of different size. Wrong Result." << "\n";
        }
    }
    catch (exception& ex) {
        cout << "Test passed: subtraction test with matrices of different size." << "\n";
    }
}

void TestMatrixMultiplication() {
    Matrix m1({{2,-3,1},{5,4,-2}});
    Matrix m2({{-7,5},{2,-1},{4,3}});
    Matrix correct_multiplication({{-16,16},{-35,15}});
    Matrix diff_size({{1, 2, 3}});

    try {
        Matrix result = m1 * m2;
        if (result == correct_multiplication) {
            cout << "Test passed: matrix multiplication test." << "\n";
        } else {
            cerr << "Test failed: matrix multiplication test. Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during matrix multiplication test." << "\n";
        cerr << ex.what();
    }

    try {
        Matrix result;
        result = m1 * diff_size;
        if (result.empty()) {
            cout << "Test passed: matrix multiplication test with matrices of different size." << "\n";
        }
        else {
            cerr << "Test failed: matrix multiplication test with matrices of different size. Wrong Result." << "\n";
        }
    }
    catch (exception& ex) {
        cout << "Test passed: matrix multiplication test with matrices of different size." << "\n";
    }
}

void TestScalarMultiplication() {
    Matrix m1({{2,-3,1}, {5,0,-2}, {0, 1, -1}});
    int scalar = 7;
    Matrix correct_multiplication({{14, -21, 7}, {35, 0, -14}, {0, 7, -7}});

    try {
        Matrix result = m1 * scalar;
        if (result == correct_multiplication) {
            cout << "Test passed: scalar multiplication test(scalar = " << scalar << ")." << "\n";
        } else {
            cerr << "Test failed: scalar multiplication test. Wrong result." << "\n";
        }
        if (result == correct_multiplication) {
            cout << "Test passed: scalar multiplication test(scalar = " << scalar << ")." << "\n";
        } else {
            cerr << "Test failed: scalar multiplication test. Wrong result." << "\n";
        }
        if (result == correct_multiplication) {
            cout << "Test passed: scalar multiplication test(scalar = " << scalar << ")." << "\n";
        } else {
            cerr << "Test failed: scalar multiplication test. Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during scalar multiplication test." << "\n";
        cerr << ex.what();
    }

}

int main() {
    TestAddition();
    cout << "\n";
    TestSubtraction();
    cout << "\n";
    TestMatrixMultiplication();
    cout << "\n";
    TestScalarMultiplication();
    return 0;
}