#include "Poisson.h"
#include <iostream>
#include <vector>


void Poisson::makeMatrix() {

    int SIZE = nodes.size();
    
    int Nx = Lx/dx+1;//各辺格子数
    int Ny = Ly/dy+1;

    std::vector<std::vector<double>> cMatrix(SIZE,std::vector<double>(SIZE));//係数行列
    std::vector<double> bvector(SIZE);

    std::cout << "格子間距離 dx = " << dx << ", dy = " << dy << std::endl;
    std::cout << "全体サイズ Lx = " << Lx << ", Ly = " << Ly << std::endl;
    std::cout << "格子数 Nx = " << Nx << ", Ny = " << Ny << std::endl;


    for ( int row = 1; row< Ny-1; row++){//ポアソン方程式
        for (int col = 1; col < Nx-1; col++) {
            int idx = row * Ny + col;
            cMatrix[idx][idx] = -2/(dx*dx)-2/(dy*dy);
            cMatrix[idx][idx - 1] = 1/(dy*dy);
            cMatrix[idx][idx + 1] = 1/(dy*dy);
            cMatrix[idx][idx - Nx] = 1/(dx*dx);
            cMatrix[idx][idx + Nx] = 1/(dx*dx);
        }
    } 

    //ディクリレ条件
    for (int i=0; i<Nx*Ny; i+=Ny){//下底 (y = 0, φ = 0)
        for(int j=0; j<Nx*Nx;j++){
            if(j==i){
                cMatrix[i][j] = 1;
            }else{cMatrix[i][j] = 0;}
        }
    }

    for (int i=Ny-1; i<Ny*Ny; i+=Ny){//上底 (y = Lx, φ = 1)
        for(int j=0; j<Ny*Ny;j++){
            if(j==i){
                cMatrix[i][j] = 1;
            }else{cMatrix[i][j] = 0;}
        }
        bvector[i] = 1.0;
    }

    //ノイマン条件
    for (int row = 1; row<Ny-1; row++){// 左側境界（x = 0, ∂φ/∂x = 0）
        int idx = row;//左端
        int idx_next = row + Ny;//隣接ノード

        cMatrix[idx][idx] = -1.0/dx;
        cMatrix[idx][idx_next] = 1.0/dx;
    }

    for (int row = 1; row<Ny-1; row++){// 右側境界（x = Lx, ∂φ/∂x = 0）
        int idx = Ny*(Nx-1) + row;//右端
        int idx_prev = idx - Ny;//隣接ノード

        cMatrix[idx][idx] = 1.0/dx;
        cMatrix[idx][idx_prev] = -1.0/dx;
    }

    this->Matrix = cMatrix;
    this->Vector = bvector;

    /* for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            std::cout<<Matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    } 
    for(int j=0;j<SIZE;j++){
        std::cout<<bvector[j]<<std::endl;
    } */ 
}