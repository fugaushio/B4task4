#ifndef POISSONSOLVER_H
#define POISSONSOLVER_H

#include <string>
#include <vector>

struct Node {
    double x, y;
    bool isBoundaryTop = false;
    bool isBoundaryBottom = false;
    bool isBoundaryLeft = false;
    bool isBoundaryRight = false;
};

class PoissonSolver {
public:
    PoissonSolver(const std::string& filename);
    void solve();
    void outputResult(const std::string& filename) const;

private:
    void loadNodes(const std::string& filename);
    void applyBoundaryConditions();
    void constructAndSolveSystem();

    std::vector<Node> nodes;
    std::vector<double> values;

    int nx;
    int ny;
};

#endif // POISSONSOLVER_H
