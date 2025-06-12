#include "DifferentialEquations.h"
#include <iostream>
#include <iomanip>

using namespace DifferentialEquations;

/**
 * Symulacja ch³odzenia cia³a: porównanie metody Eulera i Runge-Kutty.
 *
 * Program oblicza i wyœwietla temperaturê cia³a w kolejnych krokach czasowych,
 * korzystaj¹c z dwóch metod numerycznych: Eulera oraz Runge-Kutty.
 * Wyniki prezentowane s¹ w formie tabeli zawieraj¹cej:
 *  - czas (t),
 *  - temperaturê obliczon¹ metod¹ Eulera,
 *  - temperaturê obliczon¹ metod¹ Runge-Kutty.
 *
 * Zmienne:
 *  - T0: temperatura pocz¹tkowa,
 *  - dt: krok czasowy,
 *  - t_max: czas koñcowy symulacji.
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