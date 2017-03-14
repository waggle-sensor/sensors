#!/bin/bash
counter=0
end_slice=50

while IFS='' read -r line || [[ -n "$line" ]]; do
    word=$(echo $line | wc -w)
    counter=$((counter + 1))
    if [ "$word" -eq "1" ]; then 
        head_pos=$counter
        break
    fi
done < "$1"

tail -$end_slice "$1"  > temp_file.del
counter=0

while IFS='' read -r line || [[ -n "$line" ]]; do
    word=$(echo $line | wc -w)
    counter=$((counter + 1))
    if [ "$word" -eq "1" ]; then 
        tail_pos=$counter
    fi
done < "temp_file.del"

tail_pos=$(($end_slice - tail_pos))

# echo "$1"
# echo $head_pos
# echo $tail_pos
rm temp_file.del
cat $1 | head -n -$tail_pos  | tail -n +$head_pos  >  cleaned_file.txt
