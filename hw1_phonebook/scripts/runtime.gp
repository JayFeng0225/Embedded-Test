reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.100]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.1):($2+0.002):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'struct optimized'  , \
'' using ($0+0.05):($3+0.002):3 with labels title ' ', \
'' using 4:xtic(1) with histogram title 'hash function'  , \
'' using ($0+0.3):($4+0.002):4 with labels title ' ', \

