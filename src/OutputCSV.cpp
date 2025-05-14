#include "OutputCSV.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void OutputCSV::output(const std::vector<double>& x, const std::string& filename){

    const int Nx = 10;
    const int Ny = 10;
    const double dx = 0.01;

    std::ofstream file(filename);
    
    if(!file){
        std::cerr << "Cannot open the file" << filename << std::endl;
        return;
    }

    for (int j = 0; j < Ny; ++j) {
        for (int i = 0; i < Nx; ++i) {
            int idx = j * Nx + i;
            double x_coord = i * dx;
            double y_coord = j * dx;

            file << "(" << x_coord << "," << y_coord << "), " << x[idx] << "\n";
        }
    }

    file.close();
}