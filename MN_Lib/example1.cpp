#include "DifferentialEquations.h"
#include <iostream>
#include <iomanip>

using namespace DifferentialEquations;

/**
 * Symulacja ch�odzenia cia�a: por�wnanie metody Eulera i Runge-Kutty.
 *
 * Program oblicza i wy�wietla temperatur� cia�a w kolejnych krokach czasowych,
 * korzystaj�c z dw�ch metod numerycznych: Eulera oraz Runge-Kutty.
 * Wyniki prezentowane s� w formie tabeli zawieraj�cej:
 *  - czas (t),
 *  - temperatur� obliczon� metod� Eulera,
 *  - temperatur� obliczon� metod� Runge-Kutty.
 *
 * Zmienne:
 *  - T0: temperatura pocz�tkowa,
 *  - dt: krok czasowy,
 *  - t_max: czas ko�cowy symulacji.
 *
 */

int main1() {
    double T0 = 1200.0; 
    double dt = 0.5;
    double t_max = 1000.0; 

    std::cout << "Symulacja chlodzenia ciala (Euler vs Runge-Kutta)\n";
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Czas\tEuler\tRunge-Kutta\n";
    for (double t = 0; t <= t_max; t += 100.0) {
        double T_euler = euler(T0, dt, t);
        double T_rk = runge_kutta(T0, dt, t);
        std::cout << t << "\t" << T_euler << "\t" << T_rk << "\n";
    }
    return 0;
}