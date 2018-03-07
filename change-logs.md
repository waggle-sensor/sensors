# Change logs

It keeps track of the changes for versions.

# Firmware Version 4.11 (in v4.1, git tag 4.11) (2018-02)
### New features
* Firmware automatically sends a list of "disabled sensor" which contains sensor ids that plugin requests but FW regards the sensor is not working -- the FW does not read the sensor.
* Add delay in Sensor2A.ino > initialization step, iterately check (5 times) if chemsense is attached on Metsense board, and alive.

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
