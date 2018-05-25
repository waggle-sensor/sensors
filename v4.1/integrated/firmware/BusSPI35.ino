// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI35;
byte spi35slavePin = 0x35;

void InitBusSPI35(byte *parameters)
{
	long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
	byte type = parameters[3];
	byte mode = parameters[4];

	// set SPI params, begin device
	setSPI35 = SetSPI(maxCommunicationSpeed, type, mode, spi35slavePin);
}

void ConfigBusSPI35(byte *parameters)
{
	return;
}

void EnableBusSPI35()
{
	return;
}

void DisableBusSPI35()
{
	return;
}

void ReadBusSPI35(byte *parameters, byte *sensorReading, int *readingLength)
{
	int callLength = parameters[0];

	byte writearray[callLength];
	for (int i = 0; i < callLength; i++)
		writearray[i] = parameters[1];

	// User can put const parameters if necessary
	int delayTime = parameters[2];
	int iterNum = parameters[3];
	
	ReadSPI(writearray, callLength, spi35slavePin, setSPI35, delayTime, iterNum);

	for (int i = 0; i < callLength; i++)
		sensorReading[i] = writearray[i];
	*readingLength = callLength;
}

void WriteBusSPI35(byte *parameters)
{
	// WriteSPI(readarray, callLength, SPI35SlavePin, setSPI35, delayTime, iterNum);
	return;
}