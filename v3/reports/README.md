## Documentation:

The scripts in this directory can be used to create sensor reports in PDF for nodes - 
The scripts in this directory need **gunzip** and **gnuplot** for extracting and plotting data. 

### Usage: 

`$./report part_of_nodeid last_day how_many_days`

Node IDs can be obtained from the [Beehive Portal](http://beehive1.mcs.anl.gov/).

For example, to get reports on node **001E061130FE** for 4 days excluding today, 

`$./report 30FE 0 4`

This will generate a report for each sensor in the plot folder. The files are named 
based on VSN start_time end_time and parameter. 

For the same node the report for a week ending yesterday can be generated using - 

`$./report 30FE 1 7`

To clean the directories: 

`$./clean`

This will delete all the generated files. 

