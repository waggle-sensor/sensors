// TMP112 Temperature sensor

#define TMP112_ADDRESS 0x48

void InitSensor01()
{
	const byte TMP112_CONFIG_REG = 0x01;   // Pointer Register Byte: Configuration Register (Read/Write)
	// const byte TMP112_TEMP_REG = 0x00;    // Pointer Register Byte: Temperature Register (Read Only)

	byte writearray[3] = {TMP112_CONFIG_REG, 0x60, 0xB0};   // 0x60, 0xA0 --> Default 12 bit register reading, 0xB0 --> 13 bit register reading
	WriteI2C(TMP112_ADDRESS, 3, writearray);
	delay(100);

	byte writebyte[1] = {TMP112_CONFIG_REG};
	WriteI2C(TMP112_ADDRESS, 1, writebyte);
	delay(100);

	byte readarray[2];
	ReadI2C(TMP112_ADDRESS, 2, readarray);
}

void ConfigSensor01()
{
	return;
}

void EnableSensor01()
{
	EnableSensor(0x01);
}

void DisableSensor01()
{
	DisableSensor(0x01);
}

void ReadSensor01(byte *sensorReading, int *readingLength)
{
	const byte TMP112_TEMP_REG = 0x00;    // Pointer Register Byte: Temperature Register (Read Only)

	byte writebyte[1] = {TMP112_TEMP_REG};
	byte readarray[2];
	WriteI2C(TMP112_ADDRESS, 1, writebyte);
	delay(100);
	ReadI2C(TMP112_ADDRESS, 2, readarray);

	sensorReading[0] = readarray[0];
	sensorReading[1] = readarray[1];
	*readingLength = 2;
}

void WriteSensor01(byte *packet)
{
	return;
}