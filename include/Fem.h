#ifndef FEM_H
#define FEM_H

#include <string>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Sparse>



class Fem {
    public:
    void load(const std::string& filename_node, const std::string& filename_element);
    void organize_quad();
    std::array<std::array<double, 4>, 4> element_matrix(std::array<std::array<double, 2>, 4> nodes);
    void assembly();
    void boundary();
    void solve();
    void show();

    private:
    std::vector<std::vector<double>> node_list;
    std::vector<std::vector<int>> element_list;
    struct Set {
        std::vector<int> node_ids;
        std::array<std::array<double, 2>, 4> node_positions;
    };
    std::vector<Set> Sets;
    std::vector<Eigen::Triplet<double>> tripletVec_A;
    std::vector<Eigen::Triplet<double>> tripletVec_b;
    Eigen::VectorXd x;
};

class quad {
    public:
    void update(std::array<std::array<double, 2>, 4> nodes);
    // std::vector<std::vector<double>> Jacobi();
    std::array<std::array<double, 2>, 2> Jacobi(double s, double t);
    std::array<std::array<double, 2>, 2> Jacobi_inv(double s, double t);
    std::array<std::array<double, 2>, 4> dSdX(double s, double t);
    std::array<std::array<double, 2>, 4> calc_dNdX(double s, double t);
    std::array<std::array<double, 4>, 4> laplace(double s, double t);
    private:
    double x[4];
    double y[4];
    double a_1;
    double a_2;
    double a_3;
    double a_4;
    double a_5;
    double a_6;
    double a_7;
    double a_8;
};


#endif // FEM_H
