#!/usr/bin/env gnuplot
#set terminal postscript
#set output 'MidTerm5_20915301_PrasetiyoHadiPurwoko.eps'
set terminal pngcairo size 1024,768 font "Liberation Serif, 14"
set output 'MidTerm5_20915301_PrasetiyoHadiPurwoko.png'

set xlabel 'P'
set format x '%2.2f'
set ylabel 'Q'
set format y '%2.2f'

set grid
set hidden3d

set title 'Predator (Q) and Prey (P) Interaction using RK4' offset 0,-3
unset key

plot 'MidTerm5_20915301_PrasetiyoHadiPurwoko.out' notitle with lines
