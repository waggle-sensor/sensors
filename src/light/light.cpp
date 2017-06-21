#include "light.h"

void CLight::LightGet(byte ID, int* NumVal, char* val) 
{
	// initialize libraries
	if (conf == false)
	{
		chmc5883.begin();
	    mcp3428_1.init(MCP342X::L, MCP342X::L);
	    mcp3428_2.init(MCP342X::L, MCP342X::F);
		conf = true;
	}

	// Call a function in accordance of sensor ID
	if (ID == 0x10)
		HMC5883L(NumVal, val);
	else if (ID == 0x11)
		HIH6130(NumVal, val);
	else if (ID == 0x12)
		APDS9006(NumVal, val);
	else if (ID == 0x13)
		TSL260RD(NumVal, val);
	else if (ID == 0x14)
		TSL250RD(NumVal, val);
	else if (ID == 0x15)
		MLX75305(NumVal, val);
	else if (ID == 0x16)
		ML8511(NumVal, val);
	else if (ID == 0x17)
		TMP421(NumVal, val);

	else
		NumVal = 0;
}

void CLight::HMC5883L(int* NumVal, char* val)
{
	*NumVal = 6;
    chmc5883.getEvent(&event);

    val[0] = (int)(event.magnetic.x * 100) >> 8;
    val[1] = (int)(event.magnetic.x * 100) & 0xff;
    val[2] = (int)(event.magnetic.y * 100) >> 8;
    val[3] = (int)(event.magnetic.y * 100) & 0xff;
    val[4] = (int)(event.magnetic.z * 100) >> 8;
    val[5] = (int)(event.magnetic.z * 100) & 0xff;
}

void CLight::HIH6130(int* NumVal, char* val)
{
	*NumVal = 4;
	chih6.HIH_fetch_humidity_temperature(val);
}

void CLight::APDS9006(int* NumVal, char* val)
{
	*NumVal = 2;
	mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	mcp3428_2.readADC(val);
}

void CLight::TSL260RD(int* NumVal, char* val)
{
	*NumVal = 2;
	mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
	mcp3428_1.readADC(val);
}

void CLight::TSL250RD(int* NumVal, char* val)
{
	*NumVal = 2;
	mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
	mcp3428_1.readADC(val);
}

void CLight::MLX75305(int* NumVal, char* val)
{
	*NumVal = 2;
	mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	mcp3428_1.readADC(val);
}

void CLight::ML8511(int* NumVal, char* val)
{
	*NumVal = 2;
	mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
	mcp3428_1.readADC(val);
}

void CLight::TMP421(int* NumVal, char* val)
{
	*NumVal = 2;
    ctmp421.GetTemperature(val);
}
