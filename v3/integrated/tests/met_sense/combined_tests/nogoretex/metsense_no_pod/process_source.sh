#!/bin/bash
./clean_file.sh "$1"
./time_gen.sh
cat cleaned_file.txt | cut -d " " -f 2 | sort | uniq | grep [a-z] | xargs -n 1 ./create_files.sh
echo "------------------------"
ls *.txt | xargs -n 1 wc -l
echo "------------------------"
