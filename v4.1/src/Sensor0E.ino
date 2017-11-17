// TSL250RD Light sensor

void InitSensor0E(byte *sensorReading, int *readingLength)
{
	return;
}

void ConfigSensor0E(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor0E(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x0E);
}

void DisableSensor0E(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x0E);
}

void ReadSensor0E(byte *sensorReading, int *readingLength)
{
	// byte address = mcp3428_1.returnAddress();
	byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_3)};
	byte readarray[3];
	WriteReadI2C(MCP3428_1_ADDRESS, 1, writebyte, 3, readarray, 10E);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}

	// the last read is not used

	// mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
	// int TSL250_2 = mcp3428_1.readADC();
}

void WriteSensor0E(byte *sensorReading, int *readingLength)
{
	return;
}