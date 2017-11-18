// BMP180 Temperature and Barometric Pressure sensor

void InitSensor04()
{
	byte BMP180_REGISTER_CHIPID = 0xD0;
	byte writebyte[1] = {BMP180_REGISTER_CHIPID};
	//** ultra high resolution
	// int _bmp180Mode = 3;

	// // make sure we have the right device
	// byte id[1];
	// WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 1, id);
	// if (id[1] != 0x55)
	// 	byte BMP180_validity = 0;

	//** read coefficients
	byte BMP180register[11] = {0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB6, 0xB8, 0xBA, 0xBC, 0xBE};

	byte temp_coeff[2];
	for (int i = 0; i < 11; i++)
	{
		writebyte[0] = BMP180register[i];
		WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 2, temp_coeff);
		BMP180_COEFFICIENTS[i * 2] = temp_coeff[0];
		BMP180_COEFFICIENTS[i * 2 + 1] = temp_coeff[1];
		// uint16_t uco = (temp_coeff[0] << 8) | temp_coeff[1];
	}
}

void ConfigSensor04()
{
	return;
}

void EnableSensor04()
{
	EnableSensor(0x04);
}

void DisableSensor04()
{
	DisableSensor(0x04);
}

void ReadSensor04(byte *sensorReading, int *readingLength)
{
	const byte BMP180_REGISTER_CONTROL = 0xF4;
	const byte BMP180_REGISTER_TEMPDATA = 0xF6;
	const byte BMP180_REGISTER_PRESSUREDATA = 0xF6;
	const byte BMP180_REGISTER_READTEMPCMD = 0x2E;
	const byte BMP180_REGISTER_READPRESSURECMD = 0x34;

	// Read temprature
	byte writearray[2] = {BMP180_REGISTER_CONTROL, BMP180_REGISTER_READTEMPCMD};
	WriteI2C(BMP180_ADDRESS, 2, writearray);
	delay(5);
	byte writebyte[1] = {BMP180_REGISTER_TEMPDATA};
	byte readarray[2];
	WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 2, readarray);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}

	// Read pressure
	byte _bmp180Mode = 3;
	writearray[0] = BMP180_REGISTER_CONTROL;
	writearray[1] = BMP180_REGISTER_READPRESSURECMD + (_bmp180Mode << 6);
	WriteI2C(BMP180_ADDRESS, 2, writearray);
	delay(26);
	writebyte[0] = BMP180_REGISTER_PRESSUREDATA;
	WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 2, readarray);
	writebyte[0] = BMP180_REGISTER_PRESSUREDATA + 2;
	byte readbyte[1];
	WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 1, readbyte);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i + 2] = readarray[i];
		*readingLength += 1;
	}
	sensorReading[*readingLength] = readbyte[0];
	*readingLength += 1;

	// int startCoeff = *readingLength;
	// int a = sizeof(BMP180_COEFFICIENTS);
	// for (int i = 0; i < a; i++)
	// {
	// 	sensorReading[startCoeff + i] = BMP180_COEFFICIENTS[i];
	// 	*readingLength += 1;
	// }
}

void WriteSensor04(byte *sensorReading, int *readingLength)
{
	return;
}