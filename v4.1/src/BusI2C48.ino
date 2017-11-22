// TMP112 Temperature sensor through bus function

const byte i2c48address = 0x48;

void InitBusI2C48(byte *parameters)
{
	byte writearray[3] = {parameters[0], parameters[1], parameters[2]};

	WriteI2C(i2c48address, 3, writearray);
	delay(100);

	byte writebyte[1] = {parameters[0]};
	WriteI2C(i2c48address, 1, writebyte);
	delay(100);

	byte readarray[2];
	ReadI2C(i2c48address, 2, readarray);	
}

void ConfigBusI2C48(byte *parameters)
{
	return;
}

void EnableBusI2C48()
{
	return;
}

void DisableBusI2C48()
{
	return;
}

void ReadBusI2C48(byte *parameters, byte *sensorReading, int *readingLength)
{
	byte writebyte[1] = {parameters[0]};
	byte readarray[2];

	WriteI2C(i2c48address, 1, writebyte);
	delay(100);
	ReadI2C(i2c48address, 2, readarray);

	int length = 2;
	for (int i = 0; i < length; i++)
		sensorReading[i] = readarray[i];
	*readingLength = length;
}

void WriteBusI2C48(byte *sensorReading)
{
	return;
}