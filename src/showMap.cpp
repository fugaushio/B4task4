#include "Poisson.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio> 

void Poisson::showMap() {

    int Nx = Lx / dx + 1;
    int Ny = Ly / dy + 1;

    std::ofstream fout("../src/phi.dat");

    for (int col = 0; col < Nx; ++col) {
        double x = col * dx;
        for (int row = 0; row < Ny; ++row) {
            double y = row * dy;
            double val = Phi[col * Nx + row];
            fout << x << " " << y << " " << val << "\n";
        }
    fout << "\n";  
    }
    fout.close();



    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");  

    if (!gnuplotPipe) {
        std::cerr << "gnuplot を開けませんでした。" << std::endl;
        return;
    }

    fprintf(gnuplotPipe, "set terminal pngcairo size 800,600\n");
    fprintf(gnuplotPipe, "set output '../src/phi.png'\n");

    fprintf(gnuplotPipe, "set terminal wxt font 'Arial,10'\n");
    fprintf(gnuplotPipe, "set title 'heatmap'\n");
    fprintf(gnuplotPipe, "set view map\n");

    fprintf(gnuplotPipe, "set pm3d interpolate 10,10\n");
    fprintf(gnuplotPipe, "set xrange [0:%f]\n", Lx);
    fprintf(gnuplotPipe, "set yrange [0:%f]\n", Ly); 
    fprintf(gnuplotPipe, "set view 0,0\n"); 
    fprintf(gnuplotPipe, "set palette defined (0 'blue', 1 'white', 2 'red')\n");

    fprintf(gnuplotPipe, "splot '../src/phi.dat' using 1:2:3 with pm3d notitle\n");
    

    fprintf(gnuplotPipe, "unset output\n");

    fflush(gnuplotPipe);
    pclose(gnuplotPipe); 

    


}