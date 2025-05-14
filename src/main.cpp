#include <iostream>
#include <vector>
#include "Gauss.h"
#include "OutputCSV.h"
#include "Matrix.h"

int main() {
    int N = 100;

    std::vector<double> x(N);
    std::vector<double> b(N);
    std::vector<std::vector<double>> A(N, std::vector<double>(N));

    Matrix::matrix(A,b);
    
    GaussE::gausse(A,x,b);

    OutputCSV::output(x, "result.csv");

    return 0;
}
