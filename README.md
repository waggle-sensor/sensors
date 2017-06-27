# Firmware v4

Simple explanation of talker and firmware is given along with sample commands to get sensor data from coresense boards.

## Talker
This python scripts are a mothod to communicate with coresense boards. Basically, the coresense boards send binary data, and talker trasnform the data into humand readable form.

talker.py is the main script, and other python scripts work as libraries to convert raw data into human understandable value.

From line 49, the script start to convert the data using other functions.

### To start talker.py
```
python3 talker.py <port name>
```
<port name> means the name of port which coresense boards are connected.
For example,
```
python3 talker.py /dev/ttyACM0
```

### To request data from coresense boards, use command <2request>:
```
2request <sensor key words>
```
For example,
```
2request met
```
or 
```
2request BMP180
```
or
```
2request met light chem mac
```

To get all sensor data in metsense board, lightsense board, or chemsense boards, use "met", "light", or "chem" respectively.
Only to get mac addresses, use "mac".

You can use sensor name as a "sensor key word":
```
<sensor name>     <data type>
  tmp112          temperature
  htu21d          temperature & humidity
  bmp180          temperature & pressure
  pr103j2         temperature
  tsl250          light
  mma8452q        accelerate force
  spv1840         sound
  tsys01          temperature
  hmc5883l        magenetic field
  hih6130         temperature 
  apds9006        light
  tsl260rd        light
  tsl250rd        light
  mlx75305        light
  ml8511          light
  tmp421          temperature
```

### To write new mac address for metsense/lightsense boards

For now (6/27/2017) you can change mac address for metsense/lightsense board:
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
## Firmware
This firmware is based on basic C language. main.ino basically follows ardunio C language, and others follow C.

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
```
The IDs are hex integers. If the ID is smaller than 0x10, the sensor is on a metsense boards, and if the ID is smaller than 0x20 but greater than 0x0F, the sensor is on a lightsense board.

As a sensor name, mac means mad address for both metsense/lightsense board and chemsense board. So when the user wants to know both mac addresses, the user can use "mac" as a key word.

Libraries for I2C communication on boards are in folder "lib". All the data collection is performed through met.cpp, light.cpp, chem.cpp, or spi.cpp.

For now (6/27/2017), spi.cpp is incompleted.
