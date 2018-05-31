// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI34;
byte spi34slavePin = 0x34;

void InitBusSPI34(byte *parameters)
{
	long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
	byte type = parameters[3];
	byte mode = parameters[4];

	// set SPI params, begin device
	setSPI34 = SetSPI(maxCommunicationSpeed, type, mode, spi34slavePin);
}

void ConfigBusSPI34(byte *parameters)
{
	return;
}

void EnableBusSPI34()
{
	return;
}

void DisableBusSPI34()
{
	return;
}

void ReadBusSPI34(byte *parameters, byte *sensorReading, int *readingLength)
{
	int callLength = parameters[0];

	byte writearray[callLength];
	for (int i = 0; i < callLength; i++)
		writearray[i] = parameters[1];

	// User can put const parameters if necessary
	int delayTime = parameters[2];
	int iterNum = parameters[3];
	
	ReadSPI(writearray, callLength, spi34slavePin, setSPI34, delayTime, iterNum);

	for (int i = 0; i < callLength; i++)
		sensorReading[i] = writearray[i];
	*readingLength = callLength;
}

void WriteBusSPI34(byte *parameters)
{
	// WriteSPI(readarray, callLength, SPI34SlavePin, setSPI34, delayTime, iterNum);
	return;
}