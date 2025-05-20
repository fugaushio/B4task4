#include <iostream>
#include <vector>
#include "Gauss.h"
#include "OutputCSV.h"
#include "Matrix.h"

using namespace std;  // ← 追加（std:: を省略可能に）

int main() {
    int N = 100;

    vector<double> x(N);
    vector<double> b(N);
    vector<vector<double>> A(N, vector<double>(N));

    Matrix::matrix(A, b);
    GaussE::gausse(A, x, b);
    OutputCSV::output(x, "result.csv");

    return 0;
}