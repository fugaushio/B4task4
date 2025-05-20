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


    for ( int row = 1; row < Ny-1; row++){         //ポアソン方程式
        for (int col = 1; col < Nx-1; col++) {
            int idx = row * Ny + col;
            cMatrix[idx][idx] = -2/(dx*dx)-2/(dy*dy);
            cMatrix[idx][idx - 1] = 1/(dy*dy);
            cMatrix[idx][idx + 1] = 1/(dy*dy);
            cMatrix[idx][idx - Nx] = 1/(dx*dx);
            cMatrix[idx][idx + Nx] = 1/(dx*dx);
        }
    } 


    //ノイマン条件
    for (int row = 1; row< Ny-1; row++){     // 左側境界（x = 0, ∂φ/∂x = 0）
        int idx = row;                       //左端
        int idx_next = row + Ny;             //隣接ノード

        cMatrix[idx][idx] = -1.0/dx;
        cMatrix[idx][idx_next] = 1.0/dx;
    }

    for (int row = 1; row < Ny-1; row++){   // 右側境界（x = Lx, ∂φ/∂x = 0）
        int idx = Ny*(Nx-1) + row;          //右端
        int idx_prev = idx - Ny;            //隣接ノード

        cMatrix[idx][idx] = 1.0/dx;
        cMatrix[idx][idx_prev] = -1.0/dx;
    }

    
    /* for (int col = 1; col < Nx-1; col++) {     // 下側境界（y = 0, ∂φ/∂y = 0）
        int idx = col * Ny;                    // 下端（各列の最下段）
        int idx_next = idx + 1;                // 隣接ノード（y方向に上）

        cMatrix[idx][idx] = -1.0/dy;
        cMatrix[idx][idx_next] = 1.0/dy;
    }
    
    for (int col = 1; col < Nx-1; col++) {      // 上側境界（y = Ly, ∂φ/∂y = 0）
        int idx = col * Ny + (Ny - 1);          // 上端（各列の最上段）
        int idx_prev = idx - 1;                 // 隣接ノード（y方向に下）

        cMatrix[idx][idx] = 1.0/dy;
        cMatrix[idx][idx_prev] = -1.0/dy;
    } */
    
    //ディクリレ条件    
    for (int col = 0; col < Nx; col++) {    // 下側境界（y = 0, φ = 0）
        int idx = col * Ny;                 // 各列の下端ノード
        for (int j = 0; j < Nx * Ny; j++) {
            cMatrix[idx][j] = (j == idx) ? 1.0 : 0.0;
        }
        bvector[idx] = 0.0;  
    }

    for (int col = 0; col < Nx; col++) {    // 上側境界（y = Ly, φ = 1）
        int idx = col * Ny + (Ny - 1);      // 各列の上端ノード
        for (int j = 0; j < Nx * Ny; j++) {
            cMatrix[idx][j] = (j == idx) ? 1.0 : 0.0;
        }
        bvector[idx] = 1.0;
    }


    this->Matrix = cMatrix;//メンバ演算子に代入
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