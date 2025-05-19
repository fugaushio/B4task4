#ifndef SOLVER_H
#define SOLVER_H

#include <Eigen/Dense>

class Solver {
public:
    Solver();
    void run();
    void print();

private:
    const int N = 50;
    const int M = 50;
    const double H = 0.01;
    const int MK = 10000;
    const double eps = 1e-6;

    Eigen::MatrixXd U;
    Eigen::MatrixXd UF;
};

#endif