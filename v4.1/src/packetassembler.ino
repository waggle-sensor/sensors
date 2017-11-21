
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

int ReturnPacketLength()
{
    return outLength;
}



///////// Bus seperately --> different packet type
int busPacketSeq = 0;
int busOutLength = 4; // start at 4 to account for header and sequence
int busPacketType = 0x02;

byte busSequenceValidity = 0x00;

byte busPacket[2048];
void BusPacketization(byte thisid, byte *sensorReading, int readingLength)
{
    BusPacketLengthCheck(readingLength);

    int BusSensorReadingValidity = 1;

    busPacket[BusOutLength++] = thisid;
    busPacket[BusOutLength++] = (BusSensorReadingValidity << 7) | readingLength;   // valid data

    for (int i = 0; i < readingLength; i++)
        busPacket[BusOutLength++] = sensorReading[i];
}

void BusPacketLengthCheck(int readingLength)
{
    if ((BusOutLength - 1 + readingLength) > 128)
    {
        BusPacketSender(0x00);  // not the last busPacket for this request
        busPacketSeq++;
        BusMultiPacketInit();  // for the last busPacket of this request
    }
}

void BusPacketSender(byte sequenceValidity)
{
    busPacket[2] = BusOutLength - 3;  // data length - header (means including seq byte)
    busPacket[3] = (sequenceValidity << 7) | busPacketSeq;
    byte crc = CRCcalc(BusOutLength - 3, busPacket);
    busPacket[BusOutLength++] = crc;  // Append CRC8
    busPacket[BusOutLength++] = 0x55;  // postscript

    for (int i = 0; i < BusOutLength; i++)
        SerialUSB.write(busPacket[i]);
    SerialUSB.println("");
}

void BusMultiPacketInit()
{
    BusOutLength = 4;
    byte lastPacket = 0x01;

    busPacket[0] = 0xAA;  // preamble
    busPacket[1] = (busPacketType << 4) | protocolver;  // data type --> sensor reading = 0x01 | protocol
    busPacket[2] = BusOutLength;  // data length
    busPacket[3] = (lastPacket << 7) | busPacketSeq;  // seq, MSB of first sequence is 1
}

void BusPacketInit()
{
    BusOutLength = 4;
    busPacketSeq = 0;
    byte lastPacket = 0x01;

    busPacket[0] = 0xAA;  // preamble
    busPacket[1] = (busPacketType << 4) | protocolver;  // data type --> sensor reading = 0x01 | protocol
    busPacket[2] = BusOutLength;  // data length
    busPacket[3] = (lastPacket << 7) | busPacketSeq;  // seq, MSB of first sequence is 1
}

int BusReturnPacketLength()
{
    return BusOutLength;
}