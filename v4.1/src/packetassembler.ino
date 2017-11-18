
int packetseq = 0;
int outLength = 4; // start at 4 to account for header and sequence

int protocolver = 0x02;
int packetType = 0x01;

byte sequenceValidity = 0x00;

byte packet[2048];


void Packetization(byte thisid, byte *sensorReading, int readingLength)
{
    PacketLengthCheck(readingLength);

    int sensorReadingValidity = 1;

    packet[outLength++] = thisid;
    packet[outLength++] = (sensorReadingValidity << 7) | readingLength;   // valid data

    for (int i = 0; i < readingLength; i++)
        packet[outLength++] = sensorReading[i];
}

// void Packetization(byte thisid, byte returnCode)
// {
//     PacketLengthCheck(1);

//     int sensorReadingValidity = 1;

//     if (returnCode == 0xFF)
//         sensorReadingValidity = 0;

//     packet[outLength++] = thisid;
//     packet[outLength++] = sensorReadingValidity << 7 | 0x01;
//     packet[outLength++] = returnCode;
// }

void PacketLengthCheck(int readingLength)
{
    if ((outLength - 1 + readingLength) > 128)
    {
        PacketSender(0x00);  // not the last packet for this request
        packetseq++;
        MultiPacketInit();  // for the last packet of this request
    }
}

void PacketSender(byte sequenceValidity)
{
    packet[2] = outLength - 3;  // data length - header (means including seq byte)
    packet[3] = (sequenceValidity << 7) | packetseq;
    byte crc = CRCcalc(outLength - 3, packet);
    packet[outLength++] = crc;  // Append CRC8
    packet[outLength++] = 0x55;  // postscript

    for (int i = 0; i < outLength; i++)
        SerialUSB.write(packet[i]);
    SerialUSB.println("");
}

void MultiPacketInit()
{
    outLength = 4;
    byte lastPacket = 0x01;

    packet[0] = 0xAA;  // preamble
    packet[1] = (packetType << 4) | protocolver;  // data type --> sensor reading = 0x01 | protocol
    packet[2] = outLength;  // data length
    packet[3] = (lastPacket << 7) | packetseq;  // seq, MSB of first sequence is 1
}

void PacketInit()
{
    outLength = 4;
    packetseq = 0;
    byte lastPacket = 0x01;

    packet[0] = 0xAA;  // preamble
    packet[1] = (packetType << 4) | protocolver;  // data type --> sensor reading = 0x01 | protocol
    packet[2] = outLength;  // data length
    packet[3] = (lastPacket << 7) | packetseq;  // seq, MSB of first sequence is 1
}

