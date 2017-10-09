The scripts in this directory can be used to create sensor reports for nodes - 
The scripts in this directory need gnuplot for plotting data. 

Usage: 

$./report part_of_nodeid last_day how_many_days 

For example, to get reports on node 0000001E061130FE for 4 days excluding today, 

$./report 30FE 0 4

This will generate a report for each sensor under the plotfolder. The files are named 
based on VSN node_id start_time end_time and parameter. 

For the same node the report for a week ending yesterday can be generated using - 

$./report 30FE 1 7

To clean the directories: 

$./clean

This will delete all the generated files. 

