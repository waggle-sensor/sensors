
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
	delay(10);
}

void InitAlphasensor()
{
	// begin SPI
	SPI.begin();
	delay(10);

	// need to think about time interval
	// alphasense_on();
	// delay(10000);
}

//** Metsense
void InitTMP112()
{
	byte I2C_TMP112 = 0x48;
	byte TMP112_CONFIG_REG = 0x01;
	byte TMP112_TEMP_REG = 0x00;

	byte testarray[3] = {TMP112_CONFIG_REG, 0x60, 0xB0};
	WriteI2C(I2C_TMP112, *testarray);
	delay(100);
	WriteI2C(I2C_TMP112, TMP112_CONFIG_REG);
	delay(100);
	byte testdata[2];
	ReadI2C(I2C_TMP112, *testdata);
}

void InitBMP180()
{
	byte BMP085_REGISTER_CHIPID = 0xD0;
	//** ultra high resolution
	int _bmp085Mode = 3;

	// make sure we have the right device
	int id;
	ReadI2C(BMP085_REGISTER_CHIPID, id);
	if (id != 0x55)
		byte BMP180_validity = 0;

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

	byte BMP085_ADDRESS = 0x77;

	byte BMP180register[11] = {0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB6, 0xB8, 0xBA, 0xBC, 0xBE};
	byte BMP180coeff[11];
	byte temp_coeff[2];

	for (int i = 0; i < 11; i++)
	{
		WriteI2C(BMP085_ADDRESS, BMP180register[i]);
		ReadI2C(BMP085_ADDRESS, *temp_coeff);
		BMP180coeff[i] = (temp_coeff[0] << 8) | temp_coeff[1];
	}
}

void InitMMA()
{
	byte MMA8452_ADDRESS = 0x1C;
	byte XYZ_DATA_CFG = 0x0E;
	byte CTRL_REG1 = 0x2A;
	byte GSCALE = 2;
	//** Sets full-scale range to +/-2, 4, or 8g
	//** Used to calc real g values.

	byte temp_coeff;
	//*** sensor stand by
	ReadI2C(CTRL_REG1, temp_coeff);
	WriteI2C(CTRL_REG1, temp_coeff & ~(0x01));
	//** Clear the active bit to go into standby 

	// Set up the full scale range to 2, 4, or 8g.
	byte fsr = GSCALE;
	if(fsr > 8) 
	    fsr = 8; //Easy error check

	fsr >>= 2;
	// Neat trick, see page 22. 00 = 2G, 01 = 4A, 10 = 8G
	byte testarray[2] = {XYZ_DATA_CFG, fsr};
	WriteI2C(MMA8452_ADDRESS, *testarray);

	//** active sensor
	//** The default data rate is 800Hz
	//** and we don't modify it in this example code
	ReadI2C(MMA8452_ADDRESS, temp_coeff);
	//** Read a single byte from addressToRead
	//** and return it as a byte
	//** Set the active bit to begin detection
	WriteI2C(CTRL_REG1, temp_coeff|0x01);
}

//** Lightsense
void InitTSYS01()
{
	byte TSYS01Address = 0x76;
	WriteI2C(TSYS01Address, 0x1E);
	delay(50);

	int TSYS_coefficents[5];
	int temp_coeff[2];

	//gathers calibration coefficients to array
	for (uint8_t n = 0; n < 5; n++)
	{
		byte reg = 0xA2 + (n * 2);
		WriteI2C(TSYS01Address, reg);
		ReadI2C(TSYS01Address, *temp_coeff);
		TSYS_coefficents[n] = (temp_coeff[0] << 8) + temp_coeff[1];
	}

}

void InitHMC()
{
	byte HMC5883_ADDRESS_MAG = 0x3C >> 1;  // 0011110x

	byte HMC5883_REGISTER_MAG_CRB_REG_M = 0x01;
	byte HMC5883_REGISTER_MAG_MR_REG_M = 0x02;

	// Enable the magnetometer
	char testarray[2] = {HMC5883_REGISTER_MAG_MR_REG_M, 0x00};
	WriteI2C(HMC5883_ADDRESS_MAG, *testarray);

	//** Set the gain to a known level
	char gain = 0x20;
	testarray[0] = HMC5883_REGISTER_MAG_CRB_REG_M;
	testarray[1] = gain;
	WriteI2C(HMC5883_ADDRESS_MAG, *testarray);
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
