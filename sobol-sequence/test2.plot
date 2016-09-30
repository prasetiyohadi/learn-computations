#!/usr/bin/env gnuplot
#set terminal postscript
#set output 'test2.eps'
set terminal pngcairo
set output 'test2.png'

set xlabel 'y1'
set format x '%2.2f'
set ylabel 'y2'
set format y '%2.2f'
set grid x y

set title '2-dimensional pseudorandom'
set key right bmargin Left box 3

plot  'test2.dat' using 1:2 title 'y'  with points lt 1 pt 2
