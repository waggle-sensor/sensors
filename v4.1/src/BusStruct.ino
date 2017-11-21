struct Bus
{
    const byte bustype;
    const byte busid;
    void (*initFunc)(byte*);
    void (*configFunc)(byte*);
    void (*enableFunc)();
    void (*disableFunc)();
    void (*readFunc)(byte*, byte*, int*);
    void (*writeFunc)(byte*);
};
 
const Bus bus[] = {
    {0x01, 0x40, InitBusI2C40, ConfigBusI2C40, EnableBusI2C40, DisableBusI2C40, ReadBusI2C40, WriteBusI2C40},
    {0x01, 0x48, InitBusI2C48, ConfigBusI2C48, EnableBusI2C48, DisableBusI2C48, ReadBusI2C48, WriteBusI2C48},
    {0x00, 0x02, InitBusSerial02, ConfigBusSerial02, EnableBusSerial02, DisableBusSerial02, ReadBusSerial02, WriteBusSerial02},
    {0x00, 0x03, InitBusSerial03, ConfigBusSerial03, EnableBusSerial03, DisableBusSerial03, ReadBusSerial03, WriteBusSerial03},
    {0x02, 0x40, InitBusSPI40, ConfigBusSPI40, EnableBusSPI40, DisableBusSPI40, ReadBusSPI40, WriteBusSPI40},
};
 
const int numBus = sizeof(bus)/sizeof(bus[0]);
