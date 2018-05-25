#!/bin/bash
./clean_file.sh "$1"
./time_gen.sh

cat cleaned_file.txt | tr -s " " | cut -d " " -f 2 | sort | uniq | grep -i [a-z] | xargs -n 1 ./create_files.sh
echo "------------------------"
ls *.txt | xargs -n 1 wc -l
echo "------------------------"
rm cleaned_file.txt
