#!/usr/bin/env gnuplot
set terminal postscript
set output 'spiralOptimization2d.eps'
#set terminal pngcairo
#set output 'spiralOptimization2d.png'

set xlabel 'x1'
set format x '%2.2f'
set ylabel 'x2'
set format y '%2.2f'
set grid x y

set title '2-dimensional spiral dynamics'
#set key right bmargin Left box 3
set key right bottom Left box 3

plot 'spiralOptimization2d.dat' using 1:2 title 'x1'  with points lt 1 pt 1,
#  'spiralOptimization2d.dat' using 3:4 title 'x2'  with linespoints lt 2 pt 1, \
#  'spiralOptimization2d.dat' using 5:6 title 'x3'  with linespoints lt 3 pt 1, \
#  'spiralOptimization2d.dat' using 7:8 title 'x4'  with linespoints lt 4 pt 1, \
#  'spiralOptimization2d.dat' using 9:10 title 'x5'  with linespoints lt 5 pt 1
