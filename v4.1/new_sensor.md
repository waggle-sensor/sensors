# How to Put a New Sensor

If anyone wants to add a new sensor in the firmware/Metsense board, the user needs to add an ```.ino``` file. If the sensor
gets a sensor id such as **0xFA**, then the file name must be ```SensorFA.ino```. And if the sensor does not have sensor id
but uses I2C and connected through arduino pin number **0x48**, then the file name must be ```BusI2C48.ino```.

The file must contain **initSensorFA, configSensorFA, enableSensorFA, disableSensorFA, readSensorFA, and writeSensorFA** -- 
refer one of ```.ino``` files in this folder).

If the file added on this folder and do ```make``` (just compile) or ```make install``` (complie and install the firmware 
into the metsense board), then new **SensorStruct.ino, BusStruct.ino, BusParamStruct.ino, and EnabledStruct.ino** will be 
automatically created.
