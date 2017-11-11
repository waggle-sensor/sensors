
// lib for sensors on lightsense
#include "variables.h"

int MaxInputLength = 262;  // possible data bytes 256, 4 headers, 2 footers
byte inputarray[262];  // Length of this byte array has to be the same with MaxInputLength
byte input = '\0';

bool postscript = false;
int packetLength = 0;

void setup()
{
	// serial between cs and np
	SerialUSB.begin(115200);
	delay(10);

	// wire for sensors on met/lightsense boards
	// AND initialization for sensors on met/lightsense boards
	Wire.begin();
	delay(10);
	InitSensors();
	delay(1000);
	InitChemsense();
	PacketInit();
}

void loop()
{
	// Read data until it gets a postscript
	while (!postscript)
	{
		input = SerialUSB.read();

		// If input is preamble, then store bytes from now
		if (input == 0xaa)
		{
			inputarray[packetLength] = input;
			inputarray[++packetLength] = '\0';

			// And keep reading until it gets a postscript
			while (!postscript)
			{
				input = SerialUSB.read();
				inputarray[packetLength] = input;

				// If it gets a postscript, break loops
				// If packetLength of the input is 260, break loops
				if (input == 0x55)
					postscript = true;
				if (packetLength == MaxInputLength)
					break;

				inputarray[++packetLength] = '\0';

			}
			if (packetLength == MaxInputLength)
				break;
		}
	}

	if (postscript)
		SortReading(inputarray, packetLength);

	// SerialUSB.println("end!!");
	postscript = false;
	packetLength = 0;
}
