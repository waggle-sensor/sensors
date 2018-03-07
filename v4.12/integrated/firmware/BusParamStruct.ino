 
struct paramBus
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
 
const paramBus parambus[] = {
    {0x00, 0x40, InitBusI2C40, ConfigBusI2C40, EnableBusI2C40, DisableBusI2C40, ReadBusI2C40, WriteBusI2C40},
    {0x00, 0x48, InitBusI2C48, ConfigBusI2C48, EnableBusI2C48, DisableBusI2C48, ReadBusI2C48, WriteBusI2C48},
    {0x01, 0x33, InitBusSPI33, ConfigBusSPI33, EnableBusSPI33, DisableBusSPI33, ReadBusSPI33, WriteBusSPI33},
    {0x01, 0x34, InitBusSPI34, ConfigBusSPI34, EnableBusSPI34, DisableBusSPI34, ReadBusSPI34, WriteBusSPI34},
    {0x01, 0x35, InitBusSPI35, ConfigBusSPI35, EnableBusSPI35, DisableBusSPI35, ReadBusSPI35, WriteBusSPI35},
    {0x01, 0x36, InitBusSPI36, ConfigBusSPI36, EnableBusSPI36, DisableBusSPI36, ReadBusSPI36, WriteBusSPI36},
    {0x01, 0x37, InitBusSPI37, ConfigBusSPI37, EnableBusSPI37, DisableBusSPI37, ReadBusSPI37, WriteBusSPI37},
    {0x01, 0x38, InitBusSPI38, ConfigBusSPI38, EnableBusSPI38, DisableBusSPI38, ReadBusSPI38, WriteBusSPI38},
    {0x01, 0x39, InitBusSPI39, ConfigBusSPI39, EnableBusSPI39, DisableBusSPI39, ReadBusSPI39, WriteBusSPI39},
    {0x01, 0x40, InitBusSPI40, ConfigBusSPI40, EnableBusSPI40, DisableBusSPI40, ReadBusSPI40, WriteBusSPI40},
};
 
const int numParamBus = sizeof(parambus)/sizeof(parambus[0]);
