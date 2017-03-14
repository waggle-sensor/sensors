#!/bin/bash

file_name=$(echo $1 | sed 's/://g')
cat cleaned_file.txt | grep $1 | cut -d " " -f 3 > $file_name.txt


