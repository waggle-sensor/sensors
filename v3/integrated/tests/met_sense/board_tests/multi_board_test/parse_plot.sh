#!/bin/bash
echo "Splitting files into sensor files."
while read p; do
    if [ "$(echo $p | head -c 1)" != "%" ]
    then
        echo  "Processing...  "$p
        
        if [ "$1" == "all" ]
        then
            for i in dev*.txt; do
                cat $i | grep $p | tr -s " " | cut -d " " -f 1,6- > "${i%%.*}"_$p.ts
            done
        
        else
                howmuch=$(echo "$1*60*2" | bc)
                for i in dev*.txt; do
                    cat $i | grep $p | tr -s " " | cut -d " " -f 1,6- | tail -$howmuch > "${i%%.*}"_$p.ts
                done
        fi
        
        echo 'filenames = "dev0  dev1  dev2  dev3  dev4  dev6"' > graph.plot
#         echo 'filenames = "dev0  dev1  dev2  dev3  dev4  dev5  dev6"' > graph.plot
        echo 'set terminal pdf' >> graph.plot
        echo 'WHICH = "'$p'"' >> graph.plot
        echo 'set output WHICH.".pdf"' >> graph.plot
        echo 'set xlabel "Time --> "' >> graph.plot
        echo 'set ylabel "Measurement Value"' >> graph.plot
        echo 'set grid' >> graph.plot
        echo 'set tics scale 0' >> graph.plot
        echo 'unset xtics' >> graph.plot
        echo 'set xtics format " "' >> graph.plot
        echo 'check_valid_column(c) = valid(c) ? check_valid_column(c + 1) : c - 1' >> graph.plot
        echo 'stats "dev0_".WHICH.".ts" using (check_valid_column(1)) nooutput' >> graph.plot
        echo 'last_column = int(STATS_max)' >> graph.plot
        echo 'plot for [file in filenames] file."_".WHICH.".ts" using 1:last_column title file with lines smooth sbezier' >> graph.plot
        gnuplot graph.plot
    fi
done < sensors.txt
# rm graph.plot
#rm *.ts
