#include "i2c.h"

void ReadI2C(char address, int length, char *out)
{
	Wire.beginTransmission(address);
	Wire.requestFrom(address, length);

	if (Wire.available() > 0) {
		for (int i = 0; i < length; i++) {
			out[i] = Wire.read();
		}
	} else {
		for (int i = 0; i < length; i++) {
			out[i] = 0xff;
		}
	}

	// TODO should return actual size read.

	Wire.endTransmission();
}

void WriteI2C(char address, int length, char *in)
{
	Wire.beginTransmission(address);

	for (int i = 0; i < length; i++) {
		Wire.write(in[i]);
	}

	Wire.endTransmission();
}
