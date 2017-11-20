struct Bus
{
    const byte bustype;
    const byte busid;
    void (*initFunc)(byte*);
    void (*configFunc)(byte*);
    void (*enableFunc)();
    void (*disableFunc)();
    void (*readFunc)(byte*, int*);
    void (*writeFunc)(byte*, int*);
};
 
const Bus bus[] = {
    {0x01, 0x48, InitBusI2C48, ConfigBusI2C48, EnableBusI2C48, DisableBusI2C48, ReadBusI2C48, WriteBusI2C48},
};
 
const int numBus = sizeof(bus)/sizeof(bus[0]);
