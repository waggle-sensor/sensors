set terminal pdf size 17in, 11in font "Helvetica,30"
set output './plots/008-2018_02_20_00:00:12-2018_02_21_17:15:30-HTU21D-temperature.pdf'
set title " 008 | AoT Denver (S) | Denver "
set tics font "Helvetica,25"
set xlabel 'Time (UTC)'
set ylabel 'deg C'
set datafile separator ';'
set timefmt '%Y_%m_%d_%H:%M:%S'
set xdata time
set format x "%H.%M\n%m/%d"
set autoscale
set tics
set grid
plot './data_files/HTU21D-temperature.csv' using 1:2 with lines title 'Temperature by sensor HTU21D'
