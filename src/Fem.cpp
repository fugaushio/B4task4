#include "Fem.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Sparse>
#include <eigen3/Eigen/SparseQR>
#include <fstream>
#include <cmath>
#include <cstdlib>



void Fem::load(const std::string& filename_node, const std::string& filename_element)
{

    std::ifstream infile(filename_node);
    if (!infile) {
        std::cerr << "ファイルを開けません: " << filename_node << std::endl;
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        double value;
        std::vector<double> row;

        while (ss >> value) {
            row.push_back(value);
        }
        if (!row.empty()) {
            node_list.push_back(row);
        }
    }
    infile.close();

    std::ifstream infile2(filename_element);
    if (!infile2) {
        std::cerr << "ファイルを開けません: " << filename_element << std::endl;
        return;
    }
    std::string line2;
    while (std::getline(infile2, line2)) {
        std::stringstream ss(line2);
        int value2;
        std::vector<int> row2;

        while (ss >> value2) {
            row2.push_back(value2);
        }
        if (!row2.empty()) {
            element_list.push_back(row2);
        }
    }
    infile.close();

    return ;
}

void Fem::organize_quad(){
    for(std::vector<int> element: element_list){
        std::array<std::array<double, 2>, 4> nodes;
        for(int i=0; i<4; i++){//四角形要素
            for(int j=0; j<2; j++){
                nodes[i][j] = node_list[element[i]][j];
            }
        }
        Set set = {element, nodes};
        Sets.push_back(set); 
    }
}

std::array<std::array<double, 4>, 4> Fem::element_matrix(std::array<std::array<double, 2>, 4> nodes){
    int n=2;
    quad q;
    q.update(nodes);
    std::array<std::array<double, 4>, 4> mat = {};
    if (n==2){
        double gaussian_point[2] = {-0.5773502961896,0.5773502961896};
        double gaussian_weight[2] = {1, 1};//省略
        std::array<std::array<double, 4>, 4> f00 = q.laplace(gaussian_point[0], gaussian_point[0]);
        std::array<std::array<double, 4>, 4> f01 = q.laplace(gaussian_point[0], gaussian_point[1]);
        std::array<std::array<double, 4>, 4> f10 = q.laplace(gaussian_point[1], gaussian_point[0]);
        std::array<std::array<double, 4>, 4> f11 = q.laplace(gaussian_point[1], gaussian_point[1]);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                mat[i][j] = f00[i][j] + f01[i][j] + f10[i][j] + f11[i][j];
            }
        }
    }
    if (n==1){
        std::array<std::array<double, 4>, 4> f = q.laplace(0, 0);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                mat[i][j] = 2 * f[i][j];
            }
        }
    }
    return mat;
}

void Fem::assembly(){
    for(Set set : Sets){
        std::array<std::array<double, 4>, 4> mat = element_matrix(set.node_positions);
        for(int i=0; i< 4; i++){
            for(int j=0; j<4; j++){
                tripletVec_A.push_back(Eigen::Triplet<double>(set.node_ids[i], set.node_ids[j], mat[i][j]));
            }
        }
    }
}

bool containsPair(const std::vector<std::pair<int, int>>& array, int i, int j) {
    return std::find(array.begin(), array.end(), std::make_pair(i, j)) != array.end();
}

void Fem::boundary(){
    // Dirichlet
    double d_top=1;
    double d_bellow=0;
    double n_right=0;
    double n_left=0;
    std::vector<std::pair<int, int>> checked;
    for (auto& t : tripletVec_A) {
        if (node_list[t.row()][1] <= 0.00001){
            if(containsPair(checked, t.row(), t.col())){
                t = Eigen::Triplet<double>(t.row(), t.col(), 0);
                continue;
            }
            if(t.row()==t.col()){
                t = Eigen::Triplet<double>(t.row(), t.col(), 1);
                // tripletVec_b.push_back(Eigen::Triplet<double>(t.row(), 0, d_bellow));//shouryaku
                checked.push_back({t.row(), t.col()});
                continue;
            }else{
                t = Eigen::Triplet<double>(t.row(), t.col(), 0);
                continue;
            }
        }
        if (0.089999 <= node_list[t.row()][1]){
            if(containsPair(checked, t.row(), t.col())){
                t = Eigen::Triplet<double>(t.row(), t.col(), 0);
                continue;
            }
            if(t.row()==t.col()){
                t = Eigen::Triplet<double>(t.row(), t.col(), 1);
                tripletVec_b.push_back(Eigen::Triplet<double>(t.row(), 0, d_top));
                checked.push_back({t.row(), t.col()});
                continue;
            }else{
                t = Eigen::Triplet<double>(t.row(), t.col(), 0);
                continue;
            }
        }
        // Neumann
        if (node_list[t.row()][0] <= 0.00001) {
            if (node_list[t.row()][1] <= 0.00001){
                continue;
            }else{
                if(containsPair(checked, t.row(), t.col())){
                    t = Eigen::Triplet<double>(t.row(), t.col(), 0);
                    continue;
                }
                if(t.row()==t.col()){
                    t = Eigen::Triplet<double>(t.row(), t.col(), -1);
                    checked.push_back({t.row(), t.col()});
                    continue;
                    // tripletVec_b.push_back(Eigen::Triplet<double>(t.row(), 0, n_left / dx)); #shouryaku
                }else if(t.row()==(t.col() - 1)){
                    t = Eigen::Triplet<double>(t.row(), t.col(), 1);
                    checked.push_back({t.row(), t.col()});
                    continue;
                }else{
                    t = Eigen::Triplet<double>(t.row(), t.col(), 0);
                    continue;
                }
            }
        }
        if (0.089999 <= node_list[t.row()][0]){
            if (0.089999 <= node_list[t.row()][1]){
                continue;
            }else{
                if(containsPair(checked, t.row(), t.col())){
                    t = Eigen::Triplet<double>(t.row(), t.col(), 0);
                    continue;
                }
                if((t.row())==t.col()){
                    t = Eigen::Triplet<double>(t.row(), t.col(), 1);
                    checked.push_back({t.row(), t.col()});
                    continue;
                    // tripletVec_b.push_back(Eigen::Triplet<double>(t.row(), 0, n_right / dx)); #shouryaku
                }else if(t.row()==(t.col() + 1)){
                    t = Eigen::Triplet<double>(t.row(), t.col(), -1);
                    checked.push_back({t.row(), t.col()});
                    continue;
                }else{
                    t = Eigen::Triplet<double>(t.row(), t.col(), 0);
                    continue;
                }
            }
        }
    }
}

void Fem::solve()//行列をつくってeigenで解く
{
    Eigen::SparseMatrix<double> A(100, 100), b(100, 1);
    A.setFromTriplets(tripletVec_A.begin(), tripletVec_A.end());
    b.setFromTriplets(tripletVec_b.begin(), tripletVec_b.end());
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            printf("%lf, ", A.coeff(i, j));
        }
        printf("\n");
    }
    Eigen::SparseQR< Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int> > solver;  
    solver.compute(A);
    if( solver.info() != Eigen::Success ) {
      std::cerr << "decomposition failed" << std::endl;
    }
    x = solver.solve(b);
    if( solver.info() != Eigen::Success ) {
      std::cerr << "solving failed" << std::endl;
    }
    return ;
}

void Fem::show()//カラーマップで画像を出力
{
    std::ofstream data("grid_data2.dat");
    int k=0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            data << j * 0.01 << " " << i * 0.01 << " " << x[k] << "\n";
            k++;
        }
        data << "\n";
    }

    data.close();

    std::ofstream gp("plot_heatmap2.gp");
    gp << "set terminal pngcairo size 800,600 enhanced\n";
    gp << "set output 'heatmap2.png'\n";
    gp << "set pm3d map\n";
    gp << "set palette rgbformulae 33,13,10\n";  
    gp << "set xlabel 'X'\n";
    gp << "set ylabel 'Y'\n";
    gp << "splot 'grid_data2.dat' using 1:2:3 with pm3d notitle\n";
    gp.close();

    system("gnuplot plot_heatmap2.gp");

    std::cout << "heatmap2.png が生成されました。\n";
    return ;
}


void quad::update(std::array<std::array<double, 2>, 4> nodes){
    for(int i=0; i<4; i++){
        x[i] = nodes[i][0];
        y[i] = nodes[i][1];
    }
    a_1 = 0.25 * (-x[0] + x[1] + x[2] - x[3]);
    a_2 = 0.25 * ( x[0] - x[1] + x[2] - x[3]);
    a_3 = 0.25 * (-y[0] + y[1] + y[2] - y[3]);
    a_4 = 0.25 * ( y[0] - y[1] + y[2] - y[3]);
    a_5 = 0.25 * (-x[0] - x[1] + x[2] + x[3]);
    a_6 = a_2;
    a_7 = 0.25 * (-y[0] - y[1] + y[2] + y[3]);
    a_8 = a_4;
}

std::array<std::array<double, 2>, 2> quad::Jacobi(double s, double t){
    std::array<std::array<double, 2>, 2> J;
    J[0][0] = a_1 + a_2 * t;
    J[0][1] = a_3 + a_4 * t;
    J[1][0] = a_5 + a_6 * s;
    J[1][1] = a_7 + a_8 * s;
    return J;
}

std::array<std::array<double, 2>, 2> quad::Jacobi_inv(double s, double t){
    std::array<std::array<double, 2>, 2> J_inv;
    double J_det = (a_1 + a_2 * t) * (a_7 + a_8 * s) - (a_3 + a_4 * t) * (a_5 + a_6 * s);
    if(J_det == 0){printf("detJ=0\n"); exit(-1);}
    J_inv[0][0] = (a_7 + a_8 * s) / J_det;
    J_inv[0][1] = -(a_3 + a_4 * t) / J_det;
    J_inv[1][0] = -(a_5 + a_6 * s) / J_det;
    J_inv[1][1] = (a_1 + a_2 * t) / J_det;
    return J_inv;
}

std::array<std::array<double, 2>, 4> quad::dSdX(double s, double t){
    std::array<std::array<double, 2>, 4> dSdX;
    dSdX[0][0] = -0.25 * (1 - t);
    dSdX[0][1] = -0.25 * (1 - s);
    dSdX[1][0] =  0.25 * (1 - t);
    dSdX[1][1] = -0.25 * (1 - s);
    dSdX[2][0] =  0.25 * (1 - t);
    dSdX[2][1] =  0.25 * (1 - s);
    dSdX[3][0] = -0.25 * (1 - t);
    dSdX[3][1] =  0.25 * (1 - s);
    return dSdX;
}

std::array<std::array<double, 2>, 4> quad::calc_dNdX(double s, double t){
    std::array<std::array<double, 2>, 4> dNdX;
    std::array<std::array<double, 2>, 4> dSdX = quad::dSdX(s, t);
    std::array<std::array<double, 2>, 2> J_inv = quad::Jacobi_inv(s, t);
    for(int i=0; i<4; i++){
        dNdX[i][0] = J_inv[0][0] * dSdX[i][0] + J_inv[0][1] * dSdX[i][1]; 
        dNdX[i][1] = J_inv[1][0] * dSdX[i][0] + J_inv[1][1] * dSdX[i][1]; 
    }
    return dNdX;
}

std::array<std::array<double, 4>, 4> quad::laplace(double s, double t){
    std::array<std::array<double, 2>, 4> dNdX = calc_dNdX(s, t);
    std::array<std::array<double, 4>, 4> f;
    double J_det = (a_1 + a_2 * t) * (a_7 + a_8 * s) - (a_3 + a_4 * t) * (a_5 + a_6 * s);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            f[i][j] = (dNdX[i][0] * dNdX[j][0] + dNdX[i][1] * dNdX[j][1]) * J_det;
        }
    }
    return f;
}
