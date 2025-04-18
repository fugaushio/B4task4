#include <iostream>
#include "Poisson.h"

void  Poisson::poisson() {//メンバ関数をまとめた

    this->read_node();
    this->analyze_node();
    this->makeMatrix();
    this->solver();
    //this->output_phi();
    this->showMap();

}