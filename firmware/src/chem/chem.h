#include <Arduino.h>

#define PIN_CHEMSENSE_POW 47
#define CHEMSENSE_DATARATE 115200

class Cchem
{
public:
	void setting();
	void ChemGet(int* NumVal, char* reading);

private:
	char input_byte;
	int len;
};