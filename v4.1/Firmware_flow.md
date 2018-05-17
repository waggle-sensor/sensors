# Flowchart of Coresense Firmware Version 4.1

The following [flowchart](https://github.com/waggle-sensor/sensors/blob/develop/v4.1/Firmware_flow.md#flowchart) shows how the coresense firmware version 4.1 works and communicates with the plugin working at node controller in firmware side.

### Step 1:
First, when the firmware is turned on **(Start)**, it sets up serialUSB to communicate with plugin and I2C to grap data from I2C sensors **(Set up)**. After that, it calls all initialization functions **(Initialization)** for all sensors and while do that, it initializes SPI, I2C, and other serial lines communicate with sensors to collect data from them. 

### Step 2:
When it finishes initialization, the firmware waits request packets sent from plugin **(Get Packet)**. If the firmware notices that the plugin sends packet **(incoming buffer?)**, it reads buffer until the last byte 0x55 is collected **(Store Buffers until Last Byte 0x55 is collected)**. When the last byte has arrived, the firmware checks if the stored buffers matche waggle protocol by checking preamble, post script, protocol version, and packet length **(waggle protocol?)**. If all the reqirements are satisfied, it checks CRC of the packet **(CRC?)**. If the packet does not match with waggle protocol or CRC, the packet is discarded.

### Step 3:
If the packet passes the former processes, we can say it contains information to config, enable, disable, read, or write on a sensor/sensors. Until length of the packet/request becomes empty **(Request = Empty)** and if the requested sensor is availble/enabled **(Sensor available?)**, the firmware performs the commands sent through the packet **(Call Function for the Request)**. If the sensor is not available, the sensor ID is packed as *disabled sensor* **(Packetization (Current Data)**. But if the request was *read sensor data*, the firmware saves the data into buffers **(Save Data into Buffers)**. Before the firmware packes the data, it checkes if the *length of packet + currently collected data* exceeds 127 bytes **(Packet Length + Current Data Buffer) > 127)**. If it exceeds, the firmware sends one existing packet first to plugin **(Packetization (Finalize)** and **Send Packet))** and makes a new packet with the current Data Buffer **(Packetization (Current Data))**.

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

7. Request = empty: 5th to last 3rd bytes are bytes for request/command. It could be **initialization, configuration, enable, disable, read, and write**. The request must be with sensor id, or bus pin number. Detailed explanation about the subpacket is given in [v4dataExchange.pdf](https://github.com/waggle-sensor/sensors/blob/develop/v4.1/documentation/v4dataExchange.pdf).

8. Sensor available: When the firmware initializes all sensors, it determines if the sensor is available or not by trying to get data. If the firmware fails to get data in initialization stage, it assumes that eh sensor is not physically connected, and lists the sensor as *disabled*.

9. Saving data into buffers: If the request is **read**, the collected data are stored into buffers.

10. Packet Length + Current Data Buffer > 127: With regards to the waggle protocol, length of a packet and subpacket cannot exceed 127 bytes. However when the firmware collects all sensor data (Met/Light/Chem/Alpha/Plantower), the length of total packet must exceed 127 bytes. Therefore, the firmware checks length of packets and send them separately in multiple packets.

11. Packetization (Finalize): Calculate CRC, add post script at the end of a packet, and make new packet.

12. Packetization (Current Data): Make a subpacket and add it in the existing packet.

**Need to be added in the firmware**
- For now, the firmware does not send any message if the request is **write, configure, enable, or disable**. Becuase of this, users cannot notice if other request has done. Additional messaging packets saying something about the process will be needed.

### Flowchart
<img src="./Firmware_flow.png" width=600 />

