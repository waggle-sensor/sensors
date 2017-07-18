# Firmware v4
This firmware works as a form of "get request and send data". Thus if a user wants some data, the user needs to send relevant commands. Codes related to the firmware itself to receive request, collect data, and send the values are in folder "firmare", and the other folder "talker" contains scripts related to send request command, receive data, and decode the binary information.

## Firmware
Firmware version 4 is based on version 3, which means that the sensors that had been on the coresense boards are working the same method. Libraries that have been used for version 2 and 3 are implemented on the new version, so that the type of sensor values are the same with the previous versions. Some of the data are sent as byte values as they are collected from a sensor directly, and some of the sensor values are calculated, such as to temperature in celsius.

Two big difference between this new firmware and the old version are: 1) ability to request specific sensor data when a user wants, and 2) expansibility to use a new sensor without flashing a new firmware if the sensor talks through serial, SPI, or I2C (plug-in and play). Serial (Serial1, Serial2, and Serial3), SPI, and I2C on metsense board are available to use with new sensors if they can communicate through one of those communication methods.

When a user collects data from sensors on coreboards, the user can use customized universal I2C function or sensor specific implemented functions. To use the sensor specific functions, wire communication (I2C) is initialized when a coresense boards is powered on. But for Serial and SPI, there are no sensor specific functions but only customized universal serial and SPI function. 

### Flashing firmware
Platformio is used to complie and flash the firmware to coresense boards.

To install platformio using pip:
```
$ pip install -U platformio
```
To flash new Firmware, use command below at where platformio.ini exists:
```
$ platformio run -t upload
```
Or just to compile your code, do:
```
$ platformio run
```

### Commands
Below commands are primary commands. 
```  
ver            to request a coresense firmware version
id             to request a node id

Corewrite      to to change a coresense board mac address
Coreread       to request sensor values from coresense boards (metsense and lightsense boards)

SPIconfig      to establish connection and configuration for a SPI line
SPIread        to read command relavent sensor values

Serialpower    to power on or off a sensor communicate through a serial if it is needed
Serialconfig   to establish connection and configuration for a serial line
Serialwrite    to write data through a serial if it is needed
Serialread     to read a serial line

I2Cwrite       to write data through I2C if it is needed 
I2Cread        to read sensor values
```
All the primary commands require following parameters, except "ver" and "id". Detailed commands are shown below. All parameters in "< >" are hex string except Coreread and Corewrite. 
```
$ ver
$ id

$ Corewrite mac <address(integer)>
$ Coreread <sensor name>

$ SPIconfig <slave pin> <max speed(3bytes)> <bit order> <SPI mode>
$ SPIread <delay time> <the number of iteration of delay> <command>

$ Serialpower <power pin number> <sign(on/off)>
$ Serialconfig <port> <baud rate(3bytes)> <time out(3bytes)> <power pin number>
$ Serialwrite <port> <data>
$ Serialread <port>

$ I2Cwrite <address> <data(1byte)>
$ I2Cread <address> <byte length to read>

# reference values:
<SPI bit Order>
LSB first = 0
MSB first = 1

<SPI mode>
SPI mode0 = 0x00
SPI mode1 = 0x04
SPI mode2 = 0x08
SPI mode3 = 0x0c

<Serial power sign>
power on = 0
power off = 1

<<Chemsense configuration>>
power pin number = 47
serial port = 3
baud rate = 115200

<<Alpha sensor configuration>>
slave pin number = 40
max SPI speed = 500000
bit order = MSB first
SPI mode = mode1
delay time = 10 ms
the number of iteration of delay = 1 (always)
```

Sensor names as parameters for Coreread are shown below. 
Coreread is able to take multiple parameters, and has no limitation on the number of parameters.
```
mac           Mac address of coresense boards 
tmp112        Temperature sensor
htu21d        Temperature and relative humidity sensor
bmp180        Temperature and barometric pressure sensor
pr103j2       Temperature sensor
tsl250        Light sensor (300-1100 nm, high responsivity at 640 nm) 
mma8452q      Accelerate force sensor
spv1840       Sound sensor
tsys01        Temperature sensor
hmc5883l      Magnetic field sensor
hih6130       Temperature and relative humidity sensor
apds9006      Light sensor (480-640 nm, high responsivity at ~500 nm)
tsl260rd      Light sensor (820-1100 nm, high responsivity at 640 nm) 
tsl250rd      Light sensor (300-1100 nm, high responsivity at 940 nm) 
mlx75305      Light sensor (400-1000 nm, high responsivity at ~700 nm) 
ml8511        UV sensor (280-420 nm)
tmp421        Temperature sensor
```

#### Example commands (see commands above to understand details)
1. To read temperature sensors and get mac address for the coresense boards:
```
$ Coreread tmp112 htu21d pr103j2 tsys01 hih6130 tmp421 mac
```
2. To change mac address for the coresense to 12345 and read the mac again:
```
$ Corewrite mac 12345
$ Coreread mac
```
3. To read Serial3 which is connected to a chemsense board: chemsense board uses pin 47 as a power line, 115200 as baud rate, and I want that Serial3 waits for 4 seconds if there is no data to read.
```
$ Serialconfig 0x03 0x01 0xc2 0x00 0x00 0x0f 0xa0 0x2f
$ Serialread 0x03
```
4. To read SPI which is connected to an alpha sensor: alpha sensor needs 10 ms delay between first command and second command (just one time). Also it sends MSB first, it uses SPI mode1, and slave select pin is connected to GPIO pin 40:
```
$ SPIconfig 0x28 0x07 0xa1 0x20 0x01 0x04
$ SPIread 0x0a 0x01 0x03 0x00 (power on)
$ SPIread 0x0a 0x01 ... (command to read version, serial number, configuration, or histogram)
...
$ SPIread 0x0a 0x01 0x03 0x01 (power off)
```
5. To read tmp112 and HIH6130 through I2C command:
```
/*If the wire communication is initialized. For this firmware,
wire communication is always initialized when the board is powered on.*/`
$ I2Cread 0x48 2
$ I2Cread 0x27 4
```
6. To get node id and firmware version:
```
$ id
$ ver
```

#### Reference for coresense data
Information given below is a reference to understand data from the coresense boards.
```
mac           <mac address>
tmp112        <100ths of degree C>
htu21d        <100ths of degree C, 100ths of %RH>
bmp180        <100ths of degree C, barometic pressure in Pa>
pr103j2       <100ths of degree C>
tsl250        <raw read>
mma8452q      <100ths of g (gx, gy, gz, norm)>
spv1840       <raw read>
tsys01        <100ths of degree C>
hmc5883l      <100ths of G (Gx, Gy, Gz)>
hih6130       <100ths of degree C, 100ths of %RH>
apds9006      <raw read>
tsl260rd      <raw read> 
tsl250rd      <raw read> 
mlx75305      <raw read> 
ml8511        <raw read>
tmp421        <100ths of degree C>
```

#### Reference for chemsense data
Information given below is a reference to understand data from the chemsense board. Chemsense board sends 5 different data lines, and each data line is sent in each second. Which means that to collect all the data sent from chemsense boards, the user needs to read Serial3 for 5 continuous times. However for now (07/17/2017), only 3 data lines are valid. 
```
header: this header is contained each of data lines.
       The header will be saved in dictionary with a key "ChemMac" in talker.
       BAD=<board address>

t+0s: First data line
       HDT=<temperature in 100ths of degree C>
       HDH=<relative humidity in 100ths of %RH>
       SHT=<temperature in 100ths of degree C>
       SHH=<relative humidity in 100ths of %RH>
       LPT=<temperature in 100ths of degree C>
       LPP=<barometric pressure in Pascals>
       SUV=<Raw UV register>
       SVL=<Raw VL register>
       SIR=<Raw IR register>
       
t+1s: Second data line
       IRR=<AFE pA of respiratory irritant sensor current>
       IAQ=<AFE pA of indoor air quality sensor current>
       SO2=<AFE pA of SO2 sensor current>
       H2S=<AFE pA of H2S sensor current>
       OZO=<AFE pA of ozone sensor current>
       NO2=<AFE pA of NO2 sensor current>
       CMO=<AFE pA of CO sensor current>
       
t+2s: Third data line
       AT0=<ADC temperature in 100ths of degree C>
       AT1=<ADC temperature in 100ths of degree C>
       AT2=<ADC temperature in 100ths of degree C>
       AT3=<ADC temperature in 100ths of degree C>
       LTM=<LMP temperature in 100ths of degree C>

# planned to be
t+3s: Fourth data line
       ACX=<raw register of acceloration in x direction>
       ACY=<raw register of acceloration in y direction>
       ACZ=<raw register of acceloration in z direction>
       VIX=<vibration "index" high-water>
       GYX=<raw register of orientation in x direction>
       GYY=<raw register of orientation in x direction>
       GYZ=<raw register of orientation in x direction>
       OIX=<orientation "index" high-water>
       
t+4s: Fifth data line
       TBD
```

## Talker

Scripts in talker folder have been designed to talk with the new firmware. The talker can use a text file to send command sets, or it can get input. The script will convert some of command inputs to relavent values (Mostly for parameters for configuration and request values. For the details, please refer talker scripts. Some of the commands do not need to be converted..).

### To start talker.py

To start talker.py, do:
```
python3 talker.py -s <port name> -c <command set text file> -r
```
A user has to put a serial device name, which is -s <port name> option. -c option is to import command sets from a text file, from a "command set text file", and -r option is to send the command sets imported from the text file repeatedly.

For example, to connect device at /dev/ttyACM0, to import command sets from a file "cmdset.txt", and to send the commands repeatedly:
```
$ python3 talker.py -s /dev/ttyACM0 -c cmdset.txt -r
```
If a user did not put recursive option, then after sending all command sets, talker mode will be changed to get input.

Or if a user wants to type in some commands:
```
$ python3 talker.py -s /dev/ttyACM0
```



#### Identification numbers

To identify data at talker side, each sensors have each of identification number. The first byte of data sent from firmware is a sensor identification number in hex string:
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



To request data from an alpha sensor, you can send commands below as "command" (see Commands above). The commands will be translated into hex strings by talker:
```
  <command>               <data type>
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

1. To read temperature sensors and get mac address for the coresense boards (when a sensor sends multiple values including temperature, temperature value comes first):
```
$ Coreread tmp112 htu21d pr103j2 tsys01 hih6130 tmp421 mac
```
2. To change mac address for the coresense to 12345 and read the mac again:
```
$ Corewrite mac 12345
$ Coreread mac
```
3. To read Serial3 which is connected to a chemsense board: chemsense board uses pin 47 as a power line, 115200 as baud rate, and I want that Serial3 waits for 4 seconds if there is no data to read.
```
$ Serialconfig 3 115200 4000 47
$ Serialread 3
```
4. To read SPI which is connected to a alpha sensor: alpha sensor needs 10 ms delay between first command and second command (just one time). Also it sends MSB first, uses SPI mode1, and slave select pin is connected to GPIO pin 40:
```
$ SPIconfig 40 500000 MSB_first mode1
$ SPIread 10 1 power_on
$ SPIread 10 1 ... (version, serial, config, or histogram)
...
$ SPIread 10 1 power_off
```
5. To read tmp112 and HIH6130 through I2C command:
```
/*If the wire communication is initialized. For this firmware,
wire communication is always initialized when the board is powered on.*/`
$ I2Cread 0x48 2
$ I2Cread 0x27 4
```
6. To get node id and firmware version:
```
$ id
$ ver
```

#### Caution
* After you power on the alpha sensor, you'd better wait about 5 second before request data. If not, the values from alpha sensor are not correct values and some nonsenses.
* Alphasense company recommands to do not change laser power because it is adjusted for each sensor after calibration.
