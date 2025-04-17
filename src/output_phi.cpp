#include "Poisson.h"
#include <iostream>
#include <fstream>
#include <sstream>


void Poisson::output_phi() {

    int Nx = Lx/dx+1;//各辺格子数
    int Ny = Ly/dy+1;

    // 確認用出力
    for (int row = 0; row < Ny; row++) {
        for (int col = 0; col < Nx; col++) {
            std::cout << this->Phi[row*Ny + col] << "\t";
        }
        std::cout << "\n";
    }

    

}