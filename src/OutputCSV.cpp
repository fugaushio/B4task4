#include "OutputCSV.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void OutputCSV::output(const std::vector<double>& x, const std::string& filename){

    std::ofstream file(filename);
    
    if(!file){
        std::cerr << "Cannot open the file" << filename << std::endl;
        return;
    }

    for (double val : x) {
        file << val << "\n";
    }

    file.close();
}