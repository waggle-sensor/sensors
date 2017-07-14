#include "i2c.h"

// void customI2C::initI2C()
// {	
// 	Wire.begin();
// 	delay(100);
// }

void CustomI2C::readI2C(char address, int length, char* out)
{
	Wire.beginTransmission(address); // start transmission to device
	Wire.requestFrom(address, length);// send data n-bytes read
	if (Wire.available() > 0)
	{
		for (int i = 0; i < length; i++)
			out[i] = Wire.read(); // receive DATA
	}
	else
	{
		for (int i = 0; i < length; i++)
			out[i] = 0xff;
	}
	Wire.endTransmission(); // end transmission
}

void CustomI2C::writeI2C(char address, int length, char* in)
{
	Wire.beginTransmission(address); // start transmission to device
	for (int i = 0; i < length; i++)
		Wire.write(in[i]); // sends register address to read from
	Wire.endTransmission();
}