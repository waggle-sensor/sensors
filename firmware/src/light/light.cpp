#include "light.h"

void Lightsense::readLight(byte ID, int* NumVal, int* val) 
{
	// initialize libraries
	if (conf == false)
	{
		hmc5883.begin();
		mcp3428_1.init(MCP342X::L, MCP342X::L);
		mcp3428_2.init(MCP342X::L, MCP342X::F);
		conf = true;
	}

	// Call a function in accordance of sensor ID
	if (ID == 0x10)
		readHMC5883L(NumVal, val);
	else if (ID == 0x11)
		readHIH6130(NumVal, val);
	else if (ID == 0x12)
		readAPDS9006(NumVal, val);
	else if (ID == 0x13)
		readTSL260RD(NumVal, val);
	else if (ID == 0x14)
		readTSL250RD(NumVal, val);
	else if (ID == 0x15)
		readMLX75305(NumVal, val);
	else if (ID == 0x16)
		readML8511(NumVal, val);
	else if (ID == 0x17)
		readTMP421(NumVal, val);

	else
		NumVal = 0;
}

void Lightsense::readHMC5883L(int* NumVal, int* val)
{
	hmc5883.getEvent(&event);
	val[0] = (int)(event.magnetic.x * 100);
	val[1] = (int)(event.magnetic.y * 100);
	val[2] = (int)(event.magnetic.z * 100);
	*NumVal = 3;
}

void Lightsense::readHIH6130(int* NumVal, int* val)
{
	float sensorValue[2];
	hih6.HIH_fetch_humidity_temperature(sensorValue);

	for (int i = 0; i < 2; i ++)
		val[i] = sensorValue[i] * 100;

	*NumVal = 2;
}

void Lightsense::readAPDS9006(int* NumVal, int* val)
{
	mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	val[0] = mcp3428_2.readADC();
	*NumVal = 1;
}

void Lightsense::readTSL260RD(int* NumVal, int* val)
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
	val[0] = mcp3428_1.readADC();
	*NumVal = 1;
}

void Lightsense::readTSL250RD(int* NumVal, int* val)
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
	val[0] = mcp3428_1.readADC();
	*NumVal = 1;
}

void Lightsense::readMLX75305(int* NumVal, int* val)
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	val[0] = mcp3428_1.readADC();
	*NumVal = 1;
}

void Lightsense::readML8511(int* NumVal, int* val)
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
	val[0] = mcp3428_1.readADC();
	*NumVal = 1;
}

void Lightsense::readTMP421(int* NumVal, int* val)
{
	val[0] = tmp421.GetTemperature() * 100;
	*NumVal = 1;
}
