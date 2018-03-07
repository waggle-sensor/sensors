#!/bin/bash
if [ "$#" -ne 3 ]; then
   echo "Not enough information provided..."
   exit 1
fi
base_dir=$(dirname ${BASH_SOURCE[0]})
rm ${base_dir}/sensor_data_set*.csv
${base_dir}/getdatasets $1 $2 $3
cp sensor_data_set.csv sensor_data_set_orig.csv
python3 ${base_dir}/beehive_csv.py
