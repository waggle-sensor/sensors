// #include <Arduino.h>
// #include <stdio.h>

#include "../../lib/HMC5883L_waggle/HMC5883L_waggle.h"
#include "../../lib/HIH6130/HIH6130.h"
#include "../../lib/MCP342X/MCP342X.h"
#include "../../lib/LibTempTMP421/LibTempTMP421.h"

class CLight
{
public:
	void LightGet(byte id, int *NumVal, char *val);

	void HMC5883L(int* NumVal, char* val);
	void HIH6130(int* NumVal, char* val);
	void APDS9006(int* NumVal, char* val);
	void TSL260RD(int* NumVal, char* val);
	void TSL250RD(int* NumVal, char* val);
	void MLX75305(int* NumVal, char* val);
	void ML8511(int* NumVal, char* val);
	void TMP421(int* NumVal, char* val);

private:
	HMC5883_Sensor chmc5883 = HMC5883_Sensor(&Wire);
	sensors_event_t event;

	Chih6130 chih6 = Chih6130();

	MCP342X mcp3428_1;
	MCP342X mcp3428_2;

	LibTempTMP421 ctmp421 = LibTempTMP421();

	bool conf = false;
};