struct Bus
{
    const byte bustype;
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
