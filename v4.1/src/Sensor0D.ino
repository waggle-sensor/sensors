// TSL260RD Light sensor

void InitSensor0D()
{
	if (flagMCP1 == false)
	{
		mcp3428_1.init(MCP342X::L, MCP342X::L);
		MCP3428_1_ADDRESS = mcp3428_1.returnAddress();
		flagMCP1 = true;
	}
}

void ConfigSensor0D()
{
	return;
}

void EnableSensor0D()
{
	EnableSensor(0x0D);
}

void DisableSensor0D()
{
	DisableSensor(0x0D);
}

void ReadSensor0D(byte *sensorReading, int *readingLength)
{
	// byte address = mcp3428_1.returnAddress();
	byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_1)};
	byte readarray[3];
	WriteReadI2C(MCP3428_1_ADDRESS, 1, writebyte, 3, readarray, 10);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}

	// the last read is not used

	// mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
	// int TSL260 = mcp3428_1.readADC();
}

void WriteSensor0D(byte *sensorReading, int *readingLength)
{
	return;
}