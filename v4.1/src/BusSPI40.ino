// Chem sensor reading through bus functions

SPISettings setSPI40;
byte spi40SlavePin;

void InitBusSPI40(byte *parameters)
{
	spi40SlavePin = parameters[0];
	long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
	byte type = parameters[3];
	byte mode = parameters[4];

	// set SPI params, begin device
	setSPI40 = SetSPI(maxCommunicationSpeed, type, mode, spi40SlavePin);
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
	int paramLength = parameters[0] & 0x7F;
	byte writearray[paramLength];
	if (int(sizeof(parameters)) > paramLength)
	{
		for (int i = 0; i < paramLength; i++)
			writearray[i] = parameters[i + 2];
	}
	else
	{
		for (int i = 0; i < paramLength; i++)
			writearray[i] = parameters[2];
	}
	ReadSPI(writearray, paramLength, spi40SlavePin, setSPI40, 10, 1);

	for (int i = 0; i < paramLength; i++)
		sensorReading[i] = writearray[i];
	*readingLength = paramLength;
}

void WriteBusSPI40(byte *parameters)
{
	// WriteSPI(readarray, paramLength, spi40SlavePin, setSPI40, 10, 1);
	return;
}