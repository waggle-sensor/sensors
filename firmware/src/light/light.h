// #include <Arduino.h>
// #include <stdio.h>

#include "../../lib/HMC5883L_waggle/HMC5883L_waggle.h"
#include "../../lib/HIH6130/HIH6130.h"
#include "../../lib/MCP342X/MCP342X.h"
#include "../../lib/LibTempTMP421/LibTempTMP421.h"

class Lightsense
{
public:
	void readLight(byte id, int *NumVal, int *val);

	void readHMC5883L(int* NumVal, int* val);
	void readHIH6130(int* NumVal, int* val);
	void readAPDS9006(int* NumVal, int* val);
	void readTSL260RD(int* NumVal, int* val);
	void readTSL250RD(int* NumVal, int* val);
	void readMLX75305(int* NumVal, int* val);
	void readML8511(int* NumVal, int* val);
	void readTMP421(int* NumVal, int* val);

private:
	HMC5883_Sensor hmc5883 = HMC5883_Sensor(&Wire);
	sensors_event_t event;

	hih6130 hih6 = hih6130();

	MCP342X mcp3428_1;
	MCP342X mcp3428_2;

	LibTempTMP421 tmp421 = LibTempTMP421();

	bool conf = false;
};