#include "NonlinearAlgebra.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace NonlinearEquations;

// Przyk³adowa funkcja: x^3 - x - 2 = 0
double f(double x) { return x * x * x - x - 2; }
double df(double x) { return 3 * x * x - 1; }

/**
 * Rozwi¹zywanie równania nieliniowego x^3 - x - 2 = 0 trzema metodami numerycznymi.
 *
 * Program demonstruje wyznaczanie pierwiastka równania nieliniowego za pomoc¹:
 *  - metody bisekcji,
 *  - metody Newtona,
 *  - metody siecznych.
 *
 * Wynikiem dzia³ania programu s¹ przybli¿one wartoœci pierwiastka wyznaczone ka¿d¹ z metod
 * oraz porównanie b³êdów wzglêdem wartoœci referencyjnej.
 *
 * Zmienne i parametry:
 *  - f: funkcja, dla której szukamy pierwiastka,
 *  - df: pochodna funkcji f (dla metody Newtona),
 *  - root_bisect: pierwiastek wyznaczony metod¹ bisekcji,
 *  - root_newton: pierwiastek wyznaczony metod¹ Newtona,
 *  - root_secant: pierwiastek wyznaczony metod¹ siecznych,
 *  - ref: wartoœæ referencyjna pierwiastka.
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