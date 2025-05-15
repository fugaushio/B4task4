set terminal pngcairo size 600,500
set output 'y_vs_phi.png'
set xlabel "y"
set ylabel "φ"
set title "φ vs y at x = 0.05"
set grid
plot 'y_vs_phi.dat' using 1:2 with linespoints lt rgb "blue" pointtype 7 title "φ(y)"
