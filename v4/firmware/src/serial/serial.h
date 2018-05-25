#include <Arduino.h>

// #define PIN_CHEMSENSE_POW 47
// #define CHEMSENSE_DATARATE 115200

class CustomSerial
{
public:
	// void setting();

	void configSerial(int port, long datarate, long timeout, int powerPin);
	void readSerial(char* reading, int* NumVal, int port);
	void writeSerial(char* writing, int length, int port);

private:
};