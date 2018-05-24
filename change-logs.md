<!--
waggle_topic=IGNORE
-->

# Change logs

It keeps track of the changes for versions.

# Firmware Version 4.14 (in v4.1) (2018-05)
### New features
* Sensor2C.ino and Sensor 2D.ino, which are OnSet rain gauge and Dacagon rain gauge, are added on. Rain gauge has tested within v4.13, but soil moisture sensor has never tested within v4.13 (2018-05).
### Commnets
* Codes for enable/disable sensor and bus call functions are cleaned up.
### Cautions
* Rain gauge is not automatically recognized whether the sensor is connected on Metsense board or not: the firmware alway assume that rain gauge is connected from this version. It's totally user's/plugin's responsibility if the user/plugin calls the sensor or not.

# Firmware Version 4.13 (in v4.1) (2018-04)
### New features
* Sensor32.ino, which is sending a list of disabled sensors if it is requested.
* With regard to waggleprotocol spec, the length of firmware version is changed: bitwise operation is removed.
### Comments
* A list of disabled sensor is automatically sent by FW when a user request any data from any sensor. However, Sensor ID 32 is added for the case to request the list of disabled sensor explicitly.

# Firmware Version 4.12 (in v4.1) (2018-03)
### New features
* PMS7003 sensor added refering Sensor36.ino file.
* A redundant file, Mandatory.ino, removed.
* Calling enable function in initialization at setup step added.
* Change read function that if there is no Alpha sensor, then send 'N' for all bytes.
### Comments
* This version need to be tested in a long term period (not yet tested).

# Firmware Version 4.11 (in v4.1, git tag 4.11) (2018-02)
### New features
* Firmware automatically sends a list of "disabled sensor" which contains sensor ids that plugin requests but FW regards the sensor is not working -- the FW does not read the sensor.
* Add delay in Sensor2A.ino > initialization step, iterately check (5 times) if chemsense is attached on Metsense board, and alive.
### Behinds
* Data collection from soil moisture sensor and rain gauge are not tested with this version
* Version info has not updated, so that it will also send 4.10 as it's version.

# Firmware Version 4.1 (v4.1, git tag 4.1) (2017-12)
### New features
* Libraries and codes to convert raw sensor data reading had been moved to plugin
* Sensor initialization, configuration, reading, and writing functions had been separated into ```Sensor*.ino``` files
* Functions for bus reading that is for sensors that do not have sensor id had been implemented
### Fixes
* Packetization in firmware and plugin for the firmware are completed
### Behinds
* Data collection from soil moisture sensor and rain gauge are not tested with this version
### Cautions
* Functions that initialize, configure, write, and dis/enable sensors are not fully tested.
### Bugs
* May need to add "delay(100);" in Sensor2A.ino > Initialization2A() > under pinMode(Chmsensepin, output);
* May need to change read function that if there is no Alpha sensor, then send 'N' for all bytes.

# Firmware Version 4 (v4, no git tag) (2017-08)
### New features
* Data collection flow changes to two way request-answer method from one way sending method
* Packetization in firmware and plugin for the firmware are not ready

# Firmware Version 3 (v3, no git tag) (~2017-04)
* No specific trackes...
### New features
* Send heartbeat
* Collect data from Alpha sensor
* Collect data from rain gauge (On set), and soil moisture sensor (for specific nodes)
* Remove a sound level sensor, and other sensors on Met/lightsense board
### Fixes
* Collect data from NC through RS232 (serial)
* Send data continuously every 25 seconds

# Firmware Version 2 (v2, no git tag)
* No trackes... 
### Features
* Collect data from NC through I2C
* Send data continuously every 30 seconds
* No heartbeat
