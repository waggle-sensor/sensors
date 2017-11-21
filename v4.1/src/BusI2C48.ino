// TMP112 Temperature sensor through bus function

void InitBusI2C48(byte *parameters)
{
	byte address = parameters[1];
	byte writearray[3] = {parameters[2], parameters[3], parameters[4]};

	WriteI2C(address, 3, writearray);
	delay(100);

	byte writebyte[1] = {parameters[1]};
	WriteI2C(address, 1, writebyte);
	delay(100);

	byte readarray[2];
	ReadI2C(address, 2, readarray);	
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
	byte address = parameters[1];
	byte writebyte[1] = {parameters[2]};
	byte readarray[2];

	WriteI2C(address, 1, writebyte);
	delay(100);
	ReadI2C(address, 2, readarray);

	int length = 2;
	for (int i = 0; i < length; i++)
		sensorReading[i] = readarray[i];
	*readingLength = length;
}

void WriteBusI2C48(byte *sensorReading)
{
	return;
}