 
struct Bus
{
    const byte bustype;
    const byte busid;
    void (*initFunc)(byte*);
    void (*configFunc)(byte*);
    void (*enableFunc)();
    void (*disableFunc)();
    void (*readFunc)(byte*, int*);
    void (*writeFunc)(byte*);
};
 
const Bus bus[] = {
    {0x03, 0x00, InitBusAnalog00, ConfigBusAnalog00, EnableBusAnalog00, DisableBusAnalog00, ReadBusAnalog00, WriteBusAnalog00},
    {0x03, 0x01, InitBusAnalog01, ConfigBusAnalog01, EnableBusAnalog01, DisableBusAnalog01, ReadBusAnalog01, WriteBusAnalog01},
    {0x03, 0x02, InitBusAnalog02, ConfigBusAnalog02, EnableBusAnalog02, DisableBusAnalog02, ReadBusAnalog02, WriteBusAnalog02},
    {0x03, 0x03, InitBusAnalog03, ConfigBusAnalog03, EnableBusAnalog03, DisableBusAnalog03, ReadBusAnalog03, WriteBusAnalog03},
    {0x03, 0x04, InitBusAnalog04, ConfigBusAnalog04, EnableBusAnalog04, DisableBusAnalog04, ReadBusAnalog04, WriteBusAnalog04},
    {0x03, 0x05, InitBusAnalog05, ConfigBusAnalog05, EnableBusAnalog05, DisableBusAnalog05, ReadBusAnalog05, WriteBusAnalog05},
    {0x03, 0x06, InitBusAnalog06, ConfigBusAnalog06, EnableBusAnalog06, DisableBusAnalog06, ReadBusAnalog06, WriteBusAnalog06},
    {0x03, 0x07, InitBusAnalog07, ConfigBusAnalog07, EnableBusAnalog07, DisableBusAnalog07, ReadBusAnalog07, WriteBusAnalog07},
    {0x03, 0x08, InitBusAnalog08, ConfigBusAnalog08, EnableBusAnalog08, DisableBusAnalog08, ReadBusAnalog08, WriteBusAnalog08},
    {0x03, 0x09, InitBusAnalog09, ConfigBusAnalog09, EnableBusAnalog09, DisableBusAnalog09, ReadBusAnalog09, WriteBusAnalog09},
    {0x03, 0x10, InitBusAnalog10, ConfigBusAnalog10, EnableBusAnalog10, DisableBusAnalog10, ReadBusAnalog10, WriteBusAnalog10},
    {0x03, 0x11, InitBusAnalog11, ConfigBusAnalog11, EnableBusAnalog11, DisableBusAnalog11, ReadBusAnalog11, WriteBusAnalog11},
    {0x04, 0x33, InitBusDigital33, ConfigBusDigital33, EnableBusDigital33, DisableBusDigital33, ReadBusDigital33, WriteBusDigital33},
    {0x04, 0x34, InitBusDigital34, ConfigBusDigital34, EnableBusDigital34, DisableBusDigital34, ReadBusDigital34, WriteBusDigital34},
    {0x04, 0x35, InitBusDigital35, ConfigBusDigital35, EnableBusDigital35, DisableBusDigital35, ReadBusDigital35, WriteBusDigital35},
    {0x04, 0x36, InitBusDigital36, ConfigBusDigital36, EnableBusDigital36, DisableBusDigital36, ReadBusDigital36, WriteBusDigital36},
    {0x04, 0x37, InitBusDigital37, ConfigBusDigital37, EnableBusDigital37, DisableBusDigital37, ReadBusDigital37, WriteBusDigital37},
    {0x04, 0x38, InitBusDigital38, ConfigBusDigital38, EnableBusDigital38, DisableBusDigital38, ReadBusDigital38, WriteBusDigital38},
    {0x04, 0x39, InitBusDigital39, ConfigBusDigital39, EnableBusDigital39, DisableBusDigital39, ReadBusDigital39, WriteBusDigital39},
    {0x04, 0x40, InitBusDigital40, ConfigBusDigital40, EnableBusDigital40, DisableBusDigital40, ReadBusDigital40, WriteBusDigital40},
    {0x05, 0x01, InitBusPWM01, ConfigBusPWM01, EnableBusPWM01, DisableBusPWM01, ReadBusPWM01, WriteBusPWM01},
    {0x05, 0x02, InitBusPWM02, ConfigBusPWM02, EnableBusPWM02, DisableBusPWM02, ReadBusPWM02, WriteBusPWM02},
    {0x05, 0x03, InitBusPWM03, ConfigBusPWM03, EnableBusPWM03, DisableBusPWM03, ReadBusPWM03, WriteBusPWM03},
    {0x05, 0x04, InitBusPWM04, ConfigBusPWM04, EnableBusPWM04, DisableBusPWM04, ReadBusPWM04, WriteBusPWM04},
    {0x05, 0x05, InitBusPWM05, ConfigBusPWM05, EnableBusPWM05, DisableBusPWM05, ReadBusPWM05, WriteBusPWM05},
    {0x05, 0x06, InitBusPWM06, ConfigBusPWM06, EnableBusPWM06, DisableBusPWM06, ReadBusPWM06, WriteBusPWM06},
    {0x05, 0x07, InitBusPWM07, ConfigBusPWM07, EnableBusPWM07, DisableBusPWM07, ReadBusPWM07, WriteBusPWM07},
    {0x05, 0x08, InitBusPWM08, ConfigBusPWM08, EnableBusPWM08, DisableBusPWM08, ReadBusPWM08, WriteBusPWM08},
    {0x05, 0x09, InitBusPWM09, ConfigBusPWM09, EnableBusPWM09, DisableBusPWM09, ReadBusPWM09, WriteBusPWM09},
    {0x05, 0x10, InitBusPWM10, ConfigBusPWM10, EnableBusPWM10, DisableBusPWM10, ReadBusPWM10, WriteBusPWM10},
    {0x05, 0x11, InitBusPWM11, ConfigBusPWM11, EnableBusPWM11, DisableBusPWM11, ReadBusPWM11, WriteBusPWM11},
    {0x05, 0x12, InitBusPWM12, ConfigBusPWM12, EnableBusPWM12, DisableBusPWM12, ReadBusPWM12, WriteBusPWM12},
    {0x02, 0x02, InitBusSerial02, ConfigBusSerial02, EnableBusSerial02, DisableBusSerial02, ReadBusSerial02, WriteBusSerial02},
    {0x02, 0x03, InitBusSerial03, ConfigBusSerial03, EnableBusSerial03, DisableBusSerial03, ReadBusSerial03, WriteBusSerial03},
};
 
const int numBus = sizeof(bus)/sizeof(bus[0]);
