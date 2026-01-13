#include "../include/FileWriter.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void FileWriter::saveTrajectory(const std::string& filename, const std::vector<DataPoint>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    // CSV Header
    file << "t,y_approx,y_exact,abs_error\n";

    for (const auto& point : data) {
        file << point.t << "," 
             << point.y_approx << "," 
             << point.y_exact << "," 
             << point.error << "\n"; 
    }
    file.close();
    std::cout << "Saved: " << filename << std::endl;
}

// part 1()

// Note: In NumericalMethods.h, the struct member was named 'error'. 
// I used 'abs_error' above. Ensure the struct in header matches this usage.
// Let's correct the loop above to use 'point.error':
// file << point.t << "," << point.y_approx << "," << point.y_exact << "," << point.error << "\n";

void FileWriter::saveErrorAnalysis(const std::string& filename, const std::vector<std::pair<double, double>>& errorData) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    file << "StepSize,GlobalError\n";
    for (const auto& pair : errorData) {
        file << pair.first << "," << pair.second << "\n";
    }
    file.close();
    std::cout << "Saved Error Analysis: " << filename << std::endl;
}

// part 2