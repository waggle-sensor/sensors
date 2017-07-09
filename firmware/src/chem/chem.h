#include <Arduino.h>

#define PIN_CHEMSENSE_POW 47
#define CHEMSENSE_DATARATE 115200

class Chemsense
{
public:
	void setting();
	void readChem(int* NumVal, char* reading);

private:
	char input_byte;
	int len;
};