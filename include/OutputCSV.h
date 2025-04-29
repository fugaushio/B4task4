#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <vector>

class OutputCSV {
public:
    static void output(const std::vector<double>& x, const std::string& filename);
};

#endif //OUTPUT_H