// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI39;
byte spi39slavePin = 0x39;

void InitBusSPI39(byte *parameters)
{
	long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
	byte type = parameters[3];
	byte mode = parameters[4];

	// set SPI params, begin device
	setSPI39 = SetSPI(maxCommunicationSpeed, type, mode, spi39slavePin);
}

void ConfigBusSPI39(byte *parameters)
{
	return;
}

void EnableBusSPI39()
{
	return;
}

void DisableBusSPI39()
{
	return;
}

void ReadBusSPI39(byte *parameters, byte *sensorReading, int *readingLength)
{
	int callLength = parameters[0];

	byte writearray[callLength];
	for (int i = 0; i < callLength; i++)
		writearray[i] = parameters[1];

	// User can put const parameters if necessary
	int delayTime = parameters[2];
	int iterNum = parameters[3];

	ReadSPI(writearray, callLength, spi39slavePin, setSPI39, delayTime, iterNum);

	for (int i = 0; i < callLength; i++)
		sensorReading[i] = writearray[i];
	*readingLength = callLength;
}

void WriteBusSPI39(byte *parameters)
{
	// WriteSPI(readarray, callLength, SPI39SlavePin, setSPI39, delayTime, iterNum);
	return;
}