set terminal pngcairo size 800,600 enhanced
set output 'heatmap2.png'
set pm3d map
set palette rgbformulae 33,13,10
set xlabel 'X'
set ylabel 'Y'
splot 'grid_data2.dat' using 1:2:3 with pm3d notitle
