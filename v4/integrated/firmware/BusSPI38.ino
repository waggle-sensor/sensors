// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI38;
byte spi38slavePin = 0x38;

void InitBusSPI38(byte *parameters)
{
	long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
	byte type = parameters[3];
	byte mode = parameters[4];

	// set SPI params, begin device
	setSPI38 = SetSPI(maxCommunicationSpeed, type, mode, spi38slavePin);
}

void ConfigBusSPI38(byte *parameters)
{
	return;
}

void EnableBusSPI38()
{
	return;
}

void DisableBusSPI38()
{
	return;
}

void ReadBusSPI38(byte *parameters, byte *sensorReading, int *readingLength)
{
	int callLength = parameters[0];

	byte writearray[callLength];
	for (int i = 0; i < callLength; i++)
		writearray[i] = parameters[1];

	// User can put const parameters if necessary
	int delayTime = parameters[2];
	int iterNum = parameters[3];

	ReadSPI(writearray, callLength, spi38slavePin, setSPI38, delayTime, iterNum);

	for (int i = 0; i < callLength; i++)
		sensorReading[i] = writearray[i];
	*readingLength = callLength;
}

void WriteBusSPI38(byte *parameters)
{
	// WriteSPI(readarray, callLength, SPI38SlavePin, setSPI38, delayTime, iterNum);
	return;
}