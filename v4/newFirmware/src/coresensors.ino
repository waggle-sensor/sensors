

void ReadMacAdd()
{

}

void ReadTMP112()
{
	byte I2C_TMP112 = 0x48;
	byte TMP112_TEMP_REG = 0x00;

	byte writebyte[1] = {TMP112_TEMP_REG};
	byte readarray[2];
	WriteI2C(I2C_TMP112, 1, writebyte);
	delay(100);
	ReadI2C(I2C_TMP112, 2, readarray);

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

	// Read Temprature, Hang out while measurement is taken 50mS max
	byte readarray[3];
	byte writebyte[1] = {TRIGGER_TEMP_MEASURE_NOHOLD};
	WriteReadI2C(HTDU21D_ADDRESS, 1, writebyte, 3, readarray, 55);
	
	//Request a humidity reading
	writebyte[0] = TRIGGER_HUMD_MEASURE_NOHOLD;
	WriteReadI2C(HTDU21D_ADDRESS, 1, writebyte, 3, readarray, 55);
}

#define PIN_HIH4030 A10
void ReadHIH4030()
{
	int value = analogRead(PIN_HIH4030);	
}

void ReadBMP180()
{
	byte BMP180_ADDRESS = 0x77;
	byte BMP180_REGISTER_CONTROL = 0xF4;
	byte BMP180_REGISTER_TEMPDATA = 0xF6;
	byte BMP180_REGISTER_PRESSUREDATA = 0xF6;
	byte BMP180_REGISTER_READTEMPCMD = 0x2E;
	byte BMP180_REGISTER_READPRESSURECMD = 0x34;
	// Read temprature
	byte writearray[2] = {BMP180_REGISTER_CONTROL, BMP180_REGISTER_READTEMPCMD};
	WriteI2C(BMP180_ADDRESS, 2, writearray);
	delay(5);
	byte writebyte[1] = {BMP180_REGISTER_TEMPDATA};
	byte readarray[2];
	WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 1, readarray);

	// Read pressure
	byte _bmp180Mode = 3;
	writebyte[0] = BMP180_REGISTER_CONTROL;
	writebyte[1] = BMP085_REGISTER_READPRESSURECMD + (_bmp085Mode << 6);
	WriteI2C(BMP085_ADDRESS, 2, writebyte);
	delay(26);
	writebyte[0] = BMP085_REGISTER_PRESSUREDATA;
	WriteReadI2C(BMP085_ADDRESS, 1, writebyte, 2, readarray);
	writebyte[0] = BMP085_REGISTER_PRESSUREDATA + 2;
	byte readbyte[1];
	WriteReadI2C(BMP085_ADDRESS, 1, writebyte, 1, readbyte);
}

#define A2D_PRJ103J2 0
void ReadPR103J2()
{
	int PR = analogRead(A2D_PRJ103J2);
}ssss

#define A2D_TSL250RDms 1
void ReadTSL250ms()
{
	int TSL250_1 = analogRead(A2D_TSL250RDms);
}

void ReadMMA()
{
	byte MMA8452_ADDRESS = 0x1C;
	byte OUT_X_MSB = 0x01;
	byte XYZ_DATA_CFG = 0x0E;
	byte CTRL_REG1 = 0x2A;

	byte readarray[6];  // x/y/z accel register data stored here
	byte writebyte[1] = {OUT_X_MSB};
	WriteReadI2C(MMA8452_ADDRESS, 1, writebyte, 6, readarray, false);

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
void ReadSPV()
{
	long buff[128];
	for (int i = 0; i < 128; i++)
		buff[i] = analogRead(PIN_RAW_MIC);
}

void ReadTSYS01()
{
	byte TSYS01Address = 0x76;
	byte TSYS01StartReg = 0x48; //commands sensor to begin measurement / output calculation
	byte TSYS01TempReg = 0x00; //requests most recent output from measurement

	byte writebyte[1] = {TSYS01StartReg};
	WriteI2C(TSYS01Address, 1, writebyte);
	delay(10);
	writebyte[0] = {TSYS01TempReg};
	byte readarray[3];
	WriteReadI2C(TSYS01Address, 1, writebyte, 3, readarray);
	// the last read is not used
}

void ReadHMC()
{
	byte HMC5883_ADDRESS_MAG = 0x3C >> 1;  // 0011110x
	byte HMC5883_REGISTER_MAG_OUT_X_H_M = 0x03;

	byte writebyte[1] = {HMC5883_REGISTER_MAG_OUT_X_H_M};
	byte readarray[6];
	WriteReadI2C(HMC5883_ADDRESS_MAG, 1, writebyte, 6, readarray);
}

void ReadHIH6130()
{
	byte HIH_ADDRESS = 0x27;

	byte readarray[4];
	WriteReadI2C(HIH_ADDRESS, 4, readarray, 100);
	
	// Temp_byte[0] = (Temp_byte[1] >> 6) & 0x03;

	// Temp_byte[1] = Temp_byte[1] & 0x3f;
	// Temp_int[0] = (((unsigned int)Temp_byte[1]) << 8) | Temp_byte[2];

	// Temp_int[1] = (((unsigned int)Temp_byte[3]) << 8) | Temp_byte[4];
	// Temp_int[1] = Temp_int[1] / 4;

	// Temp_float[1] = (float) Temp_int[0] * 6.10e-3;
	// Temp_float[0] = (float) Temp_int[1] * 1.007e-2 - 40.0;
}

void ReadAPDS()
{
	byte address = mcp3428_2.returnAddress();
	byte writebyte[1] = {mcp3428_2.returnRegister(MCP342X::CHANNEL_0)};
	byte readarray[3];
	WriteReadI2C(address, 1, writebyte, 3, readarray);
	// the last read is not used

	// selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	// int APDS = mcp3428_2.readADC();
}

void ReadTSL260RD()
{
	byte address = mcp3428_1.returnAddress();
	byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_1)};
	byte readarray[3];
	WriteReadI2C(address, 1, writebyte, 3, readarray);
	// the last read is not used

	// mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
	// int TSL260 = mcp3428_1.readADC();
}

void ReadTSL250RDls()
{
	byte address = mcp3428_1.returnAddress();
	byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_3)};
	byte readarray[3];
	WriteReadI2C(address, 1, writebyte, 3, readarray);
	// the last read is not used

	// mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
	// int TSL250_2 = mcp3428_1.readADC();
}

void ReadMLX()
{
	byte address = mcp3428_1.returnAddress();
	byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_0)};
	byte readarray[3];
	WriteReadI2C(address, 1, writebyte, 3, readarray);
	// the last read is not used

	// mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
	// int MLX = mcp3428_1.readADC();
}

void ReadML8511()
{
	byte address = mcp3428_1.returnAddress();
	byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_2)};
	byte readarray[3];
	WriteReadI2C(address, 1, writebyte, 3, readarray);
	// the last read is not used

	// mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
	// int ML8511 = mcp3428_1.readADC();
}

void ReadTMP421()
{
	byte TMP421_ADDRESS = 0x4c;
	byte readbyte[1];
	
	// high-byte
	byte writebyte[1] = {0x00};
	WriteReadI2C(TMP421_ADDRESS, 1, writebyte, 1, readbyte); 
	// low-byte
	writebyte[0] = 0x10;
	WriteReadI2C(TMP421_ADDRESS, 1, writebyte, 1, readbyte);

	// byte testdata[2];
	// WriteI2C(TMP421_ADDRESS, char(0x00));
	// ReadI2C(TMP421_ADDRESS, testdata[0]); // high-byte

	// WriteI2C(TMP421_ADDRESS, char(0x10));
	// ReadI2C(TMP421_ADDRESS, testdata[1]); // low-byte
}

void ReadChem()
{
	char buff[1024];
	int numbytes = 0;
	ReadRS232(buff, numbytes);
}

void ReadAlpha()
{
	
}

