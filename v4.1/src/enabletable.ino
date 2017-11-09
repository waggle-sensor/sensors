

struct EnabledSensorTable
{
	const byte enabledsensorid;
	bool enabled;
};

EnabledSensorTable sensortable[] = {
	// Metsense
	{0xFF, true},  // Firmware HW/SW version, build git, build time
	{0x00, true},  // Metsense MAC
	{0x01, true},  // TMP112
	{0x02, true},  // HTU21D temperature, HTU21D humidity
	{0x03, true},  // HIH4030 humidity
	{0x04, true},  // BMP180 temperature, BMP180 pressure
	{0x05, true},  // PR103J2 temperature
	{0x06, true},  // TSL250RD
	{0x07, true},  // MMA8452Q AccX,Y,Z,Magnitude
	{0x08, true},  // SPV1840LR5H-B
	{0x09, true},  // TSYS01 temperature
	// Lightsense
	{0x0A, true},  // HMC5883L Strength Hx,y,z,Change
	{0x0B, true},  // HIH6130 temperature, humidity
	{0x0C, true},  // APDS-9006-020
	{0x0D, true},  // TSL260
	{0x0E, true},  // TSL250
	{0x0F, true},  // MLX75305
	{0x10, true},  // ML8511
	{0x13, true},  // TMP421
	{0x14, true},  // SPV1840LR5H-B
	// Chem
	{0x2A, true},  // All Chemsense
	// Alpha
	{0x2B, true},  // Alpha sensor status
};

const int numEnable = sizeof(sensortable)/sizeof(sensortable[0]);

void CallEnableCore(byte *thisid, int length)
{
	if (0x28 <= thisid[0] && thisid[0] <= 0x31)
		thisid[0] = 0x30;

	for (int j = 0; j < numEnable; j++)
	{
		EnabledSensorTable *est = sensortable + j;
		if (est->enabledsensorid == thisid[0])
		{
			est->enabled = true;
			Packetization(0, thisid[0]);

			if (thisid[0] == 0x30)
				alpha_onagain();

			break;
		}
	}
	Packetization(1, thisid[0]);
}

void CallDisableCore(byte *thisid, int length)
{
	if (0x28 <= thisid[0] && thisid[0] <= 0x31)
		thisid[0] = 0x30;

	for (int j = 0; j < numEnable; j++)
	{
		EnabledSensorTable *est = sensortable + j;
		if (est->enabledsensorid == thisid[0])
		{
			est->enabled = false;
			Packetization(0, thisid[0]);

			if (thisid[0] == 0x30)
				alphasense_off();

			break;
		}
	}
	Packetization(1, thisid[0]);
}

void CallDisableCore(byte thisid)
{
	for (int j = 0; j < numEnable; j++)
	{
		EnabledSensorTable *est = sensortable + j;
		if (est->enabledsensorid == thisid)
		{
			est->enabled = false;
			break;
		}
	}
}

bool GetEnable(byte id)
{
	for (int j = 0; j < numEnable; j++)
	{
		EnabledSensorTable *est = sensortable + j;
		if (est->enabledsensorid == id)
			return est->enabled;
	}
	return false;
}
