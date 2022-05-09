#include <iostream>
#include "Matrix.h"

using std::cout, std::cin, std::cerr, std::exception;

void TestAddition() {
    Matrix m1({{1, 2},{3, 4},{5, 6}});
    Matrix m2({{0, },{0, -1},{1, 2}});
    Matrix correct_sum({{1, 3},{3, 3},{6,8}});
    Matrix diff_size({{1, 2, 3},{3, 4, 2}});

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

    //Matrix result = m1 + diff_size;
    //cout << result;
}


int main() {
    TestAddition();
    return 0;
}