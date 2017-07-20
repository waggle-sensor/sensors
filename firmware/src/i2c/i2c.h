#include <Wire.h>

class CustomI2C
{
public:
	// void initI2C();
	void readI2C(char address, int length, char* out);
	void writeI2C(char address, int length, char* in);

private:

};

struct I2CDevice {
	const char *name;
	int addr;
	int (*read)();
};

const I2CDevice *FindI2CDevice(const char *name);
