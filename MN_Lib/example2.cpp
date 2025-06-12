#include "DifferentialEquations.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace DifferentialEquations;

/**
 * Por�wnanie metody Heuna z rozwi�zaniem analitycznym dla r�wnania r�niczkowego.
 *
 * Program oblicza i wy�wietla warto�ci funkcji w dyskretnych krokach czasowych,
 * korzystaj�c zar�wno z metody Heuna, jak i rozwi�zania analitycznego.
 * Wyniki prezentowane s� w formie tabeli zawieraj�cej:
 *  - czas (t),
 *  - warto�� obliczon� metod� Heuna,
 *  - warto�� rozwi�zania analitycznego,
 *  - bezwzgl�dn� r�nic� mi�dzy tymi warto�ciami.
 *
 * Zmienne:
 *  - T0: warto�� pocz�tkowa,
 *  - dt: krok czasowy dla metody Heuna,
 *  - t_max: maksymalny czas oblicze�.
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