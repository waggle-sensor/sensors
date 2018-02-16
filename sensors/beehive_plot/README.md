# How to excute:
```
python3 beehive_csv.py -n nodeID -ds start -de end

nodeID: last four digit of node id
start: 0 means collect data from today (0 day before today)
end: 1 means collect data to yesterday (1 day before today)

other options:
--t: to plot only temperature data
--h: to plot only humidity data
--p: to plot only pressure data
```

If you do not put option --t, --h, or --p, then the code will plot all three data. The plots are stored as png files.
The plots are time-data graph, and if you put multiple node ids, then the parameters 
(temperature, humidity, and pressure) in all nodes will be plotted in one graph.
If you just excute ```python3 beehive_csv.py``` then all live nodes will be shown as a result.
