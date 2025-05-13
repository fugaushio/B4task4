#include "PoissonSolver.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <map>

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
        node.isBoundaryBottom = (std::abs(y - 0.0) < 1e-6);
        node.isBoundaryTop = (std::abs(y - 0.09) < 1e-6);
        node.isBoundaryLeft = (std::abs(x - 0.0) < 1e-6);
        node.isBoundaryRight = (std::abs(x - 0.09) < 1e-6);
        nodes.push_back(node);
    }

    values.resize(nodes.size(), 0.0);

    // 格子のインデックス構築
    int nx = 0, ny = 0;
    for (const auto& node : nodes) {
        if (std::abs(node.y - 0.0) < 1e-6) ++nx;
        if (std::abs(node.x - 0.0) < 1e-6) ++ny;
    }
    this->nx = nx;
    this->ny = ny;
}

void PoissonSolver::applyBoundaryConditions() {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].isBoundaryBottom) {
            values[i] = 0.0; // φ = 0
        } else if (nodes[i].isBoundaryTop) {
            values[i] = 1.0; // φ = 1
        }
    }
}

void PoissonSolver::constructAndSolveSystem() {
    const int maxIter = 10000;
    const double tol = 1e-6;
    std::vector<double> newValues = values;

    for (int iter = 0; iter < maxIter; ++iter) {
        double maxDiff = 0.0;

        for (int j = 1; j < ny - 1; ++j) {
            for (int i = 1; i < nx - 1; ++i) {
                int idx = j * nx + i;

                if (nodes[idx].isBoundaryBottom || nodes[idx].isBoundaryTop) continue;

                int idxL = j * nx + (i - 1);
                int idxR = j * nx + (i + 1);
                int idxB = (j - 1) * nx + i;
                int idxT = (j + 1) * nx + i;

                // Neumann条件（∂φ/∂x = 0）を模倣（左右端の場合）
                if (nodes[idx].isBoundaryLeft) idxL = idxR;
                if (nodes[idx].isBoundaryRight) idxR = idxL;

                double average = 0.25 * (values[idxL] + values[idxR] + values[idxB] + values[idxT]);
                maxDiff = std::max(maxDiff, std::abs(values[idx] - average));
                newValues[idx] = average;
            }
        }

        values = newValues;

        if (maxDiff < tol) {
            std::cout << "Converged after " << iter << " iterations.\n";
            break;
        }
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
