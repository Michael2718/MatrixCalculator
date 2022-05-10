#include <iostream>
#include <sstream>
#include "Matrix.h"

using std::cout, std::cin, std::cerr, std::exception, std::ostringstream;

void TestAssignment() {
    Matrix m1({{1, 2}, {3, 4}, {5, 6}});
    Matrix m2({{0, 1}, {0, -1}, {1, 2}});
    Matrix m3({{1, 2, 3}});

    Matrix new_m1({{0, 1}, {0, -1}, {1, 2}});
    Matrix new_m2({{1, 2, 3}});
    Matrix new_m3({{3, 6, 9}});

    try {
        m1 = m2;
        m2 = m3;
        m3 = m3 * 3;
        if (m1 == new_m1 && m2 == new_m2 && m3 == new_m3) {
            cout << "Test passed: assignment test." << "\n";
        } else {
            cerr << "Test failed: assignment test. Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during assignment test." << "\n";
        cerr << ex.what();
    }
}

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
    ostringstream  test_name;
    int scalar1 = 1, scalar2 = -7, scalar3 = 0;

    Matrix m1({{2, -3, 1}, {5, 0, -2}, {0, 1, -1}});
    Matrix correct_multiplication_by_scalar1({{2,-3,1}, {5,0,-2}, {0, 1, -1}});
    Matrix correct_multiplication_by_scalar2({{-14, 21, -7}, {-35, 0, 14}, {0, -7, 7}});
    Matrix correct_multiplication_by_scalar3({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});

    try {
        Matrix result = m1 * scalar1;
        test_name <<  "scalar multiplication test(scalar = " << scalar1 << ").";
        if (result == correct_multiplication_by_scalar1) {
            cout << "Test passed: " << test_name.str() << "\n";
        } else {
            cerr << "Test failed: " << test_name.str() << " Wrong result." << "\n";
        }

        result = m1 * scalar2;
        test_name.str("");
        test_name.clear();
        test_name <<  "scalar multiplication test(scalar = " << scalar2 << ").";
        if (result == correct_multiplication_by_scalar2) {
            cout << "Test passed: " << test_name.str() << "\n";
        } else {
            cerr << "Test failed: " << test_name.str() << " Wrong result." << "\n";
        }

        result = m1 * scalar3;
        test_name.str("");
        test_name.clear();
        test_name <<  "scalar multiplication test(scalar = " << scalar3 << ").";
        if (result == correct_multiplication_by_scalar3) {
            cout << "Test passed: " << test_name.str() << "\n";
        } else {
            cerr << "Test failed: " << test_name.str() << " Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during scalar multiplication test." << "\n";
        cerr << ex.what();
    }

}

void TestTranspose() {
    Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Matrix correct_transposed_matrix({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});

    try {
        Matrix result = m1.transpose();
        if (result == correct_transposed_matrix) {
            cout << "Test passed: transposition test." << "\n";
        } else {
            cerr << "Test failed: transposition test. Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during transposition test." << "\n";
        cerr << ex.what();
    }
}

void TestDeterminantCalculation() {
    Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Matrix m2({{1, 2, 3}, {4, 5, 4}, {7, 10, 9}});

    try {
        if (m1.determinant() == 0) {
            cout << "Test passed: determinant calculation test(D = 0)." << "\n";
        } else {
            cerr << "Test failed: determinant calculation test(D = 0). Wrong result." << "\n";
        }

        if (m2.determinant() == 4) {
            cout << "Test passed: determinant calculation test(D = 4)." << "\n";
        } else {
            cerr << "Test failed: determinant calculation test(D = 4). Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during determinant calculation test." << "\n";
        cerr << ex.what();
    }
}

void TestMinorCalculation() {
    Matrix m1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Matrix m2({{1, 2, 3}, {4, 5, 4}, {7, 10, 9}});

    try {
        if (m1.minor(1, 1) == -12) {
            cout << "Test passed: minor calculation test(M = -12)." << "\n";
        } else {
            cerr << "Test failed: minor calculation test(M = -12). Wrong result." << "\n";
        }

        if (m2.minor(0, 2) == 5) {
            cout << "Test passed: minor calculation test(M = 5)." << "\n";
        } else {
            cerr << "Test failed: minor calculation test(M = 5). Wrong result." << "\n";
        }
    } catch (exception& ex) {
        cerr << "Error during minor calculation test." << "\n";
        cerr << ex.what();
    }
}

int main() {
    TestAssignment();
    cout << "\n";
    TestAddition();
    cout << "\n";
    TestSubtraction();
    cout << "\n";
    TestMatrixMultiplication();
    cout << "\n";
    TestScalarMultiplication();
    cout << "\n";
    TestTranspose();
    cout << "\n";
    TestDeterminantCalculation();
    cout << "\n";
    TestMinorCalculation();
    return 0;
}