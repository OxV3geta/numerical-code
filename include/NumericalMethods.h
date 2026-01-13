//part 1

#ifndef NUMERICAL_METHODS_H
#define NUMERICAL_METHODS_H

#include <vector>
#include "ODEFunctions.h"

struct DataPoint {
    double t;
    double y_approx;
    double y_exact;
    double error;
};

class NumericalSolver {
public:
    // Euler Method: y_n+1 = y_n + h * f(t_n, y_n)
    static std::vector<DataPoint> solveEuler(Func f, ExactFunc exact, double y0, double t0, double tend, double h);

    // Heun's Method (Modified Euler): Predictor-Corrector approach
    static std::vector<DataPoint> solveHeun(Func f, ExactFunc exact, double y0, double t0, double tend, double h);

    // Midpoint Method: y_n+1 = y_n + h * f(t_n + h/2, y_n + k1/2)
    static std::vector<DataPoint> solveMidpoint(Func f, ExactFunc exact, double y0, double t0, double tend, double h);
};

#endif