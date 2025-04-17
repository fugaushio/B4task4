#include "Poisson.h"
#include <vector>
#include <iostream>
#include <eigen3/Eigen/Sparse>
# include <eigen3/Eigen/Dense>
# include <eigen3/Eigen/SparseQR>

typedef Eigen::Triplet<double> T;

void Poisson::solver(){
    std::vector<T> tripletVec;

    int L_row = this->Matrix.size();//行数・列数
    int L_col = this->Matrix[0].size();

    for(int i = 0; i < L_row; i++){//Tripletに行列の要素をセット
        for(int j = 0; j < L_col; j++){
            if (Matrix[i][j] != 0.0) {
                tripletVec.push_back(T(i, j, Matrix[i][j]));
            }
        }
    }

    Eigen::SparseMatrix<double> M(L_row,L_col);//疎行列Mを作る
    M.setFromTriplets(tripletVec.begin(), tripletVec.end());

    Eigen::VectorXd b(L_col);
    for(int i = 0; i < L_col; i++){
        b[i] = this->Vector[i];
    }  


    Eigen::VectorXd phi;  // 解のベクトル

    Eigen::SparseQR< Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int> > solver;  // solverオブジェクトを構築する。
    solver.compute(M);
  
    if( solver.info() != Eigen::Success ) {
      std::cerr << "decomposition failed" << std::endl;
    }
    phi = solver.solve(b);
    if( solver.info() != Eigen::Success ) {
      std::cerr << "solving failed" << std::endl;
    }

    this->Phi.resize(phi.size());//サイズ変更

    for (int i = 0; i < phi.size(); ++i) {
        this->Phi[i] = phi(i); //解を代入 
    } 
    
}