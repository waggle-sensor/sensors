#include <Arduino.h>
#include <Wire.h> 

//MMA8452
#define MMA8452_ADDRESS 0x1C
#define OUT_X_MSB 0x01
#define XYZ_DATA_CFG  0x0E
#define WHO_AM_I   0x0D
#define CTRL_REG1  0x2A
#define GSCALE 2 // Sets full-scale range to +/-2, 4, or 8g. Used to calc real g values.

class CMMAQ
{
public:

	void MMA8452_read(float *val);
	void readAccelData(int *destination);
	void MMA8452_CONFIG();
	void MMA8452Standby();
	void MMA8452Active();
	void MMA8452readRegisters(byte addressToRead, int bytesToRead, byte *dest);
	byte MMA8452readRegister(byte addressToRead);
	void MMA8452writeRegister(byte addressToWrite, byte dataToWrite);

private:
	byte fsr;
	int gCount = 0;

	// byte Temp_byte;
	int Temp_int[3];
	// float Temp_float[3];
	// byte dest;
};