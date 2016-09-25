#!/usr/bin/env gnuplot
set terminal postscript
set output 'secondOrder.eps'

set xlabel 'x'
set xrange [-2:2]

set autoscale

set ylabel 'f(x)'
set format y '%8.2f'
set yrange[-10:10]

set title 'f(x) by x graph'
set key reverse bottom left inside
set grid
set xzeroaxis lt 3 lw 2
set yzeroaxis lt 3 lw 2

set style data linespoints

plot  'secondOrder.dat' using 1:2 title 'f1(x)' with lines lt 1, \
      'secondOrder.dat' using 1:3 title 'f2(x)' with lines lt 2, \
      'secondOrder.dat' using 1:4 title 'f2(x)' with lines lt 2
