#ifndef POISSONSOLVER_H
#define POISSONSOLVER_H

#include <vector>
#include <string>

struct Node {
    double x, y;
    bool isBoundaryBottom = false;
    bool isBoundaryTop = false;
};

class PoissonSolver {
public:
    PoissonSolver(const std::string& filename);
    void solve();
    void outputResult(const std::string& filename) const;

private:
    std::vector<Node> nodes;
    std::vector<double> values;

    void loadNodes(const std::string& filename);
    void applyBoundaryConditions();
    void constructAndSolveSystem();
    bool isNeighbor(const Node& a, const Node& b, double h = 0.05);
};

#endif // POISSONSOLVER_H
