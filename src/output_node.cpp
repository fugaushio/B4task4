#include "Poisson.h"
#include <iostream>
#include <fstream>
#include <sstream>
    
void Poisson::output_node() {
    // 確認用出力
    std::cout << "読み込んだノード数: " << nodes.size() << std::endl;
    for (const auto& node : nodes) {
        std::cout << "(" << node.first << ", " << node.second << ")\n";
    }
}    
    