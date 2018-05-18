<!--
waggle_topic=Waggle/Sensors/V4,Firmware
-->


# Firmware v4.1
This firmware works as a form of **get request, perform commands,** and **send data**. Thus if a user wants some data, the user needs to send relevant commands through coresense_4 plugin. 

Firmware version 4.1 is not based on v3, so the data collection structure is so much different then the previous firmwares. Libraries that have been used for v2 and v3 are separately implemented on various ```Sensor*.ino``` files in this version.

Moreover, all conversion equations that were implemented in v2 and v3 firmwares have moved to decoder part, [**pywaggle protocol v5**](https://github.com/waggle-sensor/pywaggle/tree/master/waggle/protocol/v5). Thus, all the data sent from this firmware are raw byte readings as they were collected from sensors directly.


## How to Put a New Sensor
If anyone wants to add a new sensor in the firmware/Metsense board, the user needs to add an ```Sensor*.ino``` or ```Bus*.ino``` file. The ```*``` in the file name must be the sensor id in hex or bus type and pin number in hex. If the sensor gets a sensor id such as **0xFA**, then the file name must be ```SensorFA.ino```, or if the sensor does not have sensor id but uses I2C and connected through arduino pin number **0x48**, then the file name must be ```BusI2C48.ino```.

The file must contain functions named as **initSensor-, configSensor-, enableSensor-, disableSensor-, readSensor-,** and **writeSensor-**. For example, if the sensor id is **0xFA**, then the functions must be **initSensorFA, configSensorFA, enableSensorFA, disableSensorFA, readSensorFA,** and **writeSensorFA**. Please refer one of ```.ino``` files in this folder.

If a new file (any of ```Sensor*.ino``` or ```Bus*.ino```) is added in this folder, and when the firmware is compiled by doing ```make``` (just compile) or ```make install``` (complie and install the firmware into a Metsense board), new **SensorStruct.ino, BusStruct.ino, BusParamStruct.ino,** and **EnabledStruct.ino** will be automatically created. Based on the files, the firmware automatically notices that a new sensor is added on and creates new sensor list.


## Request, collect, and decode data
When you use [**coresense 4 plugin**](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/coresense_4/plugin.py) to send request packets and receive collected data packets, the plugin refers [**sensor_table.conf**](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/coresense_4/sensor_table.conf) that contains what sensor will the plugin request data, how frequently request the data, and so on. With this configuration file, we can do *sensor_init, sensor_config, sensor_enable, sensor_disable, sensor_read, sensor_write, bus_init, bus_config, bus_enable, bus_disable, bus_read,* and *bus_write*.
For more information about the configuration file, please refer [**coresense 4 plugin README**](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/coresense_4/README.md), [**coresense 4 plugin**](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/coresense_4/plugin.py), and [**sensor_table.conf**](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/coresense_4/sensor_table.conf).

When this firmware and plugin communicates, the data must follow **Waggle Packet**. Detailed information about **Waggle Packet** are described in [v4dataExchange.pdf](https://github.com/waggle-sensor/sensors/blob/develop/v4.1/documentation/v4dataExchange.pdf). Below tables are simple structure description of waggle transmission packet v2:

* Protocol v2 transmission packet (two ways communication):

|preamble|data type 4 bits & protocol 4 bits|data length|End of Seq & squence number|data (subpackets)|CRC|postscript|
| --- | --- | --- | --- | --- | --- | --- |
|0xAA|0x00 - 0x0F << 4 & 0x02|0x00 - 0xFF|0 or 1 & 0x00 - 0x7F|varies, <= 255 bytes|crc|0x55|

* Protocol v2 requesting subpacket (from plugin to firmware):

|call function|acknowledge 1 bit & param length 7 bits|parameters (1st byte is sensor id)|
| --- | --- | --- |
|0x00 - 0xFF|0 or 1 & 0x00 - 0x7F|varies, <= 127 bytes|

* Protocol v2 data subpacket (from firmware to plugin):

|sensor id|validity 1 bits & data length 7 bits|data|
| --- | --- | --- |
|varies|0 or 1 of 1st bit & 0x00 - 0x7F|varies, <= 127 bytes|	

Basically, the [**coresense 4 plugin**](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/coresense_4/plugin.py) provides encoding and decoding services with regard to **Waggle protocol**. Therefore if you use the *plugin*, you only need to see [**sensor_table.conf**](https://github.com/waggle-sensor/plugin_manager/blob/master/plugins/coresense_4/sensor_table.conf). Moreover, the *plugin* is connected with [**pywaggle protocol v5**](https://github.com/waggle-sensor/pywaggle/tree/master/waggle/protocol/v5) so that the *plugin* provides converted values when an option *--hrf* is given. For more information about data convertion service, please refer [**coresense 4 plugin README**](https://github.com/waggle-sensor/plugin_manager/tree/master/plugins/coresense_4). 


## Flowchart of Coresense Firmware Version 4.1

The following [flowchart](https://github.com/waggle-sensor/sensors/blob/develop/v4.1/Firmware_flow.md#flowchart) shows how the coresense firmware version 4.1 works..

### Flowchart:
<img src="./Firmware_flow.png" width=800 />

### Step 1:
First, when the firmware is turned on **(Start)**, it sets up serialUSB to communicate with plugin and I2C to grap data from I2C sensors **(Set up)**. After that, it calls all initialization functions **(Initialization)**. While sensors are initialized, SPI, I2C, and other serial lines are started and configured to collect data from sensors. 

### Step 2:
When it finishes initialization, the firmware waits a request packet sent from plugin **(Get Packet)**. If the firmware notices that the plugin is sending a packet **(incoming buffer?)**, it reads buffer until the last byte 0x55 is collected **(Store Buffers until Last Byte 0x55 is collected)**. 

When the last byte has arrived, the firmware checks if the stored buffers matche waggle protocol by checking preamble, post script, protocol version, and packet length **(waggle protocol?)**. If all the reqirements are satisfied, it checks CRC of the packet **(CRC?)**. If the packet does not match with waggle protocol or CRC, the packet is discarded.

### Step 3:
If the packet passes former processes, we can say the packet contains information to config, enable, disable, read, or write on a sensor/sensors. Until length of the packet/request becomes empty **(Request = Empty)** and if the requested sensor is availble/enabled **(Sensor available?)**, the firmware performs the commands sent through the packet **(Call Function for the Request)**. 

If the sensor is not available, the sensor ID is packed as *disabled sensor* **(Packetization (Current Data)**. But if the sensor is available and the request was *read sensor data*, the firmware reads sensor and saves data into buffers **(Save Data into Buffers)**. Before the firmware packes the data, it checkes if the *length of current packet + currently collected data buffer* exceeds 127 bytes **(Packet Length + Current Data Buffer) > 127)**. If it exceeds, the firmware sends one existing packet first to plugin **(Packetization (Finalize)** and **Send Packet))** and makes a new packet with the current data buffer **(Packetization (Current Data))**.

### Step 4:
If there is no remaining request/command, the firmware checks packet length if it is longer than 4 bytes **(Packet Length > 4)**. If the packet length is longer than 4 bytes, the firmware finalizes the packet **(Packetization (Finalize))** and send the packet to plugin **(Send Packet)**. But if it is less than 4 bytes, the firmware does nothing and waits new buffer comming from plugin **(Get Packet)**.

### Detailed Processes:

1. Start: Sensor boards are powered on. Mostly Metsense board, Lightsense board, Chemsense board, Alpha sensor, and Plantower sensor (it depends on nodes).

2. Setup: Initialize **SerialUSB** to communicate firmware with plugin, and **I2C** to get data from I2C sensors.

3. Initialization: Call all **initialization functions** implemented in all ```Sensor*.ino``` and ```Bus*.ino``` files. For example, by calling initialization function in Sensor2A.ino (function sets for Chemsense board), the firmware sets Serial3 and power on the Chemsense board. For another example, by calling initialization function in Sensor28.ino (function sets for Alpha sensor), the firmware sets SPI and power on the alpha sensor.

* *For your information, Decagon Soil Moisture sensor uses Serial1, PMS7003 Plantower sensor uses Serial2, and Chemsense board uses Serial3. So for now, all Serial lines are occupied*

4. Get packet: [The plugin](https://github.com/waggle-sensor/plugin_manager/tree/master/plugins/coresense_4) sends a packet every particular seconds that determined by users, and this firmware waits the packet. The packet must follow waggle protocol version 2.

5. Waggle Protocol: Preamble of the packets must be **0xAA**, post script must be **0x55**, and protocol number must be **2**. 

6. CRC: CRC must be calculated based on the length and values in the packet except 4 pre-determined bytes (preamble, post script, protocol, and sequence.

7. Request = empty: 5th to last 3rd bytes are bytes for request/command. It could be **initialization, configuration, enable, disable, read,** and ***write**. The request must be with sensor id, or bus pin number. Detailed explanation about packets are given in [v4dataExchange.pdf](https://github.com/waggle-sensor/sensors/blob/develop/v4.1/documentation/v4dataExchange.pdf).

8. Sensor available: When the firmware initializes all sensors, it determines if the sensor is available or not by trying to get data. If the firmware fails to get data in initialization stage, it assumes that eh sensor is not physically connected, and lists the sensor as *disabled*.

9. Saving data into buffers: If the request is **read**, the collected data are stored into buffers.

10. Packet Length + Current Data Buffer > 127: With regards to the waggle protocol, length of a packet and subpacket cannot exceed 127 bytes. However when the firmware collects all sensor data (Met/Light/Chem/Alpha/Plantower), the length of total packet must exceed 127 bytes. Therefore, the firmware checks length of packets and send them separately in multiple packets.

11. Packetization (Finalize): Calculate CRC, add post script at the end of a packet, and make new packet. If it if the last packet for one requesting packet, first bit of 4th byte is 1. Otherwise, first bit of 4th byte is 0.

12. Packetization (Current Data): Make a subpacket and add it in the existing packet.

### Need to be added in the firmware:
- For now, the firmware does not send any message if the request is **write, configure, enable,** or **disable**. Becuase of this, users cannot notice if other request has done. Additional messaging packets saying something about the process will be needed.

