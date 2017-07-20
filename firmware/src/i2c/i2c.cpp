#include "i2c.h"

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

static const I2CDevice devices[] = {
	{"mac", 0x00},
	{"tmp112", 0x01},
	{"htu21d", 0x02},
	{"bmp180", 0x03},
	{"pr103j2", 0x04},
	{"tsl250", 0x05},
	{"mma8452q", 0x06},
	{"spv1840", 0x07},
	{"tsys01", 0x08},
	{"hmc5883l", 0x10},
	{"hih6130", 0x11},
	{"apds9006", 0x12},
	{"tsl260rd", 0x13},
	{"tsl250rd", 0x14},
	{"mlx75305", 0x15},
	{"ml8511", 0x16},
	{"tmp421", 0x17},
};

static const int numdevices = sizeof(devices) / sizeof(devices[0]);

const I2CDevice *FindI2CDevice(const char *name) {
	for (int i = 0; i < numdevices; i++) {
		const I2CDevice *device = &devices[i];

		if (strcmp(device->name, name) == 0) {
			return device;
		}
	}

	return NULL;
}
