# How to Put a New Sensor

If anyone wants to add a new sensor in the firmware/Metsense board, the user needs to add an ```Sensor*.ino``` or ```Bus*.ino``` file. The ```*``` in the file name must be the sensor id in hex or bus type and pin number in hex. If the sensor gets a sensor id such as **0xFA**, then the file name must be ```SensorFA.ino```, or if the sensor does not have sensor id but uses I2C and connected through arduino pin number **0x48**, then the file name must be ```BusI2C48.ino```.

The file must contain functions named as **initSensor-, configSensor-, enableSensor-, disableSensor-, readSensor-, and writeSensor-**. For example, if the sensor id is **0xFA**, then the functions must be **initSensorFA, configSensorFA, enableSensorFA, disableSensorFA, readSensorFA, and writeSensorFA**. Please refer one of ```.ino``` files in this folder).

If a new file is added in this folder and do ```make``` (just compile) or ```make install``` (complie and install the firmware 
into a Metsense board), then new **SensorStruct.ino, BusStruct.ino, BusParamStruct.ino, and EnabledStruct.ino** will be 
automatically created, so that the firmware automatically notices the new sensor and creates sensor list.
