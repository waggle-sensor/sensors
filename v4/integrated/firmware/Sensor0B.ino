	
// HIH6130 Temperature and relative humidity sensor

#define HIH6130_ADDRESS 0x27

void InitSensor0B()
{
	return;
}

void ConfigSensor0B()
{
	return;
}

void EnableSensor0B()
{
	EnableSensor(0x0B);
}

void DisableSensor0B()
{
	DisableSensor(0x0B);
}

void ReadSensor0B(byte *sensorReading, int *readingLength)
{
	byte readarray[4];
	Wire.beginTransmission(HIH6130_ADDRESS);
    Wire.endTransmission();
    delay(100);

	DirectReadI2C(HIH6130_ADDRESS, 4, readarray, 10);
	Wire.endTransmission();
	// 14 bit Register reading for both humidity and temperature
	// two humidity bytes (first two bytes reading), two temperature bytes (last two bytes reading)
	// last two bits of first byte are status bits (humidity bytes)
	// first two bits of last byte are empty bits (temperature bytes)

	// if first two bits of the humidity byte is 01 then
	// --> This can happen when the Master polls the data quicker than the sensor can update the output buffer
	// 00 --> normal operate

	for (int i = 0; i < 4; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}
}

void WriteSensor0B(byte *packet)
{
	return;
}