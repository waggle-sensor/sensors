// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI36;
byte spi36slavePin = 0x36;

void InitBusSPI36(byte *parameters)
{
	long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
	byte type = parameters[3];
	byte mode = parameters[4];

	// set SPI params, begin device
	setSPI36 = SetSPI(maxCommunicationSpeed, type, mode, spi36slavePin);
}

void ConfigBusSPI36(byte *parameters)
{
	return;
}

void EnableBusSPI36()
{
	return;
}

void DisableBusSPI36()
{
	return;
}

void ReadBusSPI36(byte *parameters, byte *sensorReading, int *readingLength)
{
	int callLength = parameters[0];

	byte writearray[callLength];
	for (int i = 0; i < callLength; i++)
		writearray[i] = parameters[1];

	// User can put const parameters if necessary
	int delayTime = parameters[2];
	int iterNum = parameters[3];
	
	ReadSPI(writearray, callLength, spi36slavePin, setSPI36, delayTime, iterNum);

	for (int i = 0; i < callLength; i++)
		sensorReading[i] = writearray[i];
	*readingLength = callLength;
}

void WriteBusSPI36(byte *parameters)
{
	// WriteSPI(readarray, callLength, SPI36SlavePin, setSPI36, delayTime, iterNum);
	return;
}