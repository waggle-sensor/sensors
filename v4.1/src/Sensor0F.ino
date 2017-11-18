// MLX Light sensor

void InitSensor0F()
{
	if (flagMCP1 == false)
	{
		mcp3428_1.init(MCP342X::L, MCP342X::L);
		MCP3428_1_ADDRESS = mcp3428_1.returnAddress();
		flagMCP1 = true;
	}
}

void ConfigSensor0F()
{
	return;
}

void EnableSensor0F()
{
	EnableSensor(0x0F);
}

void DisableSensor0F()
{
	DisableSensor(0x0F);
}

void ReadSensor0F(byte *sensorReading, int *readingLength)
{
	// byte address = mcp3428_1.returnAddress();
	byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_0)};
	byte readarray[3];
	WriteReadI2C(MCP3428_1_ADDRESS, 1, writebyte, 3, readarray, 100);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}

	// the last read is not used

	// mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	// int MLX = mcp3428_1.readADC();
}

void WriteSensor0F(byte *sensorReading, int *readingLength)
{
	return;
}