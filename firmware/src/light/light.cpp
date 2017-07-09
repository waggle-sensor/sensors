#include "light.h"

void Lightsense::readLight(byte ID, int* NumVal, char* val) 
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

void Lightsense::readHMC5883L(int* NumVal, char* val)
{
    hmc5883.getEvent(&event);
    val[0] = (int)(event.magnetic.x * 100) >> 8;
    val[1] = (int)(event.magnetic.x * 100) & 0xff;

    val[2] = (int)(event.magnetic.y * 100) >> 8;
    val[3] = (int)(event.magnetic.y * 100) & 0xff;

    val[4] = (int)(event.magnetic.z * 100) >> 8;
    val[5] = (int)(event.magnetic.z * 100) & 0xff;

	*NumVal = 6;
}

void Lightsense::readHIH6130(int* NumVal, char* val)
{
	float sensorValue[2];
	hih6.HIH_fetch_humidity_temperature(sensorValue);

	for (int i = 0; i < 2; i ++)
	{
		reference = sensorValue[i] * 100;
		val[i * 2] = reference >> 8;
		val[i * 2 + 1] = reference & 0xff;
	}

	*NumVal = 4;
}

void Lightsense::readAPDS9006(int* NumVal, char* val)
{
	mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	reference = mcp3428_2.readADC();

	val[0] = reference >> 8;
	val[1] = reference & 0xff;

	*NumVal = 2;
}

void Lightsense::readTSL260RD(int* NumVal, char* val)
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
	reference = mcp3428_1.readADC();

	val[0] = reference >> 8;
	val[1] = reference & 0xff;
	
	*NumVal = 2;
}

void Lightsense::readTSL250RD(int* NumVal, char* val)
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
	reference = mcp3428_1.readADC();

	val[0] = reference >> 8;
	val[1] = reference & 0xff;
	
	*NumVal = 2;
}

void Lightsense::readMLX75305(int* NumVal, char* val)
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	reference = mcp3428_1.readADC();

	val[0] = reference >> 8;
	val[1] = reference & 0xff;
	
	*NumVal = 2;
}

void Lightsense::readML8511(int* NumVal, char* val)
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
	reference = mcp3428_1.readADC();

	val[0] = reference >> 8;
	val[1] = reference & 0xff;
	
	*NumVal = 2;
}

void Lightsense::readTMP421(int* NumVal, char* val)
{
	reference = tmp421.GetTemperature() * 100;
	val[0] = reference >> 8;
	val[1] = reference & 0xff;

	*NumVal = 2;
}
