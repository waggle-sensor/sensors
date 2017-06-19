#include <Arduino.h>

class Cchem
{
public:
	void ChemGet(char* reading);

private:
	char input_byte;
	int i;
};