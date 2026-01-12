#include "../include/NumericalMethods.h"
#include <cmath>

std::vector<DataPoint> NumericalSolver::solveEuler(Func f, ExactFunc exact, double y0, double t0, double tend, double h) {
    std::vector<DataPoint> results;
    double t = t0;
    double y = y0;

    // Push initial condition
    results.push_back({t, y, exact(t), std::abs(y - exact(t))});

    while (t < tend) {
        // Euler Formula
        y = y + h * f(t, y);
        t = t + h;

        double exact_val = exact(t);
        results.push_back({t, y, exact_val, std::abs(y - exact_val)});
    }
    return results;
}

std::vector<DataPoint> NumericalSolver::solveHeun(Func f, ExactFunc exact, double y0, double t0, double tend, double h) {
    std::vector<DataPoint> results;
    double t = t0;
    double y = y0;

    results.push_back({t, y, exact(t), std::abs(y - exact(t))});

    while (t < tend) {
        // 1. Predictor (Euler step)
        double slope1 = f(t, y);
        double y_predict = y + h * slope1;
        
        // 2. Corrector
        double slope2 = f(t + h, y_predict);
        y = y + (h / 2.0) * (slope1 + slope2);
        
        t = t + h;

        double exact_val = exact(t);
        results.push_back({t, y, exact_val, std::abs(y - exact_val)});
    }
    return results;
}

std::vector<DataPoint> NumericalSolver::solveMidpoint(Func f, ExactFunc exact, double y0, double t0, double tend, double h) {
    std::vector<DataPoint> results;
    double t = t0;
    double y = y0;

    results.push_back({t, y, exact(t), std::abs(y - exact(t))});

    while (t < tend) {
        // Calculate k1
        double k1 = f(t, y);
        
        // Calculate k2 (slope at midpoint)
        double k2 = f(t + h / 2.0, y + (h * k1 / 2.0));
        
        // Update y
        y = y + h * k2;
        t = t + h;

        double exact_val = exact(t);
        results.push_back({t, y, exact_val, std::abs(y - exact_val)});
    }
    return results;
}