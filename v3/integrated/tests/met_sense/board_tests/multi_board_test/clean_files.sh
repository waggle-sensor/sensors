#!/bin/bash
echo "Pruning files..."
for i in dev*.txt; do
        head -n -1 $i > tmp.txt && mv tmp.txt $i
done