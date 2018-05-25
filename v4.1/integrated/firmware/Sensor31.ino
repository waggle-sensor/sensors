// Alpha sensor configuration

void InitSensor31()
{
	return;
}

void ConfigSensor31()
{
	return;
}

void EnableSensor31()
{
	return;
}

void DisableSensor31()
{
	return;
}

void ReadSensor31(byte *sensorReading, int *readingLength)
{
	SerialUSB.print("Start sending Alpha sensor configuration");
	delay(1000);
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x3C);   // 0xF3
	delay(10);

	byte returnbyte;
	for (int i = 0; i < 256; i++)
	{
		returnbyte = SPI.transfer(0x3C);
		delay(10);
		SerialUSB.write(returnbyte);
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
	SerialUSB.print("End sending Alpha sensor configuration");
	SerialUSB.println("");
}

void WriteSensor31(byte *packet)
{
	return;
}
