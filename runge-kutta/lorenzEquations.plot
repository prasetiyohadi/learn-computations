#!/usr/bin/env gnuplot
#set terminal postscript
#set output 'lorenzEquations.eps'
set terminal pngcairo size 1024,768 font "Liberation Serif, 14"
set output 'lorenzEquations.png'

set xlabel 'x'
set format x '%2.2f'
set xtics out offset -1.5,0
set ylabel 'y'
set format y '%2.2f'
set ytics out offset 2.0,-0.05
set zlabel 'z'
set format z '%2.2f'
set ztics out offset 1.5,0

set grid
set hidden3d

set title 'Lorenz Equations using paremeters: SIGMA = 10.0, RHO = 28, BETA = 8/3' offset 0,-3
unset key

splot  'lorenzEquations.dat' notitle  with lines
