#include <Arduino.h>
#include <stdio.h>

#include "stringutils.h"

#define NofSensor 22

class Sensor
{
public:
	byte sensorID(const char *key);
	void sensorName(byte sensor_ID, char** sensorNM);

private:
	bool condition;

	const char *sArray[NofSensor] = {"mac", "tmp112", "htu21d", "bmp180", 
									 "pr103j2", "tsl250", "mma8452q", "spv1840",
									 "tsys01", "met",
									 "hmc5883l", "hih6130", "apds9006", "tsl260rd",
									 "tsl250rd", "mlx75305", "ml8511", "tmp421",
									 "light",
									 "chem",
									 "alpha"};


	const byte bArray[NofSensor] = {0x00, 0x01, 0x02, 0x03, 
									0x04, 0x05, 0x06, 0x07,
									0x08, 0x0F,
									0x10, 0x11, 0x12, 0x13,
									0x14, 0x15, 0x16, 0x17,
									0x1F,
									0x20,
									0x40};
};