#include "Poisson.h"
#include <vector>

Poisson::Poisson(const std::string& path){

    node_path = path;

    dx = dy = 0;
    Lx = Ly = 0;


}
