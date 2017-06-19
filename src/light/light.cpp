#include "light.h"

void CLight::LightGet(byte ID, int* NumVal, float* val, char** unit) 
{
	if (conf == false)
	{
		chmc5883.begin();
	    mcp3428_1.init(MCP342X::L, MCP342X::L);
	    mcp3428_2.init(MCP342X::L, MCP342X::F);
		conf = true;
	}

	if (ID == 0x10)
		HMC5883L(NumVal, val, unit);
	else if (ID == 0x11)
		HIH6130(NumVal, val, unit);
	else if (ID == 0x12)
		APDS9006(NumVal, val, unit);
	else if (ID == 0x13)
		TSL260RD(NumVal, val, unit);
	else if (ID == 0x14)
		TSL250RD(NumVal, val, unit);
	else if (ID == 0x15)
		MLX75305(NumVal, val, unit);
	else if (ID == 0x16)
		ML8511(NumVal, val, unit);
	else if (ID == 0x17)
		TMP421(NumVal, val, unit);

	else
		NumVal = 0;
}

void CLight::HMC5883L(int* NumVal, float* val, char** unit)
{
	*NumVal = 3;
	unit[0] = "Gx";
	unit[1] = "Gy";
	unit[2] = "Gz";

    chmc5883.getEvent(&event);

    val[0] = event.magnetic.x;
    val[1] = event.magnetic.y;
    val[2] = event.magnetic.z;
}

void CLight::HIH6130(int* NumVal, float* val, char** unit)
{
	*NumVal = 2;
	unit[0] = "C";
	unit[1] = "RH";

	chih6.HIH_fetch_humidity_temperature(val);
}

void CLight::APDS9006(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "AL Raw";

	mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	val[0] = mcp3428_2.readADC();
}

void CLight::TSL260RD(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "IR Raw";

	mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
	val[0] = mcp3428_1.readADC();
}

void CLight::TSL250RD(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "VL Raw";
	
	mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
	val[0] = mcp3428_1.readADC();
}

void CLight::MLX75305(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "AL Raw";

	mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	val[0] = mcp3428_1.readADC();
}

void CLight::ML8511(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "UV Raw";

	mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
	val[0] = mcp3428_1.readADC();
}

void CLight::TMP421(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "C";

    val[0] = ctmp421.GetTemperature();
}
