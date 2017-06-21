#include <Wire.h>
// #include <OneWire.h>

#define I2C_TMP112 0x48
#define TMP112_CONFIG_REG 0x01
#define TMP112_TEMP_REG 0x00


class CTMP112
{
	private:
		int Temp_byte[2];

	public:
		void TMP112_CONFIG();
		void TMP112_read(char* val);
};

