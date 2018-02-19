## Documentation:

The bash shell scripts (for Linux or Mac OS X) in this directory can be used to create sensor reports in PDF for nodes - 
The scripts in this directory depend on **wget**, **gunzip** and **gnuplot** for downloading, extracting and plotting data. 
Please make sure they are installed in the system where they are intended to be used. 

The python scripts for Linix and Mac in this directory can be used to convert sensor data in csv files to representative unit values. The scripts in this directory depends on **numpy** and **math** python libraries, and also the scripts requires a **sensor_data_set.csv** file which can be downloaed from beehive server and **calib_data.csv** file which is modified an xlsx file provided by spec.

### Usage: 

`$./report part_of_nodeid last_day how_many_days`

Node IDs can be obtained from the [Beehive Portal](http://beehive1.mcs.anl.gov/).

For example, to get reports on node **001E061130FE** for 5 days ending today, 

`$./report 30FE 0 4`

This will generate a report for each sensor in the plot folder. The files are named 
based on VSN start_time end_time and parameter. 

For the same node the report for a week ending yesterday can be generated using - 

`$./report 30FE 1 6`

To clean the directories: 

`$./clean`

This will delete all the generated files. 

