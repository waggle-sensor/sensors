// variables for firmware
#include "variables.h"

/* for main loop */
#define HEADERSIZE 3
#define FOOTERSIZE 2
#define maxInputLength 1024  // possible data bytes 256, 4 headers, 2 footers

int bufferIndex = 0;
byte inputarray[maxInputLength];  // Length of this byte array has to be the same with MaxInputLength
byte input = '\0';

void setup()
{
	delay(2000);
	SerialUSB.begin(115200);
	delay(100);

	// wire for sensors on met/lightsense boards
	// AND initialization for sensors on met/lightsense boards
	Wire.begin();
	delay(100);
	
	// What sensors does this initialize? 
	SensorInit();
	PacketInit();
	flagON = false;
}

void loop()
{
	while (SerialUSB.available())
	{
		inputarray[bufferIndex] = SerialUSB.read();
		if (bufferIndex == maxInputLength)
			break;
		bufferIndex++;
	}

	int startByteIndex = 0;
	for (int i = 0; i < bufferIndex; i++)
	{
		if (inputarray[i] == 0xAA)
		{
			startByteIndex = i;
			break;
		}
	}

	for (int i = startByteIndex; i < bufferIndex; i++)
		inputarray[i - startByteIndex] = inputarray[i];
	bufferIndex -= startByteIndex;

	if (bufferIndex > 4)
	{
		int dataLength = inputarray[2];
		int packetLength = dataLength + HEADERSIZE + FOOTERSIZE;
		if (bufferIndex >= packetLength)
		{
			byte packet[packetLength];
			for (int i = 0; i < bufferIndex; i++)
			{
				if (i < packetLength)
					packet[i] = inputarray[i];
				else
					inputarray[i - packetLength] = inputarray[i];
			}
			bufferIndex -= packetLength;

			byte checkcrc = CRCcalc(dataLength, packet);
			int request = (packet[1] >> 4) & 0x0F;
			int protocol = packet[1] & 0x0F;
			// if ((checkcrc == packet[dataLength + HEADERSIZE]) && (request == 0) && (protocol == 2))
			if ((request == 0) && (protocol == 2))
				SortReading(packet, dataLength);
		}
	}
}
