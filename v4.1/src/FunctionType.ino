
struct FunctionType
{
	const byte funcid;
	void (*func)(byte*, byte);
};


const FunctionType functype[] = {
	{0x01, SensorInit},
	{0x02, SensorConfig},
	{0x03, SensorEnable},
	{0x04, SensorDiable},
	{0x05, SensorRead},
	// {0x06, SensorWrite},

	// {0x11, BusInit},
	// {0x12, BusConfig},
	// {0x13, BusEnable},
	// {0x14, BusDisable},
	// {0x15, BusRead},
	// {0x16, BusWrite},
};

const int numType = sizeof(functype)/sizeof(functype[0]);
