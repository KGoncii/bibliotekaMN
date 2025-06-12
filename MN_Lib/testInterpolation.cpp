#include "Interpolation.h"
#include <cassert>
#include <vector>
#include <cmath>
#include <iostream>
#include <limits>

using namespace Interpolation;

void test_lagrangeInterpolation() {
    // Test 1: Interpolacja liniowa przez (0,0), (1,2) w x=0.5
    std::vector<double> x1 = { 0.0, 1.0 };
    std::vector<double> y1 = { 0.0, 2.0 };
    double val1 = lagrangeInterpolation(x1, y1, 0.5);
    assert(std::abs(val1 - 1.0) < 1e-12);

    // Test 2: przypadek brzegowy - interpolacja w wêŸle (x=0)
    double val2 = lagrangeInterpolation(x1, y1, 0.0);
    assert(std::abs(val2 - 0.0) < 1e-12);
}

void test_calculateMSE() {
    // Test 1: Idealna interpolacja, MSE = 0
    std::vector<double> x = { 0, 1, 2 };
    std::vector<double> y = { 1, 3, 7 };
    double mse1 = calculateMSE(x, y, x, y);
    assert(std::abs(mse1) < 1e-12);

    // Test 2: przypadek brzegowy - puste wektory
    std::vector<double> empty;
    double mse2 = calculateMSE(empty, empty, empty, empty);
    assert(mse2 == 0.0);
}

void test_findOptimalNodes() {
    // Test 1: Proste dane kwadratowe
    std::vector<double> x = { 0, 1, 2, 3, 4, 5 };
    std::vector<double> y = { 0, 1, 4, 9, 16, 25 };
    int k1 = findOptimalNodes(x, y, 3);
    assert(k1 >= 2 && k1 <= 3);

    // Test 2: przypadek brzegowy - tylko dwa punkty
    std::vector<double> x2 = { 0, 1 };
    std::vector<double> y2 = { 2, 4 };
    int k2 = findOptimalNodes(x2, y2, 2);
    assert(k2 == 2);
}

void test_selectEveryKthPoint() {
    // Test 1: Co drugi punkt
    std::vector<double> data1 = { 1, 2, 3, 4, 5, 6 };
    std::vector<double> res1 = selectEveryKthPoint(data1, 2);
    assert(res1.size() == 3 && res1[0] == 1 && res1[1] == 3 && res1[2] == 5);

    // Test 2: przypadek brzegowy - krok wiêkszy ni¿ rozmiar
    std::vector<double> data2 = { 10, 20, 30 };
    std::vector<double> res2 = selectEveryKthPoint(data2, 10);
    assert(res2.size() == 1 && res2[0] == 10);
}

void test_dividedDifferences_and_evaluateNewton() {
    // Test 1: f(x) = x^2 przez (0,0), (1,1), (2,4)
    std::vector<double> x1 = { 0, 1, 2 };
    std::vector<double> y1 = { 0, 1, 4 };
    auto coeffs1 = dividedDifferences(x1, y1);
    double val1 = evaluateNewton(coeffs1, x1, 1.5);
    assert(std::abs(val1 - 2.25) < 1e-12);

    // Test 2: przypadek brzegowy - puste wektory
    std::vector<double> x2, y2;
    auto coeffs2 = dividedDifferences(x2, y2);
    assert(coeffs2.empty());
}

void test_evaluateNatural() {
    // Test 1: f(x) = 2 + 3x + x^2 w x=2
    std::vector<double> coeffs1 = { 2, 3, 1 };
    double val1 = evaluateNatural(coeffs1, 2.0);
    assert(std::abs(val1 - 12.0) < 1e-12);

    // Test 2: przypadek brzegowy - pusty wektor wspó³czynników
    std::vector<double> coeffs2;
    double val2 = evaluateNatural(coeffs2, 10.0);
    assert(val2 == 0.0);
}

void test_evaluateHorner() {
    // Test 1: f(x) = 2 + 3x + x^2 w x=2
    std::vector<double> coeffs1 = { 2, 3, 1 };
    double val1 = evaluateHorner(coeffs1, 2.0);
    assert(std::abs(val1 - 12.0) < 1e-12);

    // Test 2: przypadek brzegowy - pusty wektor wspó³czynników
    std::vector<double> coeffs2;
    double val2 = evaluateHorner(coeffs2, 3.0);
    assert(val2 == 0.0);
}

void test_lagrangeInterpolation_errors() {
    // Ró¿ne rozmiary wektorów
    std::vector<double> x = { 0, 1 };
    std::vector<double> y = { 0 };
    try {
        lagrangeInterpolation(x, y, 0.5);
        assert(false && "Brak wyj¹tku dla ró¿nych rozmiarów");
    }
    catch (...) {
        // Oczekiwany wyj¹tek lub b³¹d
    }
}

void test_dividedDifferences_errors() {
    // Puste wektory
    std::vector<double> x, y;
    auto coeffs = dividedDifferences(x, y);
    assert(coeffs.empty());
}

void test_selectEveryKthPoint_errors() {
    // Krok wiêkszy ni¿ rozmiar
    std::vector<double> data = { 1, 2, 3 };
    auto res = selectEveryKthPoint(data, 10);
    assert(res.size() == 1 && res[0] == 1);
}

void run_tests_interpolation() {
    test_lagrangeInterpolation();
    test_calculateMSE();
    test_findOptimalNodes();
    test_selectEveryKthPoint();
    test_dividedDifferences_and_evaluateNewton();
    test_evaluateNatural();
    test_evaluateHorner();
    test_lagrangeInterpolation_errors();
    test_dividedDifferences_errors();
    test_selectEveryKthPoint_errors();
    std::cout << "Wszystkie testy Interpolation.h zaliczone!" << std::endl;
}