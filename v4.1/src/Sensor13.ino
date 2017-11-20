// TMP421 Temperature sensor

void InitSensor13()
{
	return;
}

void ConfigSensor13()
{
	return;
}

void EnableSensor13()
{
	EnableSensor(0x13);
}

void DisableSensor13()
{
	DisableSensor(0x13);
}

void ReadSensor13(byte *sensorReading, int *readingLength)
{
	byte readbyte[1];
	
	// high-byte
	setPtrLoc(0x00);
	byte writebyte[1] = {0x13};
	WriteReadI2C(TMP421_ADDRESS, 1, writebyte, 1, readbyte);

	sensorReading[0] = readbyte[0];
	*readingLength += 1;

	// low-byte
	setPtrLoc(0x10);
	writebyte[0] = 0x10;
	WriteReadI2C(TMP421_ADDRESS, 1, writebyte, 1, readbyte);

	sensorReading[1] = readbyte[0];
	*readingLength += 1;

	// byte testdata[2];
	// WriteI2C(TMP421_ADDRESS, char(0x13));
	// ReadI2C(TMP421_ADDRESS, testdata[0]); // high-byte

	// WriteI2C(TMP421_ADDRESS, char(0x10));
	// ReadI2C(TMP421_ADDRESS, testdata[1]); // low-byte
}

void WriteSensor13(byte *sensorReading, int *readingLength)
{
	return;
}

void setPtrLoc(uint8_t ptrLoc) {

    //Set the pointer location
    Wire.beginTransmission(TMP421_ADDRESS);   //begin
    Wire.write(ptrLoc);             //send the pointer location
    Wire.endTransmission();         //end
    delay(8);
}
