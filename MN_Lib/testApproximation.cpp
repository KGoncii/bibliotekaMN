#include "Approximation.h"
#include <cassert>
#include <vector>
#include <cmath>
#include <functional>
#include <iostream>

using namespace Approximation;

void test_polynomialBasis() {
    // Test 1: typowy przypadek
    assert(std::abs(polynomialBasis(2, 3.0) - 9.0) < 1e-12);
    // Test 2: przypadek brzegowy - stopień 0 (powinno zwrócić 1)
    assert(std::abs(polynomialBasis(0, 5.0) - 1.0) < 1e-12);
}

void test_evaluateApproximation() {
    // Test 1: typowy przypadek
    std::vector<double> coeffs1 = { 1.0, 2.0, 3.0 }; // 1 + 2x + 3x^2
    double x1 = 2.0;
    double expected1 = 1.0 + 2.0 * 2.0 + 3.0 * 4.0; // 1 + 4 + 12 = 17
    assert(std::abs(evaluateApproximation(coeffs1, x1) - expected1) < 1e-12);
    // Test 2: przypadek brzegowy - pusty wektor współczynników
    std::vector<double> coeffs2;
    double val = evaluateApproximation(coeffs2, 1.0);
    assert(val == 0.0);
}

void test_computeSystemMatrix() {
    // Test 1: typowy przypadek
    int degree1 = 1;
    double a1 = 0.0, b1 = 1.0;
    std::vector<std::vector<double>> A1(degree1 + 1, std::vector<double>(degree1 + 1, 0.0));
    std::vector<double> b_vec1(degree1 + 1, 0.0);
    auto func1 = [](double x) { return x; };

    computeSystemMatrix(degree1, a1, b1, A1, b_vec1, func1);

    assert(std::abs(A1[0][0] - 1.0) < 1e-2);
    assert(std::abs(A1[0][1] - 0.5) < 1e-2);
    assert(std::abs(A1[1][0] - 0.5) < 1e-2);
    assert(std::abs(A1[1][1] - 1.0 / 3.0) < 1e-2);
    assert(std::abs(b_vec1[0] - 0.5) < 1e-2);
    assert(std::abs(b_vec1[1] - 1.0 / 3.0) < 1e-2);

    // Test 2: przypadek brzegowy - przedział o zerowej długości
    int degree2 = 2;
    std::vector<std::vector<double>> A2(degree2 + 1, std::vector<double>(degree2 + 1, 0.0));
    std::vector<double> b_vec2(degree2 + 1, 0.0);
    auto func2 = [](double x) { return 1.0; };
    computeSystemMatrix(degree2, 1.0, 1.0, A2, b_vec2, func2);
    for (auto& row : A2)
        for (auto v : row)
            assert(v == 0.0);
    for (auto v : b_vec2)
        assert(v == 0.0);
}

void test_calculateAverageError() {
    // Test 1: typowy przypadek
    std::vector<double> coeffs1 = { 0.0, 2.0 }; // 0 + 2x
    auto func1 = [](double x) { return 2.0 * x; };
    double error1 = calculateAverageError(coeffs1, func1, 0.0, 1.0, 10);
    if (!(error1 < 1e-10)) {
        std::cerr << "Blad: calculateAverageError zwrocil " << error1 << ", oczekiwano < 1e-10" << std::endl;
        std::abort();
    }
    // Test 2: przypadek brzegowy - liczba próbek = 0
    std::vector<double> coeffs2 = { 1.0 };
    auto func2 = [](double x) { return 1.0; };
    double error2 = calculateAverageError(coeffs2, func2, 0.0, 2.0, 0);
    assert(error2 == 0.0);
}

void test_polynomialBasis_errors() {
    // Przypadek brzegowy: ujemny stopień wielomianu
    try {
        polynomialBasis(-1, 2.0);
        assert(false && "Brak wyjątku dla ujemnego stopnia");
    }
    catch (...) {
        // Oczekiwany wyjątek lub błąd
    }
}

void test_evaluateApproximation_errors() {
    // Przypadek brzegowy: pusty wektor współczynników
    std::vector<double> coeffs;
    double val = evaluateApproximation(coeffs, 1.0);
    assert(val == 0.0);
}

void test_computeSystemMatrix_errors() {
    // Przypadek brzegowy: przedział o zerowej długości
    int degree = 1;
    std::vector<std::vector<double>> A(degree + 1, std::vector<double>(degree + 1, 0.0));
    std::vector<double> b_vec(degree + 1, 0.0);
    auto func = [](double x) { return x; };
    computeSystemMatrix(degree, 1.0, 1.0, A, b_vec, func);
    for (auto& row : A)
        for (auto v : row)
            assert(v == 0.0);
}

void test_calculateAverageError_errors() {
    // Przypadek brzegowy: liczba próbek = 0
    std::vector<double> coeffs = { 1.0 };
    auto func = [](double x) { return 1.0; };
    double err = calculateAverageError(coeffs, func, 0.0, 1.0, 0);
    assert(err == 0.0);
}

void run_tests_approximation() {
    test_polynomialBasis();
    test_evaluateApproximation();
    test_computeSystemMatrix();
    test_calculateAverageError();
    test_polynomialBasis_errors();
    test_evaluateApproximation_errors();
    test_computeSystemMatrix_errors();
    test_calculateAverageError_errors();
    std::cout << "Wszystkie testy Approximation.h zaliczone!" << std::endl;
}