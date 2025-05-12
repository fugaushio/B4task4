#ifndef POISSON_SOLVER_H
#define POISSON_SOLVER_H

#include <vector>
#include <string>

class PoissonSolver {
public:
    PoissonSolver(const std::string& filename);
    void solve();
    void outputResult(const std::string& filename) const;

private:
    struct Node {
        double x, y;
        bool isBoundaryBottom, isBoundaryTop;
    };

    std::vector<Node> nodes;
    std::vector<double> values;

    void loadNodes(const std::string& filename);
    void applyBoundaryConditions();
    void constructAndSolveSystem();
};

#endif // POISSON_SOLVER_H
