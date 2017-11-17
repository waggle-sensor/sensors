// APDS Light sensor

void InitSensor0C(byte *sensorReading, int *readingLength)
{
	mcp3428_2.init(MCP342X::L, MCP342X::F);
	MCP3428_2_ADDRESS = mcp3428_2.returnAddress();
}

void ConfigSensor0C(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor0C(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x0C);
}

void DisableSensor0C(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x0C);
}

void ReadSensor0C(byte *sensorReading, int *readingLength)
{
	// byte address = mcp3428_2.returnAddress();
	byte writebyte[1] = {mcp3428_2.returnRegister(MCP342X::CHANNEL_0)};
	byte readarray[3];
	WriteReadI2C(MCP3428_2_ADDRESS, 1, writebyte, 3, readarray, 100);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}

	// the last read is not used

	// selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	// int APDS = mcp3428_2.readADC();
}

void WriteSensor0C(byte *sensorReading, int *readingLength)
{
	return;
}