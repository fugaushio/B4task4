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

void PoissonSolver::constructAndSolveSystem() {
    // 簡易なラプラス反復法（ガウス・ザイデル）で例示
    const int maxIter = 10000;
    const double tol = 1e-6;
    std::vector<double> newValues = values;

    for (int iter = 0; iter < maxIter; ++iter) {
        double maxDiff = 0.0;

        for (size_t i = 1; i < nodes.size() - 1; ++i) {
            if (nodes[i].isBoundaryBottom || nodes[i].isBoundaryTop) continue;

            double sum = 0.0;
            int count = 0;

            // 単純な隣接ノードの平均（ここでは簡易な差分法の近似）
            if (i > 0) {
                sum += values[i - 1];
                ++count;
            }
            if (i + 1 < nodes.size()) {
                sum += values[i + 1];
                ++count;
            }

            newValues[i] = sum / count;
            maxDiff = std::max(maxDiff, std::abs(newValues[i] - values[i]));
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
