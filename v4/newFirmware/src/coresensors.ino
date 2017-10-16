
void ReadTMP112()
{
	byte I2C_TMP112 = 0x48;
	byte TMP112_TEMP_REG = 0x00;

	byte testdata[2];
	WriteI2C(I2C_TMP112, TMP112_TEMP_REG);
	delay(100);
	ReadI2C(I2C_TMP112, *testdata);

	// if ((Temp_byte[0] & 0x80) == 0x00)
	// {
	// 	// it is a positive temperature
	// 	Temp_uint16 = Temp_byte[0];
	// 	Temp_uint16 = Temp_uint16 << 5;
	// 	Temp_uint16 = Temp_uint16 | (Temp_byte[1] >> 3);
	// 	Temp_float[0] = (Temp_uint16 & 0x0FFF) * 0.0625;
	// }
	// else
	// {
	// 	Temp_byte[0] = ~Temp_byte[0];
	// 	Temp_byte[1] = ~Temp_byte[1];
	// 	Temp_uint16 = Temp_byte[0];
	// 	Temp_uint16 = Temp_uint16 << 5;
	// 	Temp_uint16 = Temp_uint16 | (Temp_byte[1] >> 3);
	// 	Temp_float[0] = (Temp_uint16 & 0x0FFF)*-0.0625;
	// }
}

void ReadHTU21D()
{
	byte HTDU21D_ADDRESS = 0x40;
	byte TRIGGER_TEMP_MEASURE_NOHOLD = 0xF3;
	byte TRIGGER_HUMD_MEASURE_NOHOLD = 0xF5;

	// Read Temprature
	byte testdata[3];
	WriteI2C(HTDU21D_ADDRESS, TRIGGER_TEMP_MEASURE_NOHOLD);
	//Hang out while measurement is taken. 50mS max, page 4 of datasheet.
	delay(55);
	//Comes back in three bytes, data(MSB) / data(LSB) / Checksum
	ReadI2C(HTDU21D_ADDRESS, *testdata);

	//Request a humidity reading
	WriteI2C(HTDU21D_ADDRESS, TRIGGER_HUMD_MEASURE_NOHOLD);
	//Hang out while measurement is taken. 50mS max, page 4 of datasheet.
	delay(55);
	//Comes back in three bytes, data(MSB) / data(LSB) / Checksum
	ReadI2C(HTDU21D_ADDRESS, *testdata);
}

#define PIN_HIH4030 A10
void HIH4030()
{
	int value = analogRead(PIN_HIH4030);	
}

void BMP180()
{
	byte BMP085_ADDRESS = 0x77;
	byte BMP085_REGISTER_CONTROL = 0xF4;
	byte BMP085_REGISTER_TEMPDATA = 0xF6;
	byte BMP085_REGISTER_PRESSUREDATA = 0xF6;
	byte BMP085_REGISTER_READTEMPCMD = 0x2E;
	byte BMP085_REGISTER_READPRESSURECMD = 0x34;
	// Read temprature
	byte testdata[2] = {BMP085_REGISTER_CONTROL, BMP085_REGISTER_READTEMPCMD};
	byte testval;
	WriteI2C(BMP085_ADDRESS, *testdata);
	delay(5);
	ReadI2C(BMP085_REGISTER_TEMPDATA, testval);static void readRawPressure(int32_t *pressure)

	// Read pressure
	int _bmp085Mode = 3;

	byte reg = BMP085_REGISTER_READPRESSURECMD + (_bmp085Mode << 6)
	WriteI2C(BMP085_REGISTER_CONTROL, reg);
	delay(26);
	WriteI2C(BMP085_ADDRESS, BMP085_REGISTER_PRESSUREDATA);
	ReadI2C(BMP085_ADDRESS, *testdata);
	// we even do not need this:
	// int pressure = (testdata[0] << 8) | testdata[1];

	WriteI2C(BMP085_ADDRESS, BMP085_REGISTER_PRESSUREDATA+2);
	ReadI2C(BMP085_ADDRESS, *testdata);
}

#define A2D_PRJ103J2 0
void PR103J2()
{
	int PR = analogRead(A2D_PRJ103J2);
}

#define A2D_TSL250RDms 1
void TSL250ms()
{
	int TSL250_1 = analogRead(A2D_TSL250RDms);
}

void MMA()
{
	byte MMA8452_ADDRESS = 0x1C;
	byte OUT_X_MSB = 0x01;
	byte XYZ_DATA_CFG = 0x0E;
	byte WHO_AM_I = 0x0D;
	byte CTRL_REG1 = 0x2A;

	byte rawData[6];  // x/y/z accel register data stored here

	WriteI2C(OUT_X_MSB, *rawData);
	// MMA8452readRegisters(OUT_X_MSB, 6, rawData);  // Read the six raw data registers into data array

	// // Loop to calculate 12-bit ADC and g value for each axis
	// for(i = 0; i < 3 ; i++)
	// {
	// 	gCount = (rawData[i * 2] << 8) | rawData[(i * 2) + 1];  //Combine the two 8 bit registers into one 12-bit number
	// 	gCount >>= 4; //The registers are left align, here we right align the 12-bit integer

	// 	// If the number is negative, we have to make it so manually (no 12-bit data type)
	// 	if (rawData[i * 2] > 0x7F)
	// 		gCount -= 0x1000;

	// destination[i] = gCount; //Record this gCount into the 3 int array
	// }


}

#define PIN_SPV_AMP A5
#define PIN_SPV_SPL A6
#define PIN_RAW_MIC A9
void SPV()
{
	byte buff[128];
	for (int i = 0; i < 128; i++)
		buff = analogRead(PIN_RAW_MIC);
}

void TSYS01()
{
	byte TSYS01Address = 0x76;
	byte TSYS01StartReg = 0x48; //commands sensor to begin measurement / output calculation
	byte TSYS01TempReg = 0x00; //requests most recent output from measurement

	byte testdata[2];
	WriteI2C(TSYS01Address, TSYS01StartReg);
	delay(10);
	WriteI2C(TSYS01Address, TSYS01TempReg);
	ReadI2C(TSYS01Address, *testdata);
}

void HMC()
{
	byte HMC5883_ADDRESS_MAG = 0x3C >> 1;  // 0011110x
	byte HMC5883_REGISTER_MAG_OUT_X_H_M = 0x03;

	byte testdata[6];
	WriteI2C(HMC5883_ADDRESS_MAG, HMC5883_REGISTER_MAG_OUT_X_H_M);
	ReadI2C(HMC5883_ADDRESS_MAG, *testdata);
}

void HIH6130()
{
	byte HIH_ADDRESS = 0x27;
	byte testdata[4];

	BeginEndI2C(HIH_ADDRESS);
	delay(100);
	ReadI2C(HIH_ADDRESS, *testdata);

	// Temp_byte[0] = (Temp_byte[1] >> 6) & 0x03;

	// Temp_byte[1] = Temp_byte[1] & 0x3f;
	// Temp_int[0] = (((unsigned int)Temp_byte[1]) << 8) | Temp_byte[2];

	// Temp_int[1] = (((unsigned int)Temp_byte[3]) << 8) | Temp_byte[4];
	// Temp_int[1] = Temp_int[1] / 4;

	// Temp_float[1] = (float) Temp_int[0] * 6.10e-3;
	// Temp_float[0] = (float) Temp_int[1] * 1.007e-2 - 40.0;
}

void APDS()
{
	mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	int APDS = mcp3428_2.readADC();
}

void TSL260RD()
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
	int TSL260 = mcp3428_1.readADC();
}

void TSL250RDls()
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
	int TSL250_2 = mcp3428_1.readADC();
}

void MLX()
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	int MLX = mcp3428_1.readADC();
}

void ML8511()
{
	mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
	int ML8511 = mcp3428_1.readADC();
}

void TMP421()
{
	char TMP421_ADDRESS = 0x4c;
	byte testdata[2];
	WriteI2C(TMP421_ADDRESS, char(0x00));
	ReadI2C(TMP421_ADDRESS, testdata[0]); // high-byte

	WriteI2C(TMP421_ADDRESS, char(0x10));
	ReadI2C(TMP421_ADDRESS, testdata[1]); // low-byte
}

void Chem()
{
	char buff[1024];
	int numbytes = 0;
	ReadRS232(buff, numbytes);
}

void Alpha()
{
	
}

