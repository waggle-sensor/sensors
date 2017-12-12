// Met and Light macaddress

void InitSensor00()
{
	return;
}

void ConfigSensor00()
{
	return;
}

void EnableSensor00()
{
	EnableSensor(0x00);
}

void DisableSensor00()
{
	DisableSensor(0x00);
}

void ReadSensor00(byte *sensorReading, int *readingLength)
{
	byte id[8];

	if (!ds2401.reset()) 
	{
		sensorReading[0] = 0xFF;
		*readingLength += 1;
		// SerialUSB.print("device is not ready");
		// return any sign that this device is not ready!!
	}

	ds2401.write(0x33);

	for (int i = 0; i < 8; i++)
	{
		id[i] = ds2401.read();
		sensorReading[i] = id[i];
		*readingLength += 1;
	}

	if (OneWire::crc8(id, 8) != 0)
	{
		sensorReading[0] = 0xFF;
		*readingLength += 1;
		// SerialUSB.print("failed to pass crc check");
		// return any sign that it is failed to checi crc
	}
}

void WriteSensor00(byte *packet)
{
	return;
}