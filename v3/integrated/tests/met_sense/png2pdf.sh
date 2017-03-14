#!/bin/bash
echo $1
b=$(echo $1 | sed 's/.png/.pdf/g')
convert $1 $b