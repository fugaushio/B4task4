#ifndef LAPLACE_H
#define LAPLACE_H

#include <string>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Sparse>

class Greeter {
public:
    Greeter(const std::string& message);
    void greet();

private:
    std::string message_;
};

class Laplace {
    public:
    void init(double Lx_, double Ly_, double nx_, double ny_);
    void assembly();
    void boundary(double d1, double d2, double n1, double n2);
    void solve();
    void show();

    private:
        double Lx;
        double Ly;
        int nx;
        int ny;
        double dx;
        double dy;
        std::vector<Eigen::Triplet<double>> tripletVec_M;
        std::vector<Eigen::Triplet<double>> tripletVec_b;
        Eigen::VectorXd x;
};

#endif // LAPLACE_H
