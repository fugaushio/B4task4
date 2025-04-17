#include "Poisson.h"
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

void  Poisson::analyze_node() {

    std::set<double> x_set, y_set;

    for (const auto& node : nodes) {
        x_set.insert(node.first);   // x座標
        y_set.insert(node.second);  // y座標
    }
    
    std::vector<double> x_vals(x_set.begin(), x_set.end());//vector型に変換
    std::vector<double> y_vals(y_set.begin(), y_set.end());

    dx = (x_vals.size() > 1) ? (x_vals[1] - x_vals[0]) : 0;
    dy = (y_vals.size() > 1) ? (y_vals[1] - y_vals[0]) : 0;

    Lx = x_vals.back() - x_vals.front();
    Ly = y_vals.back() - y_vals.front();

}
