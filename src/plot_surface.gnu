set terminal pngcairo size 800,600
set output 'surface.png'

set title "Laplace Equation Solution (3D Surface)"
set xlabel "x"
set ylabel "y"
set zlabel "phi"
set ticslevel 0
set hidden3d
set view 60, 30

splot 'solution.dat' using 1:2:3 with lines palette notitle
