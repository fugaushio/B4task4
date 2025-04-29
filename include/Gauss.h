#ifndef GAUSS_H
#define GAUSS_H

#include <vector>
#include <iostream>

class GaussE {
public:
    static void gausse(std::vector<std::vector<double>> A,std::vector<double> x,std::vector<double> b);
};

#endif // GAUSS_H