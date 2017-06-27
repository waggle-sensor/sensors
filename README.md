# Firmware v4

Sample commands to get sensor data from coresense boards.

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
For example,
```
2write mac 2078091
```
You can comfirm that mac address has been changed through
```
2request mac
```
