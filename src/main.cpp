#include <iostream>
#include <vector>
#include "Gauss.h"

int main() {
    std::vector<double> x;
    std::vector<double> b;
    std::vector<std::vector<double>> A;


    GaussE::gausse(A,x,b);

    return 0;
}
