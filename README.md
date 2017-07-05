# Firmware v4

Simple explanation of talker and firmware is given along with sample commands to get sensor data from coresense boards and sensors.

## Firmware
This firmware is based on C language. main.ino basically follows ardunio C language, and others follow C.

In the firmware, sensors have each of sensor ID:
```
<sensor name>     <sensor ID>
   mac               0x00
   tmp112            0x01
   htu21d            0x02
   bmp180            0x03
   pr103j2           0x04
   tsl250            0x05
   mma8452q          0x06
   spv1840           0x07
   tsys01            0x08
   met               0x0F
   hmc5883l          0x10
   hih6130           0x11
   apds9006          0x12
   tsl260rd          0x13
   tsl250rd          0x14
   mlx75305          0x15
   ml8511            0x16
   tmp421            0x17
   light             0x1F
   chem              0x20
   alpha             0x40
```
If an ID is smaller than 0x10, the sensor is on a metsense boards, and if an ID is smaller than 0x20 but greater than 0x0F, the sensor is on a lightsense board.

As a sensor name, mac means mac address for all coresense boards and chemsense board. So when the user wants to know all the mac addresses, the user can use "mac" as a key word.

"chem" is also a key word to get a data line. A chemsense board sends a data line every second, containing multiple sensor values. According to the document which is given by the company designed chemsense, the chemsense will send five data lines in five seconds, but three data lines are given for now. Chemsense does not send any data for following two seconds. 

"alpha" is a key word to send command to alpha sensor. A following key words or commands are necessary, and these have  to be given through talker.py, coresense plug in or any of equivalent script. Detailed commands are described below.

Libraries for I2C sensors on boards are in folder "lib". All the data collection is performed through met.cpp, light.cpp, chem.cpp, or spi.cpp, which are in each of folders respectively.

To flash new Firmware, do:
```
platformio run -t upload
```
Or just to compile your code, do:
```
platformio run
```
To perform the two commands above, you need to install "platformio" on your laptop/device.


## Talker
These python script are a method to communicate with coresense boards. Basically, the coresense boards send binary data through serial, and the talker trasnforms the data into human readable forms.

"talker.py" is the main script, and other python scripts work to convert raw data into human understandable value.

### To start talker.py

To start talker.py, do:
```
python3 talker.py <port name>
```
<port name> means the name of port which coresense boards are connected.
For example,
```
python3 talker.py /dev/ttyACM0
```

### Commands
There are four primary commands as following. 
```
ver       requests coresense firmware version
id        requests id of the node
2write    change variables such as mac address of Metsense boards
2read     request data from each sensor boards and sensors
```
Two of the primary commands requires secondary commands, which are "2write" and "2read".
When you send commands, do not send multiple primary commands in one line, especially 2write and 2read.
Detailed examples will be given below.


### To request data from coresense boards, use command <2read>:

To read data from sensor borads, you need to send secondary command(s) along with the primary command "2read".
Secondary commands are following:
```
<secondary>       <data type>
  met             all the sensor data from Metsense board
  tmp112          temperature
  htu21d          temperature & humidity
  bmp180          temperature & pressure
  pr103j2         temperature
  tsl250          light
  mma8452q        accelerate force
  spv1840         sound
  tsys01          temperature
  
  light           all the sensor data from Lightsense board
  hmc5883l        magenetic field
  hih6130         temperature 
  apds9006        light
  tsl260rd        light
  tsl250rd        light
  mlx75305        light
  ml8511          light
  tmp421          temperature
  
  chem            one data line from Chemsense board
  
  alpha           <need third command for alpha>
```

To collect data from an alpha sensor, you need to send a third command, which are:
```
  <thrid>               <data type>
  power_on              power on the alpha sensor
  power_off             power off the alpha sensor
  serial                collect serial number of the alpha sensor
  version               collect firmware version of the alpha sensor
  config                collect configuration of the alpha sensor
  histogram             collect particle data
  fan_power <power>     change fan power to <power>
  laser_power <power>   change laser power to <power>

  * <power> is an integer number indicates power in range of 0 to 255
```

#### Examples 
To get data, use:
```
2read <secondary key/keys>
```
For example,
```
2read met
```
or 
```
2read BMP180
```
or 
```
2read alpha power_on
2read alpha config
2read alpha histogram
```

To get all sensor values from a metsense board, lightsense board or chemsense boards, use "met", "light", or "chem" respectively.
Only to get mac addresses, use "mac".
You can request data from coresense boards, which are Metsense/Lightsense/Chemsense boards and mac addresses together, for example:
```
2read met light chem mac
```
However you cannot combine/mix commands with alpha sensor. For example:
```
2read met alpha power_on light
```

#### Caution
* After you power on the alpha sensor, you'd better wait about 5 second to get data. If not, the values from alpha sensor are not correct values but some nonsenses.
* Alphasense company recommand to not change laser power because it is adjusted for each sensor after calibration.


### To write new mac address for Coresense boards

You can change mac address for metsense/lightsense board:
```
2write mac <mac address>
```
The mac address should be a long type number. For example,
```
2write mac 2078091
```
You can comfirm that mac address has been changed through
```
2request mac
```
