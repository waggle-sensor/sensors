// HTU21D Temperature sensor through bus function

const byte i2c40address = 0x40;

void InitBusI2C40(byte *parameters)
{
	return;
}

void ConfigBusI2C40(byte *parameters)
{
	return;
}

void EnableBusI2C40()
{
	return;
}

void DisableBusI2C40()
{
	return;
}

void ReadBusI2C40(byte *parameters, byte *sensorReading, int *readingLength)
{
	// Read Temprature, Hang out while measurement is taken 50mS max
	byte readarray[3];
	byte writebyte[1] = {parameters[0]};
	WriteReadI2C(i2c40address, 1, writebyte, 3, readarray, 55);

	for (int i = 0; i < 2; i++)
		sensorReading[i] = readarray[i];
	*readingLength += 2;

	//Request a humidity reading
	writebyte[0] = parameters[1];
	WriteReadI2C(i2c40address, 1, writebyte, 3, readarray, 55);

	for (int i = 0; i < 2; i++)
		sensorReading[i + 2] = readarray[i];
	*readingLength += 2;
}

void WriteBusI2C40(byte *sensorReading)
{
	return;
}