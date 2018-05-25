#!/bin/bash

cat cleaned_file.txt | grep "M_HTU21D_Temp:" | cut -d " " -f 1  > times.txt
howmany=$(cat times.txt | wc -l)
what=$(head -1 times.txt)

for (( c=1; c<=$howmany; c++ ))
do  
    echo $what >> time_origin.txt
done

paste times.txt -d- time_origin.txt | bc > time.txt
rm times.txt time_origin.txt

