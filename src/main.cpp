#include <iostream>
#include "Laplace.h"
#include "Fem.h"

int main() {
    // Laplace laplace;
    // laplace.init(1, 1, 100, 100);
    // laplace.assembly();
    // laplace.boundary(0, 1e0, 0, 0);
    // laplace.solve();
    // std::cout << "solved" << std::endl;
    // laplace.show();
    Fem fem;
    fem.load("Input/node.dat", "Input/element.dat");
    fem.organize_quad();
    fem.assembly();
    fem.boundary();
    fem.solve();
    fem.show();
}
