
struct MandatorySensor
{
	const byte funcid;
	void (*enableFunc)();
};


const MandatorySensor mandsensor[] = {
	{0x00, EnableSensor00},
	{0x01, EnableSensor01},
	{0x02, EnableSensor02},
	{0x03, EnableSensor03},
	{0x04, EnableSensor04},
	{0x05, EnableSensor05},
	{0x06, EnableSensor06},
	{0x07, EnableSensor07},
	{0x08, EnableSensor08},
	{0x09, EnableSensor09},
	{0x0A, EnableSensor0A},
	{0x0B, EnableSensor0B},
	{0x0C, EnableSensor0C},
	{0x0D, EnableSensor0D},
	{0x0E, EnableSensor0E},
	{0x0F, EnableSensor0F},
	{0x10, EnableSensor10},
	{0x13, EnableSensor13},
	{0x2A, EnableSensor2A},  // Chem
	{0x30, EnableSensor28},  // Alpha
	{0xFF, EnableSensorFF},  // FW ver
};

const int numMand = sizeof(mandsensor)/sizeof(mandsensor[0]);