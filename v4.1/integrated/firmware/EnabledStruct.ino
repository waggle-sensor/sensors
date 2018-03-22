 
struct EnabledTable
{
    const byte enabledsensorid;
    bool enabled;
};
 
EnabledTable enabledtable[] = {
    {0x00, false},
    {0x01, false},
    {0x02, false},
    {0x03, false},
    {0x04, false},
    {0x05, false},
    {0x06, false},
    {0x07, false},
    {0x08, false},
    {0x09, false},
    {0x0A, false},
    {0x0B, false},
    {0x0C, false},
    {0x0D, false},
    {0x0E, false},
    {0x0F, false},
    {0x10, false},
    {0x13, false},
    {0x16, false},
    {0x28, false},
    {0x29, false},
    {0x2A, false},
    {0x2B, false},
    {0x2C, false},
    {0x30, false},
    {0x31, false},
    {0x36, false},
    {0xFF, false},
};
 
const int numEnabled = sizeof(enabledtable)/sizeof(enabledtable[0]);
