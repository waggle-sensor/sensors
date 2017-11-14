
int packetseq = 0;
int protocolver = 0x02;
byte sequenceValidity = 0x00;

byte packet[2048];
int outLength = 4; // start at 4 to account for header

void Packetization(byte sensorid, byte *sensorReading, int readingLength)
{
    PacketLengthCheck(readingLength);

    int sensorReadingValidity = 1;

    packet[outLength++] = sensorid;
    packet[outLength++] = (sensorReadingValidity << 7) | readingLength;   // valid data

    for (int i = 0; i < readingLength; i++)
        packet[outLength++] = sensorReading[i];
}

void Packetization(byte sensorid, byte returnCode)
{
    PacketLengthCheck(1);

    int sensorReadingValidity = 1;

    if (returnCode == 0xFF)
        sensorReadingValidity = 0;

    packet[outLength++] = sensorid;
    packet[outLength++] = sensorReadingValidity << 7 | 0x01;
    packet[outLength++] = returnCode;
}

void PacketLengthCheck(int readingLength)
{
    if ((outLength - 2 + readingLength) > 128)
    {
        PacketSender(0x00);  // not the last packet for this request
        packetseq++;
        MultiPacketInit();  // for the last packet of this request
    }
}

void PacketSender(byte sequenceValidity)
{
    packet[2] = (sequenceValidity << 7) | packetseq;
    packet[3] = outLength - 4;  // data length
    byte crc = CRCcalc(outLength - 4, packet);
    packet[outLength++] = crc;  // Append CRC8
    packet[outLength++] = 0x55;  // postscript

    for (int i = 0; i < outLength; i++)
        SerialUSB.write(packet[i]);
    SerialUSB.println("");
}

void MultiPacketInit()
{
    byte lastPacket = 0x01;
    packet[0] = 0xAA;  // preamble
    packet[1] = (0x01 << 4) | protocolver;  // data type --> sensor reading = 0x01 | protocol
    packet[2] = (lastPacket << 7) | packetseq;  // seq, MSB of first sequence is 1

    outLength = 4;
}

void PacketInit()
{
    byte lastPacket = 0x01;
    packetseq = 0;

    packet[0] = 0xAA;  // preamble
    packet[1] = (0x01 << 4) | protocolver;  // data type --> sensor reading = 0x01 | protocol
    packet[2] = (lastPacket << 7) | packetseq;  // seq, MSB of first sequence is 1

    outLength = 4;
}

