
int packetseq = 0;
int protocolver = 0x02;

byte wholepacket[1030];
int packetlength = 4; // start at 4 to account for header

void Packetization(byte *sensorReading, int readinglength)
{

	wholepacket[0] = 0xAA;  // preamble
	wholepacket[1] = ((0x01 & 0x0f) << 4) | protocolver;  // data type --> sensor reading = 0x01 | protocol
	wholepacket[2] = packetseq;  // seq

	for (int i = 0; i < readinglength; i++)
		wholepacket[packetlength++] = sensorReading[i];

	wholepacket[packetlength++] = packetlength - 4;  // data length
	// wholepacket[packetlength++] = CRC_calc(packetlength - 4);  // Append CRC8
	wholepacket[packetlength++] = 0x55;  // postscript
	packetseq++;

	for (int i = 0; i < packetlength; i++)
		SerialUSB.print(wholepacket[i]);
}