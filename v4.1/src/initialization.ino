

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

	InitAnalogSensors();
	// initialize libraries
	// pinMode(PIN_RAW_MIC,INPUT); SPV sound level

}

void InitAnalogSensors()
{
	pinMode(HBT_PIN, OUTPUT);
	pinMode(SPV_AMP_PIN,INPUT);         // MODE ON?????????? WHERE????????????? HOW???????????? WHEN???????????
	pinMode(SPV_SPL_PIN,INPUT);
	pinMode(SPV_RAW_MIC_PIN,INPUT);

}

//** Metsense
void InitTMP112()
{
	const byte TMP112_CONFIG_REG = 0x01;
	// const byte TMP112_TEMP_REG = 0x00;

	byte writearray[3] = {TMP112_CONFIG_REG, 0x60, 0xB0};
	WriteI2C(TMP112_ADDRESS, 3, writearray);
	delay(100);

	byte writebyte[1] = {TMP112_CONFIG_REG};
	WriteI2C(TMP112_ADDRESS, 1, writebyte);
	delay(100);

	byte readarray[2];
	ReadI2C(TMP112_ADDRESS, 2, readarray);
}

void InitBMP180()
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

	// read coefficients
	byte BMP180register[11] = {0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB6, 0xB8, 0xBA, 0xBC, 0xBE};

	byte temp_coeff[2];
	for (int i = 0; i < 11; i++)
	{
		writebyte[0] = BMP180register[i];
		WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 2, temp_coeff);
		BMP180_COEFFICIENTS[i * 2] = temp_coeff[0];
		BMP180_COEFFICIENTS[i * 2 + 1] = temp_coeff[1];
		// BMP180_COEFFICIENTS[i] = (temp_coeff[0] << 8) | temp_coeff[1];
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
	const byte XYZ_DATA_CFG = 0x0E;
	const byte CTRL_REG1 = 0x2A;
	// const byte WHO_AM_I = 0x0D;
	const byte GSCALE = 2;
	// Sets full-scale range to +/-2, 4, or 8g


	// //** check if the sensor is correct
	// byte writebyte[1] = {WHO_AM_I};
	// byte id[1];
	// WriteReadI2C(MMA8452_ADDRESS, 1, writebyte, 1, id, false);
	// if (id[0] != 0x2A) // WHO_AM_I should always be 0x2A
	// 	byte MMA8452_validity = 0;

	//*** sensor stand by
	byte readbyte[1];
	byte writebyte[1] = {CTRL_REG1};
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

void InitTSYS01()
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
		// TSYS01_COEFFICIENTS[i] = ((uint16_t)readarray[0] << 8) + readarray[1];
	}

}

//** Lightsense
void InitHMC()
{
	const byte HMC5883_REGISTER_MAG_CRB_REG_M = 0x01;
	const byte HMC5883_REGISTER_MAG_MR_REG_M = 0x02;

	// Enable the magnetometer
	byte testarray[2] = {HMC5883_REGISTER_MAG_MR_REG_M, 0x00};
	WriteI2C(HMC5883_ADDESS, 2, testarray);

	//** Set the gain to a known level
	byte gain = 0x20;
	testarray[0] = HMC5883_REGISTER_MAG_CRB_REG_M;
	testarray[1] = gain;
	WriteI2C(HMC5883_ADDESS, 2, testarray);
	// _magGain = gain;

	//** TODO: Where to store, how to send, sensor ID?????
	int coefficient_Gauss_LSB_XY = 1100;
	int coefficient_Gauss_LSB_Z  = 980;

	HMC5883_COEFFICIENTS[0] = (coefficient_Gauss_LSB_XY >> 8) & 0xFF;
	HMC5883_COEFFICIENTS[1] = coefficient_Gauss_LSB_XY & 0xFF;
	HMC5883_COEFFICIENTS[2] = (coefficient_Gauss_LSB_Z >> 8) & 0xFF;
	HMC5883_COEFFICIENTS[3] = coefficient_Gauss_LSB_Z & 0xFF;
}

void InitMCPmux()
{
	mcp3428_1.init(MCP342X::L, MCP342X::L);
	MCP3428_1_ADDRESS = mcp3428_1.returnAddress();

	mcp3428_2.init(MCP342X::L, MCP342X::F);
	MCP3428_2_ADDRESS = mcp3428_2.returnAddress();
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

// Chemsense
void InitChemsense()
{
	Serial3.begin(115200);	// begin serial3
	Serial3.setTimeout(4000);	// set timeout of serial3 as 4 sec
	pinMode(CHEM_POWER_PIN, OUTPUT);  // pin for chemsense power is 47
	digitalWrite(CHEM_POWER_PIN, LOW); 	// power on the device --> LOW means power on
	delay(1000);

	if (Serial3.available() > 0)
	{
		int chemConfigLength = Serial3.readBytesUntil(36, chemConfigReading, 2048);

		for (int i = 0; i < chemConfigLength; i++)
			SerialUSB.print(chemConfigReading[i]);
	}
	else
	{
		Serial3.end();
		CallDisableCore(0x2A);
	}
	SerialUSB.println("");
}



void InitInterrupt()
{
	// pinMode(RAIN_INTERRUPT_PIN, INPUT_PULLUP);
	// attachInterrupt(digitalPinToInterrupt(RAIN_INTERRUPT_PIN), blink, RISING);
	// delay(5);
	// pin_signal = 0;
}
