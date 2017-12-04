# Firmware v4.1
This firmware works as a form of "get request and send data". 
Thus if a user wants some data, the user needs to send relevant commands. 

Firmware version 4.1 is not based on version 3, which means that the sensors that had been on the coresense boards are working 
the same method, but which different structure. Libraries that have been used for version 2 and 3 are
separately implemented on various .ino files in the new version.
Moreover, all conversion equations that were implemented in firmware version 2 and 3 are moved to decoder part (pywaggle).
So all the data sent from this firmware are byte values as they are collected from a sensor directly.

Initialization, configuration, read, and write functions for sensors, which have sensor id are defined in Sensor*.ino files
with regard to its sensor id, and for sensors just added on the metsense board can use call functions in Bus*.ino.
Bus*.ino is related to bus type and address or pin number of the sensor.

### Flashing firmware
Platformio is used to complie and flash the firmware to coresense boards.

* To install platformio using pip: ```$ pip install -U platformio``` 

* To complie firmware using platformio: ```$ ./platformio.sh --alpha-in -c```  when an alpha sensor is included, or
```$ ./platformio.sh --alpha-ex -c``` when an alpha sensor is excluded.

* To flash new Firmware, use command this at where platformio.ini and platformio.sh exists:
```$ ./platformio.sh --alpha-in -f``` when an alpha sensor is included, or ```$ ./platformio.sh --alpha-ex -f```
when an alpha sensor is excluded.

### Request, collect, and decode data
When you use coresense-plugin.py in waggle-sensor/plugin_manager/plugins/coresense_4 to read a sensor value that has sensor id, 
you need to put a new line for sensor_table with the form as following (function_call must be 5, which means read sensor).
```
'Sensor Name': { 'sensor_id': given_sensor_id_in_hex, 'function_call': given_number_for_sensor, 'interval': time_in_second},

** function_call:
  0x01 -- initialize the sensor
  0x02 -- set configuration for the sensor
  0x03 -- enable the sensor
  0x04 -- disenable the sensor
  0x05 -- read from the sensor
  0x06 -- write on the sensor
```

If you will use your own request -- decode code, you can refer information below.

### Transmission Packet
** For detailed information about packet and subpacket, see "Interface and Data Format Specification for sensors" in
"waggle-sensor/sensors/v4.1/sensor-documentation" **

### Subpacket
Subpacket for requesting sensor reading must start with call function type in hex.
Below commands are call function type for sensors, which have sensor id, from 0x01 -- 0x06,
and call function type for new sensors, which don't have snesor id, from 0x11 -- 0x16.
```  
FUNCTION TYPE        ID
initSensor          0x01
configureSensor     0x02
enableSensor        0x03
disableSensor       0x04
readSensor          0x05
writeSensor         0x06
initBus             0x11
configureBus        0x12
enableBus           0x13
disableBus          0x14
readBus             0x15
writeBus            0x16
```
First 1 bit of the following byte is acknowledge bit, and other 7 bits are length of the parameter for the sensor reading.
Next bytes are parameters that are needed for sensor reading, and the first byte of the parameter must be sensor id.
If the sensor dosen't have a sensor id, then the first byte must be bus type and the second byte must be bus address or pin number.
Below is given identity number for each bus type.
```
BUS TYPE             ID
I2C                 0x00
SPI                 0x01
Serial              0x02
Analog              0x03
Digital             0x04
PWM                 0x05
```

Sensor names as parameters for Coreread are shown below. 
Coreread is able to take multiple parameters, and has no limitation on the number of parameters.
```
SENSOR         ID                      DATA
firmware ver  0xFF    Coresense firmware version
mac           0x00    Mac address of coresense boards 
tmp112        0x01    Temperature sensor
htu21d        0x02    Temperature and relative humidity sensor
hih4030       0x03    Relative humidity sensor
bmp180        0x04    Temperature and barometric pressure sensor
pr103j2       0x05    Temperature sensor
tsl250        0x06    Light sensor (300-1100 nm, high responsivity at 640 nm) 
mma8452q      0x07    Accelerate force sensor
spv1840       0x08    Sound sensor
tsys01        0x09    Temperature sensor
hmc5883l      0x0A    Magnetic field sensor
hih6130       0x0B    Temperature and relative humidity sensor
apds9006      0x0C    Light sensor (480-640 nm, high responsivity at ~500 nm)
tsl260rd      0x0D    Light sensor (820-1100 nm, high responsivity at 640 nm) 
tsl250rd      0x0E    Light sensor (300-1100 nm, high responsivity at 940 nm) 
mlx75305      0x0F    Light sensor (400-1000 nm, high responsivity at ~700 nm) 
ml8511        0x10    UV sensor (280-420 nm)
tmp421        0x13    Temperature sensor
chem config   0x16    Configuration of the chemsense firmware <<not core packet applicable>>
chemsense     0x2A    Raw, direct reading from chemsense board
----------------------------------------- alpha sensor -----------------------------------------
histogram     0x28    Histogram of particle count
serial        0x29    Serial number of the alpha sensor
status        0x2B    Status of the alpha sensor
firmware ver  0x30    Firmware version of the alpha sensor
configuration 0x31    Configuration of the alpha sensor <<not core packet applicable>>
```

### Examples
When to send a request packet to firmware, the packet will look like:
``` 0xAA 0x02 length(including sequence byte, which is following one byte) 0x10 subpacket crc 0x55 ```.

Subpacket must start with sensor id if the sensor has given one, or it must start with bus type id and bus address or pin number:
``` call_function_type length(first bit is acknowledge bit, and next 7 bits indicate length) parameters ```

** Below is just for example, and you must convert values to binary.

For example, to request reading of chemsense:
``` 0xAA 0x02 0x04 0x10 0x05 0x01 0x2A crc 0x55 ```
Or for tmp112:
``` 0xAA 0x02 0x04 0x10 0x05 0x01 0x01 crc 0x55 ```
Or for both chemsense and tmp112:
``` 0xAA 0x02 0x07 0x10 0x05 0x01 0x2A 0x05 0x01 0x01 crc 0x55 ```
To diable tmp112:
``` 0xAA 0x02 0x04 0x10 0x03 0x01 0x01 crc 0x55 ```

When you want to read data from a sensor communicating through I2C, you need to create **BusI2C<** **address id >.ino** and provide parameters that sensor request when firmware collect data from.
As an example, for tmp112:
``` 0xAA 0x02 0x07 0x10 0x15 0x04 0x00 0x40 0x00 0x01 crc 0x55```

When you want to read data from a sensor communicating thourgh SPI, you need to create **BusSPI<** **slave select pin number >.ino** and provide slave select pin number, total number of reading (how many times you will collect data from the sensor), and a command as parameters when you send a request packet.
For histogram reading from alpha sensor using SPI bus - arduino due pin number for slave select pin is 0x40, need to read 62 times, and command is 0x62):
``` 0xAA 0x02 0x07 0x10 0x15 0x04 0x01 0x40 0x3E 0x62 crc 0x55 ```
