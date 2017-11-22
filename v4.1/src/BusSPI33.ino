// Bus function for SPI reading using GPIO 33 as slave select pin

SPISettings setSPI33;
byte spi33slavePin = 0x33;

void InitBusSPI33(byte *parameters)
{
	long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
	byte type = parameters[3];
	byte mode = parameters[4];

	// set SPI params, begin device
	setSPI33 = SetSPI(maxCommunicationSpeed, type, mode, spi33slavePin);
}

void ConfigBusSPI33(byte *parameters)
{
	return;
}

void EnableBusSPI33()
{
	return;
}

void DisableBusSPI33()
{
	return;
}

void ReadBusSPI33(byte *parameters, byte *sensorReading, int *readingLength)
{
	int callLength = parameters[0];

	byte writearray[callLength];
	for (int i = 0; i < callLength; i++)
		writearray[i] = parameters[1];

	// User can put const parameters if necessary
	int delayTime = parameters[2];
	int iterNum = parameters[3];

	ReadSPI(writearray, callLength, spi33slavePin, setSPI33, delayTime, iterNum);

	for (int i = 0; i < callLength; i++)
		sensorReading[i] = writearray[i];
	*readingLength = callLength;
}

void WriteBusSPI33(byte *parameters)
{
	// WriteSPI(readarray, callLength, spi33slavePin, setSPI33, delayTime, iterNum);
	return;
}