#include "chem.h"

void Cchem::ChemGet(int* NumVal, char* reading)
{
	while (Serial3.available() > 0)
		input_byte = Serial3.read();
	

	len = Serial3.readBytesUntil('\n', reading, 256);
	reading[len] = '\0';
	*NumVal = len;
}

void Cchem::ChemGet(char* reading)
{
	while (Serial3.available() > 0)
		input_byte = Serial3.read();
	

	len = Serial3.readBytesUntil('\n', reading, 256);
	reading[len] = '\0';
}
