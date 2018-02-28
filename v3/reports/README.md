## Documentation:

The bash shell scripts (for Linux or Mac OS X) in this directory can be used to create sensor reports in the form of graphs in 
PDF format for nodes. The scripts in this directory depend on **Python 3.0**, **wget**, **gunzip**, **numpy** and **math** python libraries and **gnuplot** for downloading, extracting, converting and plotting data. Please make sure they are installed in the system where they are intended to be used. 

The Python scripts in this directory can be used independently to convert raw sensor data in csv files to values in parameter specific 
units. They can take raw data CSV files available at [Beehive Portal](http://beehive1.mcs.anl.gov/) and create CSV files with converted data. The final data incorporates all conversions, scaling and other corrections (temperature, cross-sensitivity etc. if any) currently available for the set of sensors. 


## 1. Generating Graph Reports:

### Usage: 

`$./report part_of_nodeid last_day how_many_days`

Node IDs can be obtained from the [Beehive Portal](http://beehive1.mcs.anl.gov/).

For example, to get reports on node **001E061130FE** for 5 days ending today, 

`$./report 30FE 0 4`

This will generate a report for each sensor in the plot folder. The files are named 
based on VSN start_time end_time and parameter. 

For the same node the report for a week ending yesterday can be generated using - 

`$./report 30FE 1 6`

## 2. Generating Processed Sensor CSV files:

### Usage: 

The `create_converted_dataset.sh` has to set as executable.

`$./create_converted_dataset.sh last_day how_many_days`

Node IDs can be obtained from the [Beehive Portal](http://beehive1.mcs.anl.gov/).

For example, to generated converted data-sets for node **001E061130FE** for 5 days ending today, 

`$./create_converted_dataset.sh 30FE 0 4`

This will generate a CSV file `sensor_data_set_converted.csv` for the node in the base directory. 

For the same node the report for a week ending yesterday can be generated using - 

`$./create_converted_dataset.sh 30FE 1 6`


## 3 . Cleaning Directory:

To clean the directories, and start over: 

`$./clean`

This will delete all the generated files. 







