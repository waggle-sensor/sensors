// TSYS01 Temperature sensor

#define TSYS01_ADDRESS 0x76
byte TSYS01_COEFFICIENTS[10];

void InitSensor09()
{
	byte writebyte[1] = {0x1E};
	WriteI2C(TSYS01_ADDRESS, 1, writebyte);
	delay(50);

	//gathers calibration coefficients to array
	byte readarray[2];
	for (int i = 0; i < 5; i++)
	{
		writebyte[0] = 0xA2 + (i * 2);
		WriteReadI2C(TSYS01_ADDRESS, 1, writebyte, 2, readarray);
		TSYS01_COEFFICIENTS[i * 2] = readarray[0];
		TSYS01_COEFFICIENTS[i * 2 + 1] = readarray[1];
		// int co = ((uint16_t)readarray[0] << 8) + readarray[1];

		// SerialUSB.print("TSYS ");
		// SerialUSB.println(co);
	}
}

void ConfigSensor09()
{
	return;
}

void EnableSensor09()
{
	EnableSensor(0x09);
}

void DisableSensor09()
{
	DisableSensor(0x09);
}

void ReadSensor09(byte *sensorReading, int *readingLength)
{
	const byte TSYS01StartReg = 0x48; //commands sensor to begin measurement / output calculation
	const byte TSYS01TempReg = 0x00; //requests most recent output from measurement

	byte writebyte[1] = {TSYS01StartReg};
	WriteI2C(TSYS01_ADDRESS, 1, writebyte);
	delay(10);
	writebyte[0] = {TSYS01TempReg};
	byte readarray[3];
	WriteReadI2C(TSYS01_ADDRESS, 1, writebyte, 3, readarray);
	// the last read is not used

	for (int i = 0; i < 3; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}

	// int startCoeff = *readingLength;
	// int a = sizeof(TSYS01_COEFFICIENTS);
	// for (int i = 0; i < a; i++)
	// {
	// 	sensorReading[startCoeff + i] = TSYS01_COEFFICIENTS[i];
	// 	*readingLength += 1;
	// }
}

void WriteSensor09(byte *packet)
{
	return;
}