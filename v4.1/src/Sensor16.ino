// Chemconfig

void InitSensor16()
{
	return;
}

void ConfigSensor16()
{
	return;
}

void EnableSensor16()
{
	EnableSensor(0x16);
}

void DisableSensor16()
{
	DisableSensor(0x16);
}

void ReadSensor16(byte *sensorReading, int *readingLength)
{
	SerialUSB.print("Start sending Chemsense FW configuration");
	for (int i = 0; i < chemConfigLength; i++)
		SerialUSB.write(chemConfigReading[i]);
	SerialUSB.print("End sending Chemsense FW configuration");
	SerialUSB.println("");
}

void WriteSensor16(byte *sensorReading, int *readingLength)
{
	return;
}