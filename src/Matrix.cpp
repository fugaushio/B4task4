#include <iostream>
#include <vector>
#include <cmath>
#include "Matrix.h"

using namespace std;

void Matrix::matrix(vector<vector<double>>& A, vector<double>& b) {
    const int Nx = 10;
    const int Ny = 10;
    const int N = Nx * Ny;
    const double dx = 0.01;

    auto index = [&](int i, int j) { return j * Nx + i; };

    for (int j = 0; j < Ny; j++) {
        for (int i = 0; i < Nx; i++) {
            int idx = index(i, j);

            // Dirichlet条件：下底
            if (j == 0) {
                A[idx][idx] = 1.0;
                b[idx] = 0.0;
            }
            // Dirichlet条件：上底
            else if (j == Ny - 1) {
                A[idx][idx] = 1.0;
                b[idx] = 1.0;
            }
            // Neumann条件：左端
            else if (i == 0) {
                A[idx][idx] = -1.0;
                A[idx][index(i + 1, j)] = 1.0;
                b[idx] = 0.0;
            }
            // Neumann条件：右端
            else if (i == Nx - 1) {
                A[idx][idx] = -1.0;
                A[idx][index(i - 1, j)] = 1.0;
                b[idx] = 0.0;
            }
            // 内部ノード
            else {
                A[idx][idx] = -4.0;
                A[idx][index(i + 1, j)] = 1.0;
                A[idx][index(i - 1, j)] = 1.0;
                A[idx][index(i, j + 1)] = 1.0;
                A[idx][index(i, j - 1)] = 1.0;
                b[idx] = 0.0;
            }
        }
    }
}