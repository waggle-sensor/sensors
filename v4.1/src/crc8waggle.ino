/** Calculate CRC8 ********************************************************************/
byte CRCcalc(byte dataLength, byte *packet)
{
    byte crc = 0x00;
    
    for (int i = 0x04; i < (dataLength + 0x04); i++) // 0x03 accounts for header
        crc = CRC8Waggle(packet[i], crc);

    return crc;
}
/**************************************************************************************/


/** Calculate CRC, byte by byte *******************************************************/
byte CRC8Waggle(byte data, byte crc)
{
    byte i;
    crc ^= data;

    for (i = 0x00; i < 0x08; i++)
    {
        if (crc & 0x01)
            crc = (crc >> 0x01) ^ 0x8C;
        else
            crc =  crc >> 0x01;
    }

    return(crc);
}
/**************************************************************************************/