//part 1

#ifndef ODE_FUNCTIONS_H
#define ODE_FUNCTIONS_H

#include <cmath>
#include <functional>

// Definition of the ODE type: dy/dt = f(t, y)
using Func = std::function<double(double, double)>;
// Definition of the Exact Solution type: y = f(t)
using ExactFunc = std::function<double(double)>;

namespace ODEProblems {

    // TEST PROBLEM: y' = y - t^2 + 1, y(0) = 0.5
    // This is a standard test case.
    
    // The derivative function f(t, y)
    inline double test_derivative(double t, double y) {
        return y - (t * t) + 1; 
    }

    // The analytical (exact) solution: y(t) = (t+1)^2 - 0.5*e^t
    inline double test_exact(double t) {
        return ((t + 1) * (t + 1)) - (0.5 * std::exp(t));
    }
}

#endif