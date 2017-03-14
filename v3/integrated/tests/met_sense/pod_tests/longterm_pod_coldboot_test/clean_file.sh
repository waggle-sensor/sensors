#!/bin/bash
cat $1 | head -n -$2  | tail -n +$3  >  cleaned_file.txt
