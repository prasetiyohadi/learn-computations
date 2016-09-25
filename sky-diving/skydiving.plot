#!/usr/bin/env gnuplot
set terminal postscript
set output 'skydiving.eps'

set xlabel 'time'
set ylabel 'height'
set y2label 'velocity'
set format y '%8.2f'
set format y2 '%8.2f'
set ytics nomirror
set y2tics
set tics out
set grid x y
set autoscale y
set autoscale y2

set title 'height vs time graphic for sky diving dynamic'
set key reverse top right inside

plot  'skydiving.dat' using 1:2 title 'position' with lines lt 1 axes x1y1, \
      'skydiving.dat' using 1:3 title 'velocity' with lines lt 2 axes x2y2
