#include <iostream>
#include <vector>
#include <string>
#include "../include/NumericalMethods.h"
#include "../include/FileWriter.h"
#include "../include/ODEFunctions.h"

int main() {
    std::cout << "=== CSE261 Numerical Methods Project ===\n";
    std::cout << "Method: Euler, Heun, Midpoint\n\n";

    // 1. PARAMETERS
    double y0 = 0.5;
    double t0 = 0.0;
    double tend = 2.0;
    double h_default = 0.1;

    // 2. RUN SIMULATION FOR CURVES (Visual Comparison)
    std::cout << "Running simulations with h = " << h_default << "...\n";

    auto eulerData = NumericalSolver::solveEuler(ODEProblems::test_derivative, ODEProblems::test_exact, y0, t0, tend, h_default);
    auto heunData = NumericalSolver::solveHeun(ODEProblems::test_derivative, ODEProblems::test_exact, y0, t0, tend, h_default);
    auto midData = NumericalSolver::solveMidpoint(ODEProblems::test_derivative, ODEProblems::test_exact, y0, t0, tend, h_default);

    // 3. SAVE DATA FOR PLOTTING
    // Ensure the 'results' folder exists or path is correct
    FileWriter::saveTrajectory("results_euler.csv", eulerData);
    FileWriter::saveTrajectory("results_heun.csv", heunData);
    FileWriter::saveTrajectory("results_midpoint.csv", midData);

    // 4. ERROR ANALYSIS (Error vs Step Size)
    std::cout << "\nRunning Error vs Step Size Analysis...\n";
    std::vector<double> stepSizes = {0.2, 0.1, 0.05, 0.025, 0.0125, 0.01};
    
    std::vector<std::pair<double, double>> eulerErrors;
    std::vector<std::pair<double, double>> heunErrors;
    std::vector<std::pair<double, double>> midErrors;

    for (double h : stepSizes) {
        // Get results for this step size
        auto e = NumericalSolver::solveEuler(ODEProblems::test_derivative, ODEProblems::test_exact, y0, t0, tend, h);
        auto he = NumericalSolver::solveHeun(ODEProblems::test_derivative, ODEProblems::test_exact, y0, t0, tend, h);
        auto m = NumericalSolver::solveMidpoint(ODEProblems::test_derivative, ODEProblems::test_exact, y0, t0, tend, h);

        // Calculate Global Error (Error at the final point)
        eulerErrors.push_back({h, e.back().error});
        heunErrors.push_back({h, he.back().error});
        midErrors.push_back({h, m.back().error});
    }

    FileWriter::saveErrorAnalysis("error_analysis_euler.csv", eulerErrors);
    FileWriter::saveErrorAnalysis("error_analysis_heun.csv", heunErrors);
    FileWriter::saveErrorAnalysis("error_analysis_midpoint.csv", midErrors);

    std::cout << "\nAll tasks completed successfully. Check CSV files for data.\n";

    return 0;
}