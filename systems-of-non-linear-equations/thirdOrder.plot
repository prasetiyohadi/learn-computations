#!/usr/bin/env gnuplot
set terminal postscript
set output 'thirdOrder.eps'

set xlabel 'x'

set autoscale

set ylabel 'f(x)'
set format y '%8.2f'

set title 'f(x) by x graph'
set key reverse bottom left inside
set grid
set xzeroaxis lt 3 lw 2

set style data linespoints

plot 'thirdOrder.dat' using 1:2 title 'f(x)' with lines
