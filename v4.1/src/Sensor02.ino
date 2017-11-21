// HTU21D Temperature and relative humidity sensor

void InitSensor02()
{
	return;
}

void ConfigSensor02()
{
	return;
}

void EnableSensor02()
{
	EnableSensor(0x02);
}

void DisableSensor02()
{
	DisableSensor(0x02);
}

void ReadSensor02(byte *sensorReading, int *readingLength)
{
	const byte TRIGGER_TEMP_MEASURE_NOHOLD = 0xF3;
	const byte TRIGGER_HUMD_MEASURE_NOHOLD = 0xF5;

	// Read Temprature, Hang out while measurement is taken 50mS max
	byte readarray[3];
	byte writebyte[1] = {TRIGGER_TEMP_MEASURE_NOHOLD};
	WriteReadI2C(HTDU21D_ADDRESS, 1, writebyte, 3, readarray, 55);

	int raw = (readarray[0] << 8) | readarray[1];
	if (check_crc(raw, int(readarray[2])) != 0)
	{
		readarray[0] = 0xFF;
		readarray[1] = 0xFF;
	}

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}

	//Request a humidity reading
	writebyte[0] = TRIGGER_HUMD_MEASURE_NOHOLD;
	WriteReadI2C(HTDU21D_ADDRESS, 1, writebyte, 3, readarray, 55);

	raw = (readarray[0] << 8) | readarray[1];
	if (check_crc(raw, int(readarray[2])) != 0)
	{
		readarray[0] = 0xFF;
		readarray[1] = 0xFF;
	}

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i + 2] = readarray[i];
		*readingLength += 1;
	}
}

void WriteSensor02(byte *packet)
{
	return;
}


const int SHIFTED_DIVISOR = 0x988000;
byte check_crc(int message_from_sensor, int check_value_from_sensor)
{
	uint32_t remainder = (uint32_t)message_from_sensor << 8; //Pad with 8 bits because we have to add in the check value
	remainder |= check_value_from_sensor; //Add on the check value

	uint32_t divsor = (uint32_t)0x988000;

	for (int i = 0 ; i < 16 ; i++) //Operate on only 16 positions of max 24. The remaining 8 are our remainder and should be zero when we're done.
	{
	if( remainder & (uint32_t)1<<(23 - i) ) //Check if there is a one in the left position
		remainder ^= divsor;

	divsor >>= 1; //Rotate the divsor max 16 times so that we have 8 bits left of a remainder
	}

	return (byte)remainder;
}