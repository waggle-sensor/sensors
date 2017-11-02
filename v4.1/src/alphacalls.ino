
void alphasense_on()
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	val1 = SPI.transfer(0x03);
	delay(10);
	val2 = SPI.transfer(0x00);

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void alpha_status()
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	byte returnbyte;
	val1 = SPI.transfer(0xCF);
	SPI.endTransaction();
}

// // Alphasense
// byte alphaReading[256];
// void ReadAlphaHisto()
// {
// 	SPI.beginTransaction(set1);
// 	digitalWrite(33, LOW);
// 	delay(100);

// 	SPI.transfer(0x30);   // 0xF3
// 	delay(100);

// 	for (i = 0; i < 62; i++)
// 	{
// 		alphaReading[i] = SPI.transfer(0x30);
// 		delay(100);
// 	}

// 	digitalWrite(33, HIGH);
// 	SPI.endTransaction();	
// }

// void ReadAlphaSerial()
// {
// 	SPI.beginTransaction(set1);
// 	digitalWrite(33, LOW);
// 	delay(100);

// 	SPI.transfer(0x10);    // 0xF3
// 	delay(100);

// 	for (i = 0; i < 20; i++)
// 	{
// 	    alphaReading[i] = SPI.transfer(0x10);
// 	    delay(100);
// 	}

// 	digitalWrite(33, HIGH);
// 	SPI.endTransaction();
// }

// void ReadAlphaFWver()
// {
// 	SPI.beginTransaction(set1);
// 	digitalWrite(33, LOW);
// 	delay(100);

// 	SPI.transfer(0x12);    // 0xF3
// 	delay(100);

// 	alphaReading[0] = SPI.transfer(0x12);
// 	delay(100);
// 	alphaReading[1] = SPI.transfer(0x12);
// 	delay(100);

// 	digitalWrite(33, HIGH);
// 	SPI.endTransaction();
// }

// void ReadAlphaConfig()
// {
// 	SPI.beginTransaction(set1);
// 	digitalWrite(33, LOW);
// 	delay(100);

// 	SPI.transfer(0x3C);   // 0xF3
// 	delay(100);

// 	for (i = 0; i < 256; i++)
// 	{
// 		alphaReading[i] = SPI.transfer(0x3C);
// 		delay(100);
// 	}

// 	digitalWrite(33, HIGH);
// 	SPI.endTransaction();

// }