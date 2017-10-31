
void InitSensors()
{
	// Metsense
	InitTMP112();
	InitBMP180();
	InitMMA();
	//Lightsense
	InitTSYS01();
	InitHMC();
	InitMCPmux();

	// initialize libraries
	// pinMode(PIN_RAW_MIC,INPUT); SPV sound level

}

void InitChemsense()
{
	// begin serial3
	Serial3.begin(115200);
	// set timeout of serial3 as 4 sec
	Serial3.setTimeout(4000);
	// set chemsense power power pin
	// pin for chemsense power is 47
	pinMode(47, OUTPUT);
	// power on the device --> LOW means power on
	// chemense power pin = 47
	digitalWrite(47, LOW);
	delay(500);
	ChemFWConfig();
}

void ChemFWConfig() // read one time, at setup
{
	byte totalReading[512];
	byte configReading[128];
	int numConfig = 0; // 0 - 9
	int readingLength = 0;
	int cum = 0;

	for (int i = 0; i < 65535; i++)
	{
		if (Serial3.available() > 2)
		{
			numConfig++;

			readingLength = Serial3.readBytesUntil('\n', configReading, 128);
			cum += readingLength;

			for (int j = 0; j < readingLength; j++)
				totalReading[cum + j] = configReading[j];

			// 47 times
			if (numConfig == 47)
				break;
		}
		delay(1);
	}

	for (int i = 0; i < 512; i++)
		SerialUSB.print(totalReading[i]);

	SerialUSB.println("");
}

// #define PIN_ALPHASENSE_SLAVE 33
// SPIsettings set1;
// void InitAlphasensor()
// {
// 	// begin SPI
// 	set1 = SPISettings(5000000, MSBFIRST, mode1);
// 	pinMode(33, OUTPUT);

// 	// SPI begin
// 	SPI.begin();
// 	delay(15000);

//     alphasense_on();
//     byte fanval = alpha_status();

//     SerialUSB.print(fanval);
//     SerialUSB.print("Alphasensor");
//     // fanval = 0x01; // This is when alpha sensor is off
//     while (fanval != 0x00)
//     {
//         alphasense_on();
//         fanval = alpha_status();
//         SerialUSB.println(fanval);
//         SerialUSB.println("Alphasensor");
//         delay(5000);
//     }
//     SerialUSB.print("on");
//     delay(1000);
// }

// void alphasense_on()
// {
// 	SPI.beginTransaction(set1);
// 	digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);

// 	val1 = SPI.transfer(0x03);
// 	delay(10);
// 	val2 = SPI.transfer(0x00);

// 	digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
// 	SPI.endTransaction();
// }

// void alpha_status()
// {
// 	SPI.beginTransaction(set1);
// 	digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);

// 	byte returnbyte;
// 	val1 = SPI.transfer(0xCF);
// 	SPI.endTransaction();
// }

void InitInterrupt()
{
	// pinMode(RAIN_INTERRUPT_PIN, INPUT_PULLUP);
	// attachInterrupt(digitalPinToInterrupt(RAIN_INTERRUPT_PIN), blink, RISING);
	// delay(5);
	// pin_signal = 0;
}

//** Metsense
void InitTMP112()
{
	byte I2C_TMP112 = 0x48;
	byte TMP112_CONFIG_REG = 0x01;
	byte TMP112_TEMP_REG = 0x00;

	byte writearray[3] = {TMP112_CONFIG_REG, 0x60, 0xB0};
	WriteI2C(I2C_TMP112, 3, writearray);
	delay(100);

	byte writebyte[1] = {TMP112_CONFIG_REG};
	WriteI2C(I2C_TMP112, 1, writebyte);
	delay(100);

	byte readarray[2];
	ReadI2C(I2C_TMP112, 2, readarray);
}

void InitBMP180()
{
	byte BMP180_REGISTER_CHIPID = 0xD0;
	byte BMP180_ADDRESS = 0x77;
	byte writebyte[1] = {BMP180_REGISTER_CHIPID};
	//** ultra high resolution
	int _bmp180Mode = 3;

	// make sure we have the right device
	byte id[1];
	WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 1, id);
	if (id[1] != 0x55)
		byte BMP180_validity = 0;

	// read coefficients
	byte BMP180register[11] = {0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB6, 0xB8, 0xBA, 0xBC, 0xBE};
	byte BMP180coeff[11];

	byte temp_coeff[2];
	for (int i = 0; i < 11; i++)
	{
		writebyte[0] = BMP180register[i];
		WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 2, temp_coeff);
		BMP180coeff[i] = (temp_coeff[0] << 8) | temp_coeff[1];
	}
	// read coefficients, R   Calibration data (16 bits)
	// byte BMP085_REGISTER_CAL_AC1 = 0xAA;
	// byte BMP085_REGISTER_CAL_AC2 = 0xAC;
	// byte BMP085_REGISTER_CAL_AC3 = 0xAE;
	// byte BMP085_REGISTER_CAL_AC4 = 0xB0;
	// byte BMP085_REGISTER_CAL_AC5 = 0xB2;
	// byte BMP085_REGISTER_CAL_AC6 = 0xB4;
	// byte BMP085_REGISTER_CAL_B1 = 0xB6;
	// byte BMP085_REGISTER_CAL_B2 = 0xB8;
	// byte BMP085_REGISTER_CAL_MB = 0xBA;
	// byte BMP085_REGISTER_CAL_MC = 0xBC;
	// byte BMP085_REGISTER_CAL_MD = 0xBE;

	// byte bmp085_coeffs_ac1;
	// byte bmp085_coeffs_ac2;
	// byte bmp085_coeffs_ac3;
	// byte bmp085_coeffs_ac4;
	// byte bmp085_coeffs_ac5;
	// byte bmp085_coeffs_ac6;
	// byte bmp085_coeffs_b1;
	// byte bmp085_coeffs_b2;
	// byte bmp085_coeffs_mb;
	// byte bmp085_coeffs_mc;
	// byte bmp085_coeffs_md;
}

void InitMMA()
{
	byte MMA8452_ADDRESS = 0x1C;
	byte XYZ_DATA_CFG = 0x0E;
	byte CTRL_REG1 = 0x2A;
	byte WHO_AM_I = 0x0D;
	byte GSCALE = 2;
	// Sets full-scale range to +/-2, 4, or 8g

	//** check if the sensor is correct
	byte writebyte[1] = {WHO_AM_I};
	byte id[1];
	WriteReadI2C(MMA8452_ADDRESS, 1, writebyte, 1, id, false);
	if (id[0] != 0x2A) // WHO_AM_I should always be 0x2A
		byte MMA8452_validity = 0;

	//*** sensor stand by
	byte readbyte[1];
	writebyte[0] = CTRL_REG1;
	WriteReadI2C(MMA8452_ADDRESS, 1, writebyte, 1, readbyte, false);
	// Clear the active bit to go into standby 
	byte writearray[2] = {CTRL_REG1, readbyte[0] & ~(0x01)};
	WriteI2C(MMA8452_ADDRESS, 2, writearray);

	//** Set up the full scale range to 2, 4, or 8g.
	byte fsr = GSCALE;
	if(fsr > 8) 
		fsr = 8; //Easy error check
	// Neat trick, see page 22. 00 = 2G, 01 = 4A, 10 = 8G
	fsr >>= 2;
	
	//** set up accelerometer scale as 2G, default data rate 800Hz
	writearray[0] = XYZ_DATA_CFG;
	writearray[1] = fsr;
	WriteI2C(MMA8452_ADDRESS, 2, writearray);

	//*** active sensor--> Set the active bit to begin detection
	writebyte[0] = CTRL_REG1;
	WriteReadI2C(MMA8452_ADDRESS, 1, writebyte, 1, readbyte, false);
	writearray[0] = CTRL_REG1;
	writearray[1] = readbyte[0] | 0x01;
	WriteI2C(MMA8452_ADDRESS, 2, writearray);
}

//** Lightsense
void InitTSYS01()
{
	byte TSYS01Address = 0x76;
	byte writebyte[1] = {0x1E};
	WriteI2C(TSYS01Address, 1, writebyte);
	delay(50);

	//gathers calibration coefficients to array
	byte readarray[2];
	int TSYScoefficents[5];
	for (int i = 0; i < 5; i++)
	{
		writebyte[0] = 0xA2 + (i * 2);
		WriteReadI2C(TSYS01Address, 1, writebyte, 2, readarray);
		TSYScoefficents[i] = ((uint16_t)readarray[0] << 8) + readarray[1];
	}

}

void InitHMC()
{
	byte HMC5883_ADDRESS_MAG = 0x3C >> 1;  // 0011110x

	byte HMC5883_REGISTER_MAG_CRB_REG_M = 0x01;
	byte HMC5883_REGISTER_MAG_MR_REG_M = 0x02;

	// Enable the magnetometer
	byte testarray[2] = {HMC5883_REGISTER_MAG_MR_REG_M, 0x00};
	WriteI2C(HMC5883_ADDRESS_MAG, 2, testarray);

	//** Set the gain to a known level
	byte gain = 0x20;
	testarray[0] = HMC5883_REGISTER_MAG_CRB_REG_M;
	testarray[1] = gain;
	WriteI2C(HMC5883_ADDRESS_MAG, 2, testarray);
	// _magGain = gain;

	//** TODO: Where to store, how to send, sensor ID?????
	int coefficient_Gauss_LSB_XY = 1100;
	int coefficient_Gauss_LSB_Z  = 980;
}

void InitMCPmux()
{
	mcp3428_1.init(MCP342X::L, MCP342X::L);
	mcp3428_2.init(MCP342X::L, MCP342X::F);
}

void blink()
{
	// pin_signal++;
	// if (pin_signal == 2)
	// {
	// 	count_num++;
	// 	pin_signal = 0;
	// }
}