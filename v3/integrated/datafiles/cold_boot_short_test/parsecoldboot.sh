#!/bin/bash

# cat data_cold_boot.txt | cut -d " " -f 2 | sort | uniq | grep [a-z]

cat data_cold_boot.txt | grep $1 | cut -d " " -f 3 > $1.txt
# 
# for (( c=1; c<=654; c++ ))
# do  
#    echo "1488842114"
# done



