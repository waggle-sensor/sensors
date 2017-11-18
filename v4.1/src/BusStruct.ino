struct Bus
{
    const byte busid;
    void (*initFunc)(byte*, int*);
    void (*configFunc)(byte*, int*);
    void (*enableFunc)(byte*, int*);
    void (*disableFunc)(byte*, int*);
    void (*readFunc)(byte*, int*);
    void (*writeFunc)(byte*, int*);
};
 
const Bus bus[] = {
};
 
const int numBus = sizeof(bus)/sizeof(bus[0]);
    {0xI2C, 0x48, InitBus48BusI2C48, ConfigBus48BusI2C48, EnableBus48BusI2C48, DisableBus48BusI2C48, ReadBus48BusI2C48, WriteBus48BusI2C48},
    {0xSerial, 0x03, InitBus03BusSerial03, ConfigBus03BusSerial03, EnableBus03BusSerial03, DisableBus03BusSerial03, ReadBus03BusSerial03, WriteBus03BusSerial03},
    {0x00, 0x03, InitBus03Bus0003, ConfigBus03Bus0003, EnableBus03Bus0003, DisableBus03Bus0003, ReadBus03Bus0003, WriteBus03Bus0003},
    {0xI2C, 0x48, InitBus48BusI2C48, ConfigBus48BusI2C48, EnableBus48BusI2C48, DisableBus48BusI2C48, ReadBus48BusI2C48, WriteBus48BusI2C48},
