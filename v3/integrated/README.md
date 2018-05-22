<!--
waggle_topic=Waggle/Sensors/V3,Firmware v3
-->

# Firmware v3

This is coresense firmware v3. It collects data from sensors in Metsense board, Lightsense board, and Chemsense board. Basically, this firmware automatically reads data, transforms the data to waggle packet format, and sends a packet every 25 seconds if the boards are powered on and connected to node controller.

## Flowchart of Coresense Firmware Version 3
The following [flowchart](https://github.com/waggle-sensor/sensors/blob/develop/v3/integrated/Firmware_flow.png) shows how the coresense firmware version 3 works.

### Flowchart:
<img src="./Firmware_flow.png" width=350 />

### Step 1:
First, when the firmware is turned on **(Start)**, it sets up serialUSB to communicate with plugin and I2C to grap data from I2C sensors **(Set up)**. After that, it initializes sensors **(Initialization)**. While sensors are initialized, SPI, I2C, and other serial lines are started and configured to collect data from sensors. 

### Step 2:
When it finishes initialization, the firmware reads sensors one by one **(Collect Data)**, and trasnforms the data to match waggle packet format **(Change Data to Waggle Format)**. When the firmware reads all the sensors, it packtizes the data **(Pack Data)**, and sends the packet **(Send Packet)**. 

**One cycle for reading, transforming, packing, and sending a packet takes about 25 seconds.** So this firmware sends a packet every 25 seconds.


### Detailed codes:
The list below is the files/folders for this coresense firmware v3.

#### Make:

makefile

buildinfo.cpp
config.cpp
setbuildtime.sh

configure

#### Main:
1. firmware.ino: This Firmware starts from this, and it calls all other functions to read, transform, pack, and send data.

#### Sub-main:
1. airsense.ino: When the firmware collects data from sensors on Metsense board, it goes through this.
2. lightsense.ino: When the firmware collects data from sensors on Lightsense board, it goes through this.
3. chemsense.ino: When the firmware collects data from sensors on Chemsense board, it goes through this.
4. alphasense.ino: When the firmware collects data from Alpha sensor, it goes through this.

#### Set up sensor:
These codes are called when the main function sets up all sensors:

1. sensors_setup.ino: Setup functions for some sensors.
2. setsensor.h: Setup functions for some sensors.
3. pin_config.cpp: Pin cofniguration for some sensors.
4. variable.h: Define temporary buffers for sensors.
5. subpacket.h: Define packet buffers for sensors and packets.
6. subpacket.ino: Initialize packet buffers

#### Supporting:
These codes are sort of libraries to collect data from,

1. HIH.ino: a sensor, HIH6130 temperature and humidity sensor.
2. TMP112.ino: a sensor, TMP112 temperature sensor.
3. TSYS01.ino: a sensor, TSYS01 temperature sensor.
4. mma84521.ino: a sensor, MMA84521 accelerometer.
5. verinfo.cpp: firmware version, a fixed value.

#### Libraries:
1. libs: Libraries for some sensors, because not all the sensors requires libraries.

#### Transform format:
1. dataFormats.ino: Defined Waggle format. Before the data are packetized, all data pass through this and transformed from raw byte to Waggle format.

#### Packetization:
These codes are called when the firmware packs data:

1. firmware_version.ino: packetize firmware version, a fixed value.
2. packet_assembler.ino: packetize sensor readings.
3. alpha_packet.ino: packetize Alpha sensor reading only.
4. alpha_packet_conf.ino: packetize Alpha sensor configuration data only.
5. CRC_8_Waggle.ino: create CRC for current packet and add CRC at the second last byte of a packet.

## Coresense_plugin

The coresense plugin folder contains python codes which de-parse super-packets into human readable lines. Processes to de-parse super-packets are in [coresense_pluginUSBSerial.py](./coresense_plugin/coresense_pluginUSBSerial.py). To change USB serial port, see [coresense_InotifyKernel.py](./coresense_plugin/coresense_InotifyKernel.py) and change "/dev/waggle_coresense" in "newDevice.put('/dev/waggle_coresense')" to what you are using.

This plugin uses **python2**.

To execute this process, do
```bash
python coresense.py
```

## Tools and equipment required
* One of each Chemsense, Lightsense, and Airsense borads
* Two ethernet cables and a micro-USB cable
* A computer to test the Chemsense


## To compile and install the program
To compile the files, do
```bash
make
```
To compile, build and upload the codes on the Atmel, do
```bash
make install
```
or
```bash
make
make program
```

To compile, build and run the files, do
```bash
make run
```

To compile, build the codes and get decoded data with python script, do
```bash
make install
```
and execute [coresense.py](./coresense_plugin/coresense.py) in [coresens_plugin](./coresense_plugin). 
```bash
python coresense.py
```
Decode process is done through [coresense_pluginUSBSerial.py](./coresense_plugin/coresense_pluginUSBSerial.py).
