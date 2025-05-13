#include <iostream>
#include "Greeter.h"
#include "PoissonSolver.h"

int main() {
    Greeter greeter("Solving Poisson Equation...");
    greeter.greet();

    PoissonSolver solver("Input/node.dat");
    solver.solve();
    solver.outputResult("solution2.dat");

    std::cout << "Solution written to solution2.dat\n";
    return 0;
}
