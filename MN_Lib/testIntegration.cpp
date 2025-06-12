#include "Integration.h"
#include <cassert>
#include <vector>
#include <cmath>
#include <functional>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace Integration;

void test_evaluatePolynomial() {
    // Test 1: typowy przypadek - 2x^2 + 3x + 1 w x=2
    std::vector<double> coeffs1 = { 1.0, 3.0, 2.0 };
    double val1 = evaluatePolynomial(coeffs1, 2.0);
    assert(std::abs(val1 - (2 * 4 + 3 * 2 + 1)) < 1e-12);

    // Test 2: przypadek brzegowy - pusty wektor wsp�czynnik�w
    std::vector<double> coeffs2;
    double val2 = evaluatePolynomial(coeffs2, 100.0);
    assert(val2 == 0.0);
}

void test_rectangleRule_poly() {
    // Test 1: typowy przypadek - ca�ka z x od 0 do 1 = 0.5
    std::vector<double> coeffs = { 0.0, 1.0 };
    double res1 = rectangleRule(coeffs, 0.0, 1.0, 1000);
    assert(std::abs(res1 - 0.5) < 1e-3);

    // Test 2: przypadek brzegowy - liczba przedzia��w = 0
    std::vector<double> coeffs2 = { 3.0 };
    double res2 = rectangleRule(coeffs2, 0.0, 2.0, 0);
    assert(res2 == 0.0);
}

void test_trapezoidalRule_poly() {
    // Test 1: typowy przypadek - ca�ka z x od 0 do 1 = 0.5
    std::vector<double> coeffs = { 0.0, 1.0 };
    double res1 = trapezoidalRule(coeffs, 0.0, 1.0, 1000);
    assert(std::abs(res1 - 0.5) < 1e-3);

    // Test 2: przypadek brzegowy - przedzia� o zerowej d�ugo�ci
    std::vector<double> coeffs2 = { 2.0 };
    double res2 = trapezoidalRule(coeffs2, 2.0, 2.0, 1000);
    assert(res2 == 0.0);
}

void test_simpsonsRule_poly() {
    // Test 1: typowy przypadek - ca�ka z x od 0 do 1 = 0.5
    std::vector<double> coeffs = { 0.0, 1.0 };
    double res1 = simpsonsRule(coeffs, 0.0, 1.0, 1000);
    assert(std::abs(res1 - 0.5) < 1e-6);

    // Test 2: przypadek brzegowy - liczba przedzia��w nieparzysta
    std::vector<double> coeffs2 = { 0.0, 0.0, 1.0 };
    double res2 = simpsonsRule(coeffs2, 0.0, 1.0, 11);
    assert(res2 == 0.0);
}

void test_rectangleRule_func() {
    // Test 1: typowy przypadek - ca�ka z sin(x) od 0 do pi = 2
    auto f1 = [](double x) { return std::sin(x); };
    double res1 = rectangleRule(f1, 0.0, M_PI, 10000);
    assert(std::abs(res1 - 2.0) < 1e-2);

    // Test 2: przypadek brzegowy - liczba przedzia��w = 0
    auto f2 = [](double) { return 4.0; };
    double res2 = rectangleRule(f2, 0.0, 2.0, 0);
    assert(res2 == 0.0);
}

void test_trapezoidalRule_func() {
    // Test 1: typowy przypadek - ca�ka z sin(x) od 0 do pi = 2
    auto f1 = [](double x) { return std::sin(x); };
    double res1 = trapezoidalRule(f1, 0.0, M_PI, 10000);
    assert(std::abs(res1 - 2.0) < 1e-4);

    // Test 2: przypadek brzegowy - przedzia� o zerowej d�ugo�ci
    auto f2 = [](double) { return 2.0; };
    double res2 = trapezoidalRule(f2, 2.0, 2.0, 1000);
    assert(res2 == 0.0);
}

void test_simpsonsRule_func() {
    // Test 1: typowy przypadek - ca�ka z sin(x) od 0 do pi = 2
    auto f1 = [](double x) { return std::sin(x); };
    double res1 = simpsonsRule(f1, 0.0, M_PI, 1000);
    assert(std::abs(res1 - 2.0) < 1e-6);

    // Test 2: przypadek brzegowy - liczba przedzia��w nieparzysta
    auto f2 = [](double x) { return x * x; };
    double res2 = simpsonsRule(f2, 0.0, 1.0, 11);
    assert(res2 == 0.0);
}


void test_getGaussLegendreData() {
    // Test 1: 2 w�z�y
    GaussLegendreData d2 = getGaussLegendreData(2);
    assert(d2.nodes.size() == 2 && d2.weights.size() == 2);

    // Test 2: 3 w�z�y
    GaussLegendreData d3 = getGaussLegendreData(3);
    assert(d3.nodes.size() == 3 && d3.weights.size() == 3);
}

void test_gaussLegendreIntegration() {
    // Test 1: ca�ka z 2 od 0 do 1 = 2
    auto f1 = [](double) { return 2.0; };
    double res1 = gaussLegendreIntegration(f1, 0.0, 1.0, 2, 1);
    assert(std::abs(res1 - 2.0) < 1e-6);

    // Test 2: ca�ka z x od 0 do 1 = 0.5
    auto f2 = [](double x) { return x; };
    double res2 = gaussLegendreIntegration(f2, 0.0, 1.0, 2, 1);
    assert(std::abs(res2 - 0.5) < 1e-6);
}


void test_rectangleRule_poly_errors() {
    // Liczba przedzia��w = 0
    std::vector<double> coeffs = { 1.0 };
    double res = rectangleRule(coeffs, 0.0, 1.0, 0);
    assert(res == 0.0);
}


void test_trapezoidalRule_func_errors() {
    // Przedzia� o zerowej d�ugo�ci
    auto f = [](double x) { return x; };
    double res = trapezoidalRule(f, 2.0, 2.0, 10);
    assert(res == 0.0);
}

void test_simpsonsRule_func_errors() {
    // Liczba przedzia��w nieparzysta
    auto f = [](double x) { return x; };
    double res = simpsonsRule(f, 0.0, 1.0, 11); // powinno by� parzyste
    assert(res == 0.0);
}

void test_gaussLegendreIntegration_errors() {
    // Liczba w�z��w = 0
    auto f = [](double x) { return x; };
    double res = gaussLegendreIntegration(f, 0.0, 1.0, 0, 1);
    assert(res == 0.0);
}

void run_tests_integration() {
    test_evaluatePolynomial();
    test_rectangleRule_poly();
    test_trapezoidalRule_poly();
    test_simpsonsRule_poly();
    test_rectangleRule_func();
    test_trapezoidalRule_func();
    test_simpsonsRule_func();
    test_getGaussLegendreData();
    test_gaussLegendreIntegration();
	test_rectangleRule_poly_errors();
	test_trapezoidalRule_func_errors();
	test_simpsonsRule_func_errors();
	test_gaussLegendreIntegration_errors();
    std::cout << "Wszystkie testy Integration.h zaliczone!" << std::endl;
}