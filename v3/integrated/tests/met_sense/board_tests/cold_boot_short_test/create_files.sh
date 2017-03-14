#!/bin/bash

# cat cleaned_file.txt | cut -d " " -f 2 | sort | uniq | grep [a-z]

file_name=$(echo $1 | sed 's/://g')
cat cleaned_file.txt | grep $1 | cut -d " " -f 3 > $file_name.txt


