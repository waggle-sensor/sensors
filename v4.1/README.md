# Firmware v4.1
This firmware works as a form of "get request and send data". 
Thus if a user wants some data, the user needs to send relevant commands. 

Firmware version 4.1 is not based on version 3, which means that the sensors that had been on the coresense boards are working 
the same method, but which different structure. Libraries that have been used for version 2 and 3 are
separately implemented on various .ino files in the new version.
Moreover, all conversion equations that were implemented in firmware version 2 and 3 are moved to decoder part (pywaggle).
So all the data sent from this firmware are byte values as they are collected from a sensor directly.

Initialization, configuration, enable, disable, read, and write functions for sensors, which have sensor id, are defined in Sensor*.ino files with regard to its sensor id, and for sensors just added on the metsense board can use call functions in Bus*.ino. Bus*.ino is related to bus type and address or pin number of the sensor.

### Flashing firmware
Platformio is used to complie and flash the firmware to coresense boards.

* To install platformio using pip: ```$ pip install -U platformio``` 

* To complie firmware using platformio: ```$ ./platformio.sh --alpha-in -c```  when an alpha sensor is included, or
```$ ./platformio.sh --alpha-ex -c``` when an alpha sensor is excluded.

* To flash new Firmware, use command this at where platformio.ini and platformio.sh exists:
```$ ./platformio.sh --alpha-in -f``` when an alpha sensor is included, or ```$ ./platformio.sh --alpha-ex -f```
when an alpha sensor is excluded.

## Request, collect, and decode data
When you use coresense-plugin.py in waggle-sensor/plugin_manager/plugins/coresense_4 to read a sensor value. The plugin will refer 'sensor_table.conf' in folder /wagglerw/waggle/ in nodecontroller. 

### Waggle and Coresense Packet
** For detailed information about transmission packet and subpacket, see "Interface and Data Format Specification for sensors" in
"waggle-sensor/sensors/v4.1/sensor-documentation" **

When the coresnese borad is powered on, the firmware configures, initializes, and enables all sensors implemented on met/light/chemsense boards, and alpha sensor and waits data collection request sent from coresense plugin. As the firmware uses Waggle protocol v5 to send and receive packets, coresense plugin should also use the same protocol version. Coresense Plugin 4.1 (in plugin_manager repository) is the plugin that can interact with the firmware. The plugin generates request packet using "sensor_table.conf" in /wagglerw/waggle in nodecontroller. Configuration reading from chemsense and alpha sensor do not follow waggle and coresense packet. The sensor table follows json format, and examples are given below:

#### Example sensor table
```
s-1. Sensor table to read from a sensor that has its sensor id. Collect data every 5 seconds

"Given_Sensor_Name": {
        "interval": 5,
        "function_call": "sensor_read",
        "sensor_id": given_id_in_integer
}

b-1.  Sensor table to read from a sensor that does not have its sensor id. Collect data every 5 seconds
** For i2c reading, user must write related code **

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

b-2. Sensor table to read from a sensor that does not have its sensor id. Collect data every 5 seconds

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

b-3. Sensor table to read from a sensor through analog read every 5 sec. (The same format for digial and serial)

"Sensor_Name": {
        "interval": 5,
        "function_call": "bus_read",
        "bus_type": "analog",
        "bus_address": 0,                 # pin number for the sensor is A0
        "params": []                      # no parameter is needed
}

b-4. Sensor table to read from a sensor through PWM read every 5 sec

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

|FUNCTION TYPE  |  Key for sensor_table.conf |  ID for Firmware |  Description  |
| ------------- |:-------------:|:-------------:| ----- |
|initSensor     | Sensor_init   | 0x01 | All sensors on Met/Light/Chem/Alpha are automatically initialized  |
|configureSensor| Sensor_config | 0x02 | All sensors on Met/Light/Chem/Alpha re configured with they are initialized  |
|enableSensor   | Sensor_enable | 0x03 | To enable sensor on Met/Light/Chem/Alpha: All sensors on Met/Light/Chem/Alpha are enabled when they are initialized  |
|disableSensor  | Sensor_disable| 0x04 | To disable sensor on Met/Light/Chem/Alpha --> no data will be collected from the sensor  |
|readSensor     | Sensor_read   | 0x05 | To collecte data from sensors  |
|writeSensor    | Sensor_write  | 0x06 | All sensors on Met/Light/Chem/Alpha are not writable  |
|initBus        | Bus_init      | 0x11 | To initialize new implemented sensors  |
|configureBus   | Bus_config    | 0x12 | To configure new implemented sensors  |
|enableBus      | Bus_enable    | 0x13 | New implemented sensors cannot be enabled --> data can be collected always from new sensors  |
|disableBus     | Bus_disable   | 0x14 | New implemented sensors cannot be disabled --> data can be collected always from new sensors  |
|readBus        | Bus_read      | 0x15 | To collect data from new implemented sensors  |
|writeBus       | Bus_write     | 0x16 | To write data on new implemented sensors  |

Below is given identity number for each bus type.

| BUS TYPE |Key for sensor_table.conf |  ID for Firmware |
|:-------------:|:-------------:|:-------------:|
|I2C      | i2c |  0x00 |
|SPI      | spi |  0x01 |
|Serial   | serial |  0x02 |
|Analog   | analog |  0x03 |
|Digital  | digital |  0x04 |
|PWM      | pwm |  0x05 |

Sensor names as parameters for Coreread are shown below. 
Coreread is able to take multiple parameters, and has no limitation on the number of parameters.

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

#### Configuration Information from chemsense and alpha sensor
Configuration information do not follow waggle and coresense packet format. To collect data of configutation information, user need to send request packet to coresense firmware. User can use coresense firmware, but the plugin cannot decode the data. To decode the data, the plugin needs to be modified. The configuration data will be sent with starting statement ("Start sending Alpha sensor/Chemsense configuration") and ending statement ("End sending Alpha sensor/Chemsense configuration"). Data length between the two statements differ for each case.


