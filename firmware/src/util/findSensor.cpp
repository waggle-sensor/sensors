#include "findSensor.h"

byte Sensor::sensorID(const char *key) {
	for (int i = 0; i < NofSensor; i++)
	{
		condition = matches(key, sArray[i]);
		if (condition)
			return bArray[i];
	}
	
    return 0xff;
}

void Sensor::sensorName(byte sensor_ID, char** sensorNM)
{
	for (int i = 0; i < NofSensor; i++)
	{
		if (sensor_ID == bArray[i])
			*sensorNM = (char*) sArray[i];
	}
}