#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <string>
#include <vector>
#include "NumericalMethods.h"

class FileWriter {
public:
    // Saves trajectory data (t, y_approx, y_exact, error) to CSV
    static void saveTrajectory(const std::string& filename, const std::vector<DataPoint>& data);
    
    // Saves error analysis (StepSize, GlobalError) to CSV
    static void saveErrorAnalysis(const std::string& filename, const std::vector<std::pair<double, double>>& errorData);
};

#endif