set terminal pngcairo size 800,600
set output 'contour.png'

set title "Laplace Equation Solution (Contour)"
set xlabel "x"
set ylabel "y"
set zlabel "phi"

set view map
set pm3d at b
set palette rgb 33,13,10
set colorbox
set contour base
unset surface

splot 'solution.dat' using 1:2:3 with lines notitle
