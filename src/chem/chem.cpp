#include "chem.h"

void Cchem::ChemGet(char* reading)
{
	i = 0;
	input_byte = 'a';
	// input_byte = Serial3.read();

	if (Serial3.available() > 0)
	{
		while (input_byte != '\n')
		//while (input_byte != ' ')
		{
			input_byte = Serial3.read();
			reading[i++] = input_byte;
		}

		// while (input_byte != '\n')
		// 	input_byte = Serial3.read();
	}

	input_byte = ' ';
	reading[i] = '\0';
}
