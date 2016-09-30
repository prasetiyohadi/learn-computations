#!/usr/bin/env gnuplot
#set terminal postscript
#set output 'test.eps'
set terminal pngcairo
set output 'test.png'

set xlabel 'x1'
set format x '%2.2f'
set ylabel 'x2'
set format y '%2.2f'
set grid x y

set title '2-dimensional sobol sequence'
set key right bmargin Left box 3

plot  'test.dat' using 1:2 title 'x'  with points lt 1 pt 1
