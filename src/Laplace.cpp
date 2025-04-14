#include "Laplace.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Sparse>
#include <eigen3/Eigen/SparseQR>
#include <fstream>
#include <cmath>
#include <cstdlib>

Greeter::Greeter(const std::string& message) : message_(message) {}

void Greeter::greet() {
    std::cout << message_ << std::endl;
}

void Laplace::init(double Lx_, double Ly_, double nx_, double ny_)//状況設定
{
    Lx = Lx_;
    Ly = Ly_;
    nx = nx_;
    ny = ny_;
    dx = Lx / (nx-1);
    dy = Ly / (ny-1);
}

void Laplace::assembly()//全体行列に値を代入（境界条件を除く）
{
    for (int i=0; i < nx*ny; i++){
        int ix = i / ny;
        int iy = i % ny;
        if (ix == 0 || ix == nx-1 || iy == 0 || iy == ny-1) {
            continue;
        }
        tripletVec_M.push_back(Eigen::Triplet<double>(i, i-ny, 1/(dx*dx)));
        tripletVec_M.push_back(Eigen::Triplet<double>(i, i, -2/(dx*dx) + -2/(dy*dy)));
        tripletVec_M.push_back(Eigen::Triplet<double>(i, i+ny, 1/(dx*dx)));
        tripletVec_M.push_back(Eigen::Triplet<double>(i, i-1, 1/(dy*dy)));
        tripletVec_M.push_back(Eigen::Triplet<double>(i, i+1, 1/(dy*dy)));
    }
}

void Laplace::boundary(double d1, double d2, double n1, double n2)//境界条件の値を代入
{
    // Dirichlet
    for (int i=0; i < nx*ny; i+=ny){
        tripletVec_M.push_back(Eigen::Triplet<double>(i, i, 1));             
        tripletVec_b.push_back(Eigen::Triplet<double>(i, 0, d1));
        tripletVec_M.push_back(Eigen::Triplet<double>(i+ny-1, i+ny-1, 1));   
        tripletVec_b.push_back(Eigen::Triplet<double>(i+ny-1, 0, d2));
    }
    // Neumann
    for (int j=1; j < ny-1; j++){
        tripletVec_M.push_back(Eigen::Triplet<double>(j, j, -1));
        tripletVec_M.push_back(Eigen::Triplet<double>(j, j+ny, 1));
        int idx_top = (nx-1)*ny + j;
        tripletVec_M.push_back(Eigen::Triplet<double>(idx_top, idx_top, -1));
        tripletVec_M.push_back(Eigen::Triplet<double>(idx_top, idx_top-ny, 1));
    }
}

void Laplace::solve()//行列をつくってeigenで解く
{
    Eigen::SparseMatrix<double> M(nx*ny, nx*ny), b(nx*ny, 1);
    M.setFromTriplets(tripletVec_M.begin(), tripletVec_M.end());
    b.setFromTriplets(tripletVec_b.begin(), tripletVec_b.end());
    Eigen::SparseQR< Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int> > solver;  
    solver.compute(M);
    if( solver.info() != Eigen::Success ) {
      std::cerr << "decomposition failed" << std::endl;
    }
    x = solver.solve(b);
    if( solver.info() != Eigen::Success ) {
      std::cerr << "solving failed" << std::endl;
    }
    return ;
}

void Laplace::show()//カラーマップで画像を出力
{
    std::ofstream data("grid_data.dat");
    int k=0;
    for (int i=0; i<nx; i++){
        for (int j=0; j<ny; j++){
            data << i * dx << " " << j * dy << " " << x[k] << "\n";
            k++;
        }
        data << "\n";
    }

    data.close();

    std::ofstream gp("plot_heatmap.gp");
    gp << "set terminal pngcairo size 800,600 enhanced\n";
    gp << "set output 'heatmap.png'\n";
    gp << "set pm3d map\n";
    gp << "set palette rgbformulae 33,13,10\n";  
    gp << "set xlabel 'X'\n";
    gp << "set ylabel 'Y'\n";
    gp << "splot 'grid_data.dat' using 1:2:3 with pm3d notitle\n";
    gp.close();

    system("gnuplot plot_heatmap.gp");

    std::cout << "heatmap.png が生成されました。\n";
    return ;
}

