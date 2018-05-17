# Flowchart of Coresense Firmware Version 4.1

The following [flowchart](https://github.com/waggle-sensor/sensors/blob/develop/v4.1/Firmware_flow.md#flowchart) shows how the coresense firmware version 4.1 works and communicates with the plugin working at node controller in firmware side.

### Step 1
First, when the firmware is turned on **(start)**, it sets up serialUSB to communicate with plugin and I2C to grap data from I2C sensors **(setup)**. After that, it calls all initialization functions (initialization) from all exising sensors and while do that, it initializes SPI, I2C, and other serial lines to collect data from the various sensors. 

### Step 2
When it finishes initialization step, the firmware waits request packets from plugin **(get packet)**. The request packets will contains information that which sensor that the firmware need to grap data from or send to. If the firmware get a packet (yes), then it will move forward to collect and send data back to plugin. If not (no), then the firmware waits untill the plugin sends a pacekt.

### Step 3
If the firmware gets a packet, it parses the packet into bytes (parse) and check **(check packet)** if preamble (0xAA) and post script (0x55) match, and if they are correct then it checks if CRC matches. If one of them (preamble, post script, and CRC) does not match, then the whole packet is deleted and the firmware waits again a new packet.

### Step 4
It the three check factors are correct, then the firmware find if the packet request **(request)** from or to any sensors in the list of enabled sensor table. If there is no request at all **(request = emtpy)** then no further process is called, and the firmware waits again for a new packet.

### Step 5
If there is/are sensor id(s) in the packet, then the firmware calls relevant function(s) **(sensor call)** and save all the data collected from and created for the sensor stored into buffers **(saving data into buffers)** and packetize the data **(packetization)** until there are no more request sensors in the packet.

### Step 6
The firmware call sensor functions and do packetization until there is no more request in the packet received from plugin, and when there is no more request, the firmware finishes packetization **(packetization - finalize)** and send packet(s) to plugin **(send packets)** and waits new packets sent from plugin **(get packet)**.


### Detailed Processes

1. Start: Sensor boards are powered on.
2. Setup: Initialize **SerialUSB** to communicate firmware and plugin, and **I2C** to get data from I2C sensors.
3. Initialization: Call all **initialization function** from all ```Sensor*.ino``` and ```Bus*.ino``` files. By calling initialization function in Sensor2A.ino (function sets related to Chemsense board), if exist, the firmware sets Serial3 and power on the sensor board, and by calling initialization function in Sensor28.ino, if exist, the firmware sets SPI and power on the alpha sensor. And other serial lines can be ready if there is a sensor uses the lines to send data (for example, Decagon soil moisture sensor (Serial1) and PMS7003 particle sensor (Serial2)).
4. Get packet: [The plugin](https://github.com/waggle-sensor/plugin_manager/tree/master/plugins/coresense_4) sends a packet every specific seconds that determined by users, and this firmware waits the packet.
5. Parse: Parse the packet into bytes for further processes.
6. Check packet: Preamble of all the packets must be **0xAA**, post script must be **0x55**, and protocol number must be **2**. Also CRC must be calculated based on the length and value of the packet except 4 pre-determined bytes.
7. Request = empty: 5th to 3rd bytes from the last bytes are bytes for request. It could be **initialization, configuration, enable, disable, read, and write**. The request must be with sensor id, or bus pin number. Detailed explanation about the packet is given in [v4dataExchange.pdf](https://github.com/waggle-sensor/sensors/blob/develop/v4.1/documentation/v4dataExchange.pdf).
8. Sensor call: This firmware calls functions with regard to the parsed bytes.
9. Saving data into buffers: If request(s) are **read**, the reading data stored into buffers.
10. Packetization: Stored buffers are packed into packet(s).
11. Packetization - finalize: If request(s) have finished, this firmware finalizes packetization --.
12. Send Packets: -- and send the packet(s) to plugin.

**Need to be added in the firmware**
- For now, the firmware does not send any message to plugin except the request is read so that users do not know if other request has happend. Thus additional messages saying something about the process relatice to other request such as write, configure, and so on.

### Flowchart
<img src="./Firmware_flow.png" width=600 />

