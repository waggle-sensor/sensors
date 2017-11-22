// Alpha sensor reading through bus functions

SPISettings setSPI40;
byte spi40slavePin = 0x40;

void InitBusSPI40(byte *parameters)
{
	long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
	byte type = parameters[3];
	byte mode = parameters[4];

	// set SPI params, begin device
	setSPI40 = SetSPI(maxCommunicationSpeed, type, mode, spi40slavePin);
}

void ConfigBusSPI40(byte *parameters)
{
	return;
}

void EnableBusSPI40()
{
	return;
}

void DisableBusSPI40()
{
	return;
}

void ReadBusSPI40(byte *parameters, byte *sensorReading, int *readingLength)
{
	int callLength = parameters[0];

	byte writearray[callLength];
	for (int i = 0; i < callLength; i++)
		writearray[i] = parameters[1];

	ReadSPI(writearray, callLength, spi40slavePin, setSPI40, 10, 1);

	for (int i = 0; i < callLength; i++)
		sensorReading[i] = writearray[i];
	*readingLength = callLength;
}

void WriteBusSPI40(byte *parameters)
{
	// WriteSPI(readarray, callLength, spi40slavePin, setSPI40, 10, 1);
	return;
}