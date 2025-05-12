#include "PoissonSolver.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>

PoissonSolver::PoissonSolver(const std::string& filename) {
    loadNodes(filename);
    applyBoundaryConditions();
}

void PoissonSolver::loadNodes(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Cannot open node file: " << filename << std::endl;
        exit(1);
    }

    double x, y;
    while (infile >> x >> y) {
        Node node;
        node.x = x;
        node.y = y;
        node.isBoundaryBottom = (std::abs(y) < 1e-6);
        node.isBoundaryTop = (std::abs(y - 1.0) < 1e-6);
        nodes.push_back(node);
    }

    values.resize(nodes.size(), 0.0);
}

void PoissonSolver::applyBoundaryConditions() {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].isBoundaryBottom) {
            values[i] = 0.0;
        } else if (nodes[i].isBoundaryTop) {
            values[i] = 1.0;
        }
    }
}

// 近傍ノードかどうか（グリッド間隔が約0.05〜0.1と仮定）
bool PoissonSolver::isNeighbor(const Node& a, const Node& b, double h) {
    double dx = std::abs(a.x - b.x);
    double dy = std::abs(a.y - b.y);
    return (dx + dy) < (h + 1e-6) && std::abs(dx * dy) < 1e-6; // 直交隣接（上下左右のみ）
}

void PoissonSolver::constructAndSolveSystem() {
    const int maxIter = 10000;
    const double tol = 1e-6;
    const double h = 0.05; // メッシュ間隔の近似値（調整可能）

    std::vector<double> newValues = values;

    for (int iter = 0; iter < maxIter; ++iter) {
        double maxDiff = 0.0;

        for (size_t i = 0; i < nodes.size(); ++i) {
            if (nodes[i].isBoundaryBottom || nodes[i].isBoundaryTop)
                continue;  // Dirichlet境界は固定

            double sum = 0.0;
            int count = 0;

            for (size_t j = 0; j < nodes.size(); ++j) {
                if (i == j) continue;
                if (isNeighbor(nodes[i], nodes[j], h)) {
                    sum += values[j];
                    ++count;
                }
            }

            if (count > 0) {
                newValues[i] = sum / count;
                maxDiff = std::max(maxDiff, std::abs(newValues[i] - values[i]));
            }
        }

        values = newValues;

        if (maxDiff < tol) break;
    }
}

void PoissonSolver::solve() {
    constructAndSolveSystem();
}

void PoissonSolver::outputResult(const std::string& filename) const {
    std::ofstream out(filename);
    for (size_t i = 0; i < nodes.size(); ++i) {
        out << nodes[i].x << " " << nodes[i].y << " " << values[i] << "\n";
    }
}
