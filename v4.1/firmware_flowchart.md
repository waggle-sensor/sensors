### Flowchart of Coresense Firmware Version 4.1

The following [flowchart](https://github.com/waggle-sensor/sensors/blob/develop/v4.1/Firmware_flow.png) shows how the coresense firmware works and communicates with the plugin working at node controller in firmware side.

First, when the firmware is turned on (start), it sets up serial to communicate with plugin (setup). After that, it calls all initialization functions (initialization) from all exising sensors and while do that, it initializes SPI, I2C, and other serial lines to collect data from the various sensors. 

When it finishes initialization step, the firmware waits request packets from plugin (get packet). The request packets will contains information that which sensor that the firmware need to grap data from or send to. If the firmware get a packet (yes), then it will move forward to collect and send data back to plugin. If not (no), then the firmware waits untill the plugin sends a pacekt.

If the firmware gets a packet, it parses the packet into bytes (parse) and check (check packet) if preamble (0xAA) and post script (0x55) match, and if they are correct then it checks if CRC matches. If one of them (preamble, post script, and CRC) does not match, then the whole packet is deleted and the firmware waits again a new packet.

It the three check factors are correct, then the firmware find if the packet request (request) from or to any sensors in the list of enabled sensor table. If there is no request at all (request = emtpy) then no further process is called, and the firmware waits again for a new packet.

If there is/are sensor id(s) in the packet, then the firmware calls relevant function(s) (sensor call) and save all the data collected from and created for the sensor stored into buffers (saving data into buffers) and packetize the data until there are no more request sensors in the packet. 

<img src="./Firmware_flow.png" width=400 />
