filenames = "dev0  dev1  dev2  dev3  dev4  dev6"
set terminal pdf
WHICH = "TMP421"
set output WHICH.".pdf"
set xlabel "Time --> "
set ylabel "Measurement Value"
set grid
set tics scale 0
unset xtics
set xtics format " "
check_valid_column(c) = valid(c) ? check_valid_column(c + 1) : c - 1
stats "dev0_".WHICH.".ts" using (check_valid_column(1)) nooutput
last_column = int(STATS_max)
plot for [file in filenames] file."_".WHICH.".ts" using 1:last_column title file with lines smooth sbezier
