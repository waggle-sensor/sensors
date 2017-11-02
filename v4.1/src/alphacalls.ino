

void InitAlphasensor()
{
	// begin SPI
	setAlpha = SPISettings(5000000, MSBFIRST, SPI_MODE1);
	pinMode(ALPHA_SLAVE_PIN, OUTPUT);

	// SPI begin
	SPI.begin();
	delay(1000);

	alphasense_on();
	byte returnbyte = alpha_status();

	// SerialUSB.print(returnbyte);
	// SerialUSB.print("Alphasensor");
	// returnbyte = 0x01; // This is when alpha sensor is off
	int repeat = 0;
	while ((returnbyte != 0x31) && (repeat < 10))
	{
		repeat++;
		alphasense_on();
		// returnbyte = alpha_status();
		// SerialUSB.println(returnbyte);
		// SerialUSB.println("Alphasensor");
		delay(5000);
	}
	delay(1000);

	if (returnbyte == 0x31)
		Packetization(0x01, 0x30);
	else
		Packetization(0x00, 0x30);
}


// Alphasense
void alphasense_on()   // initialization
{
	byte val;
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	val = SPI.transfer(0x03);
	delay(10);
	val = SPI.transfer(0x00);

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

byte alpha_status()   // initialization
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	byte returnbyte;
	returnbyte = SPI.transfer(0xCF);
	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();

	return returnbyte;
}

void ReadAlphaHisto(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x30);   // 0xF3
	delay(10);

	for (int i = 0; i < 62; i++)
	{
		sensorReading[i] = SPI.transfer(0x30);
		*readingLength += 1;
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void ReadAlphaSerial(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x10);    // 0xF3
	delay(10);

	for (int i = 0; i < 20; i++)
	{
		sensorReading[i] = SPI.transfer(0x10);
		*readingLength += 1;
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void ReadAlphaFWver(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x12);    // 0xF3
	delay(10);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = SPI.transfer(0x12);
		delay(10);
		*readingLength += 1;
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void ReadAlphaConfig(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x3C);   // 0xF3
	delay(10);

	for (int i = 0; i < 256; i++)
	{
		sensorReading[i] = SPI.transfer(0x3C);
		delay(10);
		*readingLength += 1;
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();

}