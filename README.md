# Firmware v4

Firmware version 4 is based on version 3, which means that the sensors what had been there are working the same method. So that some of the data are sent as byte values as they collected from a sensor directly, and some of the sensor values are calculated, such as to temperature in celsius.

This firmware works as a form of "get request and send data". Thus if a user wants some data, the user need to send relevant command.

Codes related to the firmware itself to receive request, collect data, and send the values are in folder "firmare", and the other folder "talker" contains scripts related to send request command, receive data, and decode the binary information.

Two difference between this new firmware and the old version is: 1) ability to request specific sensor data when a user wants, and 2) expansibility to use a new sensor without flashing a new firmware (plug-in and play). 

Serial (Serial1, Serial2, and Serial3 for chemsense board), SPI, and I2C on metsense board are now available to use with new sensors if they can communicate through one of those communication methods.

When a user read data from sensors on coreboards, the user can use customized universal I2C function or sensor specific implemented functions. But for Serial and SPI, there are no sensor specific functions but only customized universal serial and SPI function. 

### Flashing firmware
Platformio is used to complie and flash the firmware to coresense boards.

To install platformio using pip:
```
pip install -U platformio
```
To flash new Firmware, use command below at where platformio.ini exists:
```
platformio run -t upload
```
Or just to compile your code, do:
```
platformio run
```

### Commands
Below commands are primary commands. 
```  
ver            requests coresense firmware version
id             requests id of the node

Corewrite      change mac address of the coresense board
Coreread       request sensor value on metsense or lightsense board

SPIconfig      establish configuration for a SPI line
SPIread        read sensor value

Serialpower    power on or off the sensor connected to serial if it is needed
Serialconfig   establish configuration for a serial line
Serialwrite    write data through serial if it is needed
Serialread     read serial line

I2Cwrite       write data through I2C if it is needed 
I2Cread        read sensor value
```
All the primary commands requires following parameters, except "ver" and "id". Detailed commands are shown below. All parameters in "< >" are hex string.
```
Coreread <sensor name>
Corewrite mac <address>

SPIconfig <slavePin> <maxSpeed(3bytes)> <bitOrder> <dataMode>
SPIread <delay time> <the number of iteration of delay> <command>

Serialpower <power pin number> <sign(on/off)>
Serialconfig <port> <datarate(3bytes)> <timeout(3bytes)> <power pin number>
Serialwrite <port> <data>
Serialread <port>

I2Cwrite <address> <data>
I2Cread <address> <length>
```
For example, to get a line of data from a chemsense board which is connected through serial3, a user need to establish configuration of the line and request data through:
```
use pin 47 as a power line for chemsense board, baudrate is 115200, and the line will wait for 4 second if no data is comming through.
Serialconfig 0x03 0x01 0xc2 0x00 0x00 0x00 0x0f 0xa0 0x2f
Serialread 0x03
```


### Identification numbers

To identify data at plug-in side, sensors have each of identification number. The first byte of data sent from firmware is sensor identification number:
```
       <sensor name>                   <identification number>
            mac                                 0x00
            tmp112                              0x01
            htu21d                              0x02
            bmp180                              0x03
            pr103j2                             0x04
            tsl250                              0x05
            mma8452q                            0x06
            spv1840                             0x07
            tsys01                              0x08
            hmc5883l                            0x10
            hih6130                             0x11
            apds9006                            0x12
            tsl260rd                            0x13
            tsl250rd                            0x14
            mlx75305                            0x15
            ml8511                              0x16
            tmp421                              0x17
   
sensor communicate through serial      0xc0|port number (0x01 - 0x03)
sensor communicate through SPI         slave pin number
sensor communicate through I2C         address
```
If an ID is smaller than 0x10, the sensor is on a metsense boards, and if an ID is smaller than 0x20 but greater than 0x0F, the sensor is on a lightsense board. As a sensor name, mac means mac address of coresense boards.


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
