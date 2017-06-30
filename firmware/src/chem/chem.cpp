#include "chem.h"

void Cchem::setting()
{
	// Begin Serial3
    Serial3.begin(CHEMSENSE_DATARATE);
    // To wait until chem sends data again
    // if chem does not send data for 2 secs
    Serial3.setTimeout(4000);
    
    // Set a GPIO pin for chemsense power
    pinMode(PIN_CHEMSENSE_POW, OUTPUT);
    // LOW means power on
    digitalWrite(PIN_CHEMSENSE_POW, LOW);	
}

void Cchem::ChemGet(int* NumVal, char* reading)
{
	while (Serial3.available() > 0)
		input_byte = Serial3.read();
	

	len = Serial3.readBytesUntil('\n', reading, 256);
	reading[len] = '\0';
	*NumVal = len;
}
