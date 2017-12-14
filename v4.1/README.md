# Firmware v4.1
This firmware works as a form of "get request and send data". 
Thus if a user wants some data, the user needs to send relevant commands. 

Firmware version 4.1 is not based on version 3, which means that the sensors that had been on the coresense boards are working 
the same method, but which different structure. Libraries that have been used for version 2 and 3 are
separately implemented on various .ino files in the new version.
Moreover, all conversion equations that were implemented in firmware version 2 and 3 are moved to decoder part (pywaggle).
So all the data sent from this firmware are byte values as they are collected from a sensor directly.

Initialization, configuration, enable, disable, read, and write functions for sensors, which have sensor id, are defined in Sensor*.ino files with regard to its sensor id, and for sensors just added on the metsense board can use call functions in Bus*.ino. Bus*.ino is related to bus type and address or pin number of the sensor.

### Flashing firmware using makefile
Makefile in /waggle-sensor/senssros/v4.1/integrated/firmware does complie, build, and flash onto the board. Binary file of the firmware is created in bin folder in the directory.

### Flashing firmware using platformio
If you would like to use platformio, you can use commands below, but the structure of the directory v4.1 needs to be re-configured. Build method is changed from platformio to use makefile because platformio does not provide a way to create binary file, which needed to flash new firmware to nodes.

* To install platformio using pip: ```$ pip install -U platformio``` 

* To complie firmware using platformio: ```$ ./platformio.sh --alpha-in -c```  when an alpha sensor is included, or
```$ ./platformio.sh --alpha-ex -c``` when an alpha sensor is excluded.

* To flash new Firmware, use command this at where platformio.ini and platformio.sh exists:
```$ ./platformio.sh --alpha-in -f``` when an alpha sensor is included, or ```$ ./platformio.sh --alpha-ex -f```
when an alpha sensor is excluded.

## Request, collect, and decode data
When you use coresense-plugin.py in waggle-sensor/plugin_manager/plugins/coresense_4 to read a sensor value, the plugin will refer 'sensor_table.conf' in folder /wagglerw/waggle/ in nodecontroller. 'sensor_table.conf' will be generated when coresense-plugin.py is excuted if there is no such file. If User wants to modify which sensor the user wants to collect data, how frequently the user wants to collect data, or add a new sensor that the user wants to test alone.

### Waggle and Coresense Packet
** For detailed information about transmission packet and subpacket, see "Interface and Data Format Specification for sensors" in
"waggle-sensor/sensors/v4.1/sensor-documentation" **

When the coresnese borad is powered on, the firmware configures, initializes, and enables all sensors implemented on met/light/chemsense boards, and alpha sensor and waits data collection request sent from coresense plugin. As the firmware uses Waggle protocol v5 to send and receive packets, coresense plugin should also use the same protocol version. Coresense Plugin 4.1 (in plugin_manager repository) is the plugin that can interact with the firmware. The plugin generates request packet using "sensor_table.conf" in /wagglerw/waggle in nodecontroller. Configuration reading from chemsense and alpha sensor do not follow waggle and coresense packet. The sensor table follows json format, and examples are given below:

#### Example sensor table
```
s-1. Sensor table to collect data every 5 seconds from a sensor that has its sensor id.

"Given_Sensor_Name": {
        "interval": 5,
        "function_call": "sensor_read",
        "sensor_id": given_id_in_integer
}

b-1.  Sensor table to collect data every 5 seconds from a new sensor that does not have its sensor id through i2c.
** For i2c reading, user must write related code and re-flash the new firmware **

"Sensor_Name": {
        "interval": 5,
        "function_call": "bus_read",
        "bus_type": "i2c",
        "bus_address": 64,                 # address for the sensor is 0x40
        "params": [                        # to collect data, this sensor 
                243,                         requests to send two bytes
                245                          that are 0xF3 and 0xF5
         ]
}

b-2. Sensor table to collect data every 5 seconds from a new sensor that does not have its sensor id thorugh spi.

"Sensor_Name": {
        "interval": 5,
        "function_call": "bus_read",
        "bus_type": "spi",
        "bus_address": 64,                # address for the sensor is 0x40
        "params": [                       # to collect data, this sensor requires
                64,                         how many time it collects data from the sensor
                100                         requesting command
         ]
}

b-3. Sensor table to collect data every 5 seconds from a new sensor through analog, digial, and serial.

"Sensor_Name": {
        "interval": 5,
        "function_call": "bus_read",
        "bus_type": "analog",
        "bus_address": 0,                 # pin number for the sensor is A0
        "params": []                      # no parameter is needed
}

b-4. Sensor table to collect data every 5 seconds from a new sensor through PWM.

"Sensor_Name": {
        "interval": 5,
        "function_call": "bus_read",
        "bus_type": "PWM",
        "bus_address": 0,                 # pin number for the sensor is A0
        "params": [                       # duty cycle in %
                50
         ]
}
```

A table below shows types of "function_call" in the sensor table. When you do something with sensors that have sensor id, you need to use top 6 commands that with a word "Sensor". Otherwise, when you do something with new sensors that do not have sensor id, you need to use bottom 6 command that with a word "Bus".

|FUNCTION TYPE  |  Key for sensor_table.conf |  ID for Firmware |  Description  |
| ------------- |:-------------:|:-------------:| ----- |
|initSensor     | sensor_init   | 0x01 | All sensors on Met/Light/Chem/Alpha are automatically initialized  |
|configureSensor| sensor_config | 0x02 | All sensors on Met/Light/Chem/Alpha re configured with they are initialized  |
|enableSensor   | sensor_enable | 0x03 | To enable sensor on Met/Light/Chem/Alpha: All sensors on Met/Light/Chem/Alpha are enabled when they are initialized  |
|disableSensor  | sensor_disable| 0x04 | To disable sensor on Met/Light/Chem/Alpha --> no data will be collected from the sensor  |
|readSensor     | sensor_read   | 0x05 | To collecte data from sensors  |
|writeSensor    | sensor_write  | 0x06 | All sensors on Met/Light/Chem/Alpha are not writable  |
|initBus        | bus_init      | 0x11 | To initialize new implemented sensors  |
|configureBus   | bus_config    | 0x12 | To configure new implemented sensors  |
|enableBus      | bus_enable    | 0x13 | New implemented sensors cannot be enabled --> data can be collected always from new sensors  |
|disableBus     | bus_disable   | 0x14 | New implemented sensors cannot be disabled --> data can be collected always from new sensors  |
|readBus        | bus_read      | 0x15 | To collect data from new implemented sensors  |
|writeBus       | bus_write     | 0x16 | To write data on new implemented sensors  |

When you try to collect data from a new sensor using "readBus", then you must provide which bus are you using, as shown in a table below.

| BUS TYPE |Key for sensor_table.conf |  ID for Firmware |
| ------------- |:-------------:|:-------------:|
|I2C      | i2c |  0x00 |
|SPI      | spi |  0x01 |
|Serial   | serial |  0x02 |
|Analog   | analog |  0x03 |
|Digital  | digital |  0x04 |
|PWM      | pwm |  0x05 |

All the sensor table provide parameters for the sensor reading, and  Sensor names are parameters for "readSensor".
"readSensor" command is able to take multiple parameters, if the length of the parameter is less than 127.

| SENSOR        |ID             |        DATA   |
| ------------- |:-------------:|:-------------:|
|firmware ver  |0xFF|    Coresense firmware version                                                |
|mac           |0x00|    Mac address of coresense boards                                           |
|tmp112        |0x01|    Temperature sensor                                                        |
|htu21d        |0x02|    Temperature and relative humidity sensor                                  |
|hih4030       |0x03|    Relative humidity sensor                                                  |
|bmp180        |0x04|    Temperature and barometric pressure sensor                                |
|pr103j2       |0x05|    Temperature sensor                                                        |
|tsl250        |0x06|    Light sensor (300-1100 nm, high responsivity at 640 nm)                   |
|mma8452q      |0x07|    Accelerate force sensor                                                   |
|spv1840       |0x08|    Sound sensor                                                              |
|tsys01        |0x09|    Temperature sensor                                                        |
|hmc5883l      |0x0A|    Magnetic field sensor                                                     |
|hih6130       |0x0B|    Temperature and relative humidity sensor                                  |
|apds9006      |0x0C|    Light sensor (480-640 nm, high responsivity at ~500 nm)                   |
|tsl260rd      |0x0D|    Light sensor (820-1100 nm, high responsivity at 640 nm)                   |
|tsl250rd      |0x0E|    Light sensor (300-1100 nm, high responsivity at 940 nm)                   |
|mlx75305      |0x0F|    Light sensor (400-1000 nm, high responsivity at ~700 nm)                  |
|ml8511        |0x10|    UV sensor (280-420 nm)                                                    |
|tmp421        |0x13|    Temperature sensor                                                        |
|chem config   |0x16|    Configuration of the chemsense firmware <<not core packet applicable>>    |
|chemsense     |0x2A|    Raw, direct reading from chemsense board                                  |
|alpha sensor histogram     |0x28|    Histogram of particle count                                               |
|alpha sensor serial        |0x29|    Serial number of the alpha sensor                                         |
|alpha sensor status        |0x2B|    Status of the alpha sensor                                                |
|alpha sensor firmware ver  |0x30|    Firmware version of the alpha sensor                                      |
|alpha sensor configuration |0x31|    Configuration of the alpha sensor <<not core packet applicable>>          |

Parameters for "readBus" are differed with regard to the bus type -- i2c, spi, serial, and so on -- and sensor properties. Additionally, parameters for all bus related commands must be differed regarding sensor type and sensor properties. Therefore, the example paremeters cannot be given in here, and follow the datasheet for each sensor for "sensor_table.conf". Functions for bus are not fully completed, such as config, enable, disable, and write, however, the given standards are:

| Function      | Bus type      | Parameter     |
| ------------- |:-------------:|:-------------|
| bus_init | i2c <br> spi <br> serial <br> analog <br> digital <br> pmw | : N/A <br> : 3 bytes of max speed, 1 byte of type, 1 byte of mode <br> : 1 byte of power pin, 3 bytes of baudrate, 1 byte of timeout time in second <br> : N/A <br> : 1 byte of pin mode (0: input or 1: output) <br> : N/A |
| bus_config | i2c <br> spi <br> serial <br> analog <br> digital <br> pmw | : N/A <br> : N/A <br> : N/A <br> : N/A <br> : N/A <br> : N/A |
| bus_enable | i2c <br> spi <br> serial <br> analog <br> digital <br> pmw | : N/A <br> : N/A <br> : N/A <br> : N/A <br> : N/A <br> : N/A |
| bus_disable| i2c <br> spi <br> serial <br> analog <br> digital <br> pmw | : N/A <br> : N/A <br> : N/A <br> : N/A <br> : N/A <br> : N/A |
| bus_read | i2c <br> spi <br> serial <br> analog <br> digital <br> pmw | : n number of parameters regaring to the sensor properties <br> : each 1 byte of the number of call, command, delay time, and the number of delay <br> : N/A <br> : N/A <br> : N/A <br> : N/A |
| bus_write | i2c <br> spi <br> serial <br> analog <br> digital <br> pmw | : N/A <br> : N/A <br> : N/A <br> : N/A <br> : 1 byte of input (0 or 1) <br> : 1 byte of pwm duty cycle in percentage |


#### Configuration Information from chemsense and alpha sensor
Configuration information do not follow waggle and coresense packet format. To collect data of configutation information, user need to send request packet to coresense firmware. User can use coresense firmware, but the plugin cannot decode the data. To decode the data, the plugin needs to be modified. The configuration data will be sent with starting statement ("Start sending Alpha sensor/Chemsense configuration") and ending statement ("End sending Alpha sensor/Chemsense configuration"). Data length between the two statements differ for each case.



