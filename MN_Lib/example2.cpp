#include "DifferentialEquations.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace DifferentialEquations;

/**
 * Porównanie metody Heuna z rozwi¹zaniem analitycznym dla równania ró¿niczkowego.
 *
 * Program oblicza i wyœwietla wartoœci funkcji w dyskretnych krokach czasowych,
 * korzystaj¹c zarówno z metody Heuna, jak i rozwi¹zania analitycznego.
 * Wyniki prezentowane s¹ w formie tabeli zawieraj¹cej:
 *  - czas (t),
 *  - wartoœæ obliczon¹ metod¹ Heuna,
 *  - wartoœæ rozwi¹zania analitycznego,
 *  - bezwzglêdn¹ ró¿nicê miêdzy tymi wartoœciami.
 *
 * Zmienne:
 *  - T0: wartoœæ pocz¹tkowa,
 *  - dt: krok czasowy dla metody Heuna,
 *  - t_max: maksymalny czas obliczeñ.
 *
 */

int main2() {
    double T0 = 970.0;
    double dt = 0.2;
    double t_max = 5.0;

    std::cout << "Porownanie: Heun vs rozwiazanie analityczne\n";
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Czas\tHeun\tAnalityczne\tRoznica\n";
    for (double t = 0; t <= t_max; t += 1.0) {
        double T_heun = heun(T0, dt, t);
        double T_analytical = analytical_solution(t);
        double diff = std::abs(T_heun - T_analytical);
        std::cout << t << "\t" << T_heun << "\t" << T_analytical << "\t" << diff << "\n";
    }
    return 0;
}