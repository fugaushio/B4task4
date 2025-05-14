#include <iostream>
#include <vector>
#include <cmath>
#include "Matrix.h"

using namespace std;

void Matrix::matrix(std::vector<std::vector<double>>& A,std::vector<double>& b){

    const int Nx = 10;
    const int Ny = 10;
    const int N = Nx * Ny;
    const double dx = 0.01;

    auto index = [&](int i, int j){return j*Nx + i; };
    A[N][N];
    b[N];
    
    for(int j = 0; j < Ny; j++){
        for(int i = 0; i < Nx; i++){
            int idx = index(i,j);

            //ディレクトリ条件
            if(j == 0){
                A[idx][idx] = 1.0;
                b[idx] = 0.0;
            }
            else if(j == Ny - 1){
                A[idx][idx] = 1.0;
                b[idx] = 1.0;
            }

            //ノイマン条件
            else if(i == 0){
                A[idx][idx] = -1.0;
                A[idx][index(i + 1, j)] = 1.0;
                b[idx] = 0.0;
            }
            else if(i == Nx - 1){
                A[idx][idx] = -1.0;
                A[idx][index(i - 1, j)] = 1.0;
                b[idx] = 0.0;
            }

            //離散化
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