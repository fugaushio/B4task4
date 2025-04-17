#include "Poisson.h"
#include <iostream>
#include <fstream>
#include <sstream>


void Poisson::read_node() {
    
    std::ifstream ifs(node_path);
    if (!ifs.is_open()) {
        std::cerr << "ファイルを開けませんでした: " << node_path << std::endl;
        return;
    }

    std::string line;

    while (std::getline(ifs, line)) {

        std::istringstream iss(line);
        double x, y;

        if (!(iss  >> x >> y)) {
            std::cerr << "フォーマットエラー: " << line << std::endl;
            continue;
        }

        nodes.push_back({x, y});//nodeのxy座標情報をnodesに格納
    }
}

