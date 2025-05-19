#include "Solver.h"
#include <iostream>
#include <cmath>
#include <cstdio>

Solver::Solver()
    : U(Eigen::MatrixXd::Zero(N + 1, M + 1)),
      UF(Eigen::MatrixXd::Zero(N + 1, M + 1)) {
    // Dirichlet 境界条件
    for (int j = 0; j < M + 1; ++j) {
        U(0, j) = 0.0;
        U(N - 1, j) = 1.0;
    }
}

void Solver::run() {
    for (int k = 0; k < MK; ++k) {
        double max_diff = 0.0;

        // Neumann 境界条件
        for (int i = 0; i < N; ++i) {
            U(i, 0) = U(i, 1);
            U(i, M - 1) = U(i, M - 2);
        }

        for (int i = 1; i < M - 1; ++i) {
            for (int j = 1; j < N - 1; ++j) {
                UF(i, j) = U(i, j);
                U(i, j) = (U(i + 1, j) + U(i - 1, j) + U(i, j + 1) + U(i, j - 1)) / 4.0;
                double diff = std::fabs(U(i, j) - UF(i, j));
                if (diff > max_diff) max_diff = diff;
            }
        }

        if (max_diff < eps) {
            std::cout << "収束しました (k = " << k << ")\n";
            break;
        }
    }
}

void Solver::print() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::printf("%6.1f", U(i, j));
        }
        std::printf("\n");
    }
}