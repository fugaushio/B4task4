#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "OutputCSV.h"

using namespace std;

void OutputCSV::output(const vector<double>& x, const string& filename) {

    const int Nx = 10;
    const int Ny = 10;
    const double dx = 0.01;

    ofstream file(filename);
    
    if (!file) {
        cerr << "Cannot open the file: " << filename << endl;
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