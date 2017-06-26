#include "findSensor.h"

byte CSensor::sensorID(const char *key) {
	for (int i = 0; i < NofSensor; i++)
	{
		condition = matches(key, sArray[i]);
		if (condition){
			// SerialUSB.println(condition);
			// SerialUSB.println(BArray[i]);
			return bArray[i];
		}
	}
    return 0xff;
}

void CSensor::sensorName(byte sensor_ID, char** sensorNM)
{
	for (int i = 0; i < NofSensor; i++)
	{
		if (sensor_ID == bArray[i])
			*sensorNM = (char*) sArray[i];
	}
}