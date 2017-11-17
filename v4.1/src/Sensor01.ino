// TMP112 Temperature sensor

void InitSensor01(byte *sensorReading, int *readingLength)
{
	const byte TMP112_CONFIG_REG = 0x01;
	// const byte TMP112_TEMP_REG = 0x00;

	byte writearray[3] = {TMP112_CONFIG_REG, 0x60, 0xB0};
	WriteI2C(TMP112_ADDRESS, 3, writearray);
	delay(100);

	byte writebyte[1] = {TMP112_CONFIG_REG};
	WriteI2C(TMP112_ADDRESS, 1, writebyte);
	delay(100);

	byte readarray[2];
	ReadI2C(TMP112_ADDRESS, 2, readarray);
}

void ConfigSensor01(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor01(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x01);
}

void DisableSensor01(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x01);
}

void ReadSensor01(byte *sensorReading, int *readingLength)
{
	const byte TMP112_TEMP_REG = 0x00;

	byte writebyte[1] = {TMP112_TEMP_REG};
	byte readarray[2];
	WriteI2C(TMP112_ADDRESS, 1, writebyte);
	delay(100);
	ReadI2C(TMP112_ADDRESS, 2, readarray);

	sensorReading[0] = readarray[0];
	sensorReading[1] = readarray[1];
	*readingLength = 2;
}

void WriteSensor01(byte *sensorReading, int *readingLength)
{
	return;
}