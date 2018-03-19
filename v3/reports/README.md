## Overview:

Several sensors measuring a range of values from TPH to concentrations of several gases and particulate matter are 
installed in a Waggle/AoT node. The various details including links to the datasheets for the sensors are available in 
the [README](https://github.com/waggle-sensor/sensors) file in the sensors repo. 

### Here are some caveats while using these graphs toward understanding the environment: 

1. The sensors in the [Metsense](https://github.com/waggle-sensor/sensors#metsense-hw-ver-31) are exposed 
to the air in the external environment, and are shielded by a Stevenson shield. 

2. The sensors in the [Lightsense](https://github.com/waggle-sensor/sensors#lightsense-hw-ver-31) are 
exposed only to external light, through a glass window. They are not exposed to the external air. 

3. The sensors in the [Chemsense](https://github.com/waggle-sensor/sensors#chemsense-hw-ver-passamaquoddy-bay) 
 are exposed to the air in the external environment, and are shielded by a Stevenson shield. 

4. The [OPC-N2](https://github.com/waggle-sensor/sensors#alphasense-opc-n2-regular-range-16-bins-in-0-10-%CE%BCm-and-high-rangepollen-16-bins-in-0-40-%CE%BCm) sensor is exposed to the air in the external environment, and is shielded by a Stevenson shield.


### What sensors should I use?

    - Temperature: TSYS01 or HTU21D
    - Humidity: HTU21D
    - Pressure: BMP180
    - Acceleration: MMA8452Q
    - Magnetic Field: HMC5883L


## Documentation:

The bash shell scripts (for Linux or Mac OS X) in this directory can be used to create [sensor reports](https://github.com/waggle-sensor/sensors/blob/develop/v3/reports/README.md#1-generating-graph-reports)  in the form of graphs in
PDF format for nodes. The scripts in this directory depend on **Python 3 + numpy** and **wget**, **gunzip**, and **gnuplot** for downloading, extracting, converting and plotting data. Please make sure they are installed in the system where they are intended to be used. 

The Python scripts in this directory can be used independently to [convert raw sensor data](https://github.com/waggle-sensor/sensors/blob/develop/v3/reports/README.md#2-generating-processed-sensor-csv-files) in csv files to values in parameter specific
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

`$./create_converted_dataset.sh part_of_nodeid last_day how_many_days`

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
