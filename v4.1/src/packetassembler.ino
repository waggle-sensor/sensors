
int packetseq = 0;
int protocolver = 0x02;

byte packet[1030];
int outLength = 4; // start at 4 to account for header

void Packetization(byte *sensorReading, int readingLength, byte sensorid)
{
    packet[outLength++] = sensorid;
    packet[outLength++] = (1 << 7) | readingLength;   // valid data

	for (int i = 0; i < readingLength; i++)
		packet[outLength++] = sensorReading[i];
}

void Packetization(byte sensorid, byte returnCode)
{
    int validity = 1;

    if (returnCode == 0xFF)
        validity = 0;

    packet[outLength++] = sensorid;
    packet[outLength++] = validity << 7 | 0x01;   // invalid data
    packet[outLength++] = returnCode;
}

void PacketSender()
{
    if (outLength < 256)
    {   
        packet[3] = outLength - 4;  // data length
        packet[outLength++] = 0x00;  //CRC_calc(outLength - 4);  // Append CRC8
        packet[outLength++] = 0x55;  // postscript

        for (int i = 0; i < outLength; i++)
            SerialUSB.print(packet[i],HEX);
    }
    else
    {
        int sequence = ceil(outLength / 256);
    }
    SerialUSB.println("");
}

void PacketInit()
{
    packet[0] = 0xAA;  // preamble
    packet[1] = ((0x01 & 0x0f) << 4) | protocolver;  // data type --> sensor reading = 0x01 | protocol
    packet[2] = (0x01 << 7) | packetseq;  // seq, MSB of first sequence is 1

    outLength = 4;
    packetseq = 0;
}
