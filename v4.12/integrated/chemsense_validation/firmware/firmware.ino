
#include "./DueTimer/DueTimer.h" //** TIMER3 library

byte inputarray[1024];
bool UP_DOWN;

void setup()
{
	SerialUSB.begin(115200);
	delay(100);

	Serial3.begin(115200);	// begin serial3
	Serial3.setTimeout(5000);	// set timeout of serial3 as 5 sec
	pinMode(47, OUTPUT);  // pin for chemsense power is 47
	delay(10);
	digitalWrite(47, LOW); 	// power on the device --> LOW means power on
	delay(1000);

	Timer3.attachInterrupt(handler).setPeriod(1000000 * 1).start();  //every 1000ms
	delay(1000);
}

void loop()
{
	SerialUSB.println("Firmware loop is started");

	byte inputbyte = '\0';
	SerialUSB.println("While loop reading serial3 is started");

	while (true)
	{
		if (Serial3.available() > 0)
		{
			SerialUSB.println("Serial3 is available");

			while (Serial3.available() > 0)
				inputbyte = Serial3.read();

			int len = 0;
			len = Serial3.readBytesUntil('\n	', inputarray, 256);

			for (int i = 0; i < len; i++)
        		SerialUSB.write(inputarray[i]);
			SerialUSB.println("");

			SerialUSB.println("While loop reading serial3 is ended");
		}
		else
			SerialUSB.println("Serial3 is not available");

		delay(1000);
	}
}

void handler()
{
    UP_DOWN =! UP_DOWN;
    digitalWrite(8, UP_DOWN);
}
