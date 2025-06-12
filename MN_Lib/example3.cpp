#include "NonlinearAlgebra.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace NonlinearEquations;

// Przyk�adowa funkcja: x^3 - x - 2 = 0
double f(double x) { return x * x * x - x - 2; }
double df(double x) { return 3 * x * x - 1; }

/**
 * Rozwi�zywanie r�wnania nieliniowego x^3 - x - 2 = 0 trzema metodami numerycznymi.
 *
 * Program demonstruje wyznaczanie pierwiastka r�wnania nieliniowego za pomoc�:
 *  - metody bisekcji,
 *  - metody Newtona,
 *  - metody siecznych.
 *
 * Wynikiem dzia�ania programu s� przybli�one warto�ci pierwiastka wyznaczone ka�d� z metod
 * oraz por�wnanie b��d�w wzgl�dem warto�ci referencyjnej.
 *
 * Zmienne i parametry:
 *  - f: funkcja, dla kt�rej szukamy pierwiastka,
 *  - df: pochodna funkcji f (dla metody Newtona),
 *  - root_bisect: pierwiastek wyznaczony metod� bisekcji,
 *  - root_newton: pierwiastek wyznaczony metod� Newtona,
 *  - root_secant: pierwiastek wyznaczony metod� siecznych,
 *  - ref: warto�� referencyjna pierwiastka.
 *
 */

int main3() {
    std::cout << "Rozwiazywanie rownania x^3 - x - 2 = 0\n";
    std::cout << std::fixed << std::setprecision(15);

    double root_bisect = bisection(f, 1, 2, 1e-8, 100);
    std::cout << "Bisekcja: pierwiastek w przyblizeniu = " << root_bisect << "\n";

    double root_newton = newton(f, df, 1.5, 1e-8, 100);
    std::cout << "Newton: pierwiastek w przyblizeniu = " << root_newton << "\n";

    double root_secant = secant(f, 1, 2, 1e-8, 100);
    std::cout << "Sieczne: pierwiastek w przyblizeniu = " << root_secant << "\n";

    double ref = 1.5213797;
    std::cout << "Blad bisekcji: " << std::abs(root_bisect - ref) << "\n";
    std::cout << "Blad Newtona: " << std::abs(root_newton - ref) << "\n";
    std::cout << "Blad siecznych: " << std::abs(root_secant - ref) << "\n";

    return 0;
}