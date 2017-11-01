
struct FunctionType
{
	const byte funcid;
	void (*func)(byte*, int);
};

const FunctionType functype[] = {
	// {0x00, MultiFunctions},
	{0x01, CallInitCore},
	{0x02, CallReadCore},
	{0x03, CallEnableCore},
	{0x04, CallDisableCore},
};

const int numtype = sizeof(functype)/sizeof(functype[0]);

void SortReading(byte *dataReading, int packetLength)
{
	
	int request = dataReading[1] & 0xF0;
	int protocol = dataReading[1] & 0x0F;
	int datalength = dataReading[3];
	int decrease = 0;

	bool checkcrc = CheckCRC(dataReading[datalength + 4]);

	byte typebyte = 0;
	byte paramlength = 0;
	byte sending[3];

	if (checkcrc && (request == 0) && (protocol == 2) && (datalength + 6 == packetLength))
	{
		SerialUSB.println("crc okay, packet data type okay, protocol version okay");

		byte *subpacket = dataReading + 4;
		// while (datalength != 0)
		while (subpacket < &dataReading[datalength + 4])
		{
			typebyte = (subpacket[0] >> 4) & 0x0F;
			paramlength = subpacket[0] & 0x0F;

			for (int i = 0; i < numtype; i++)
			{
				const FunctionType *ft = functype + i;
				if (ft->funcid == typebyte)
				{
					SerialUSB.println("found matching function");
					ft->func(subpacket + 1, paramlength);
					break;
				}
			}
			subpacket += paramlength + 1;
		}
	}
	else
		ReturnFalse();

	SerialUSB.println("end sorting");
}

void ReturnFalse()
{
	SerialUSB.print("WRONG");
}

bool CheckCRC(byte crc)
{
	if (crc == 0)
		return true;
	else
		return false;
}


struct EnabledSensorTable
{
	const byte enabledsensorid;
	bool enabled;
};

EnabledSensorTable sensortable[] = {
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
	{0x0A, true},  // HMC5883L Strength Hx,y,z,Change
	{0x0B, true},  // HIH6130 temperature, humidity
	{0x0C, true},  // APDS-9006-020
	{0x0D, true},  // TSL260
	{0x0E, true},  // TSL250
	{0x0F, true},  // MLX75305
	{0x10, true},  // ML8511
	{0x13, true},  // TMP421
	{0x14, true},  // SPV1840LR5H-B
	{0x2A, true},  // All Chemsense
	{0x28, true},  // Alphasensor Histogram
	{0x29, true},  // Alphasensor Serial
	{0x30, true},  // Alphasensor Firmware
	{0x31, true},  // Configuration
	{0x2B, false},  // YL-69
	{0x2C, false},  // YHDC SCT-013-030
	{0x2D, false},  // CR3110-3000
	{0x2E, false},  // Water Level (Black)
	{0x2F, false},  // Water Level (Red)
	{0x35, false},  // PMS3003
	{0x36, false},  // PMS7003
	{0x37, false},  // Rain gauge
	{0x38, false},  // Soil moisture
};

const int numEnable = sizeof(sensortable)/sizeof(sensortable[0]);

void CallEnableCore(byte *enablingthisids, int length)
{
	byte thisid;
	for (int i = 0; i < length; i++)
	{
		thisid = enablingthisids[i];
		for (int j = 0; j < numEnable; j++)
		{
			EnabledSensorTable *est = sensortable + j;
			if (est->enabledsensorid == thisid)
			{
				est->enabled = true;
				break;
			}
		}
	}
}

void CallDisableCore(byte *disablethisids, int length)
{
	byte thisid;
	for (int i = 0; i < length; i++)
	{
		thisid = disablethisids[i];
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

void CallInitCore(byte *data, int length)
{
	if (data[0] == 0x2A)
		InitChemsense();
	// else if (data[0] == 0x30)
	// 	InitAlphasensor();
	else
		ReturnFalse();
}

struct ReadCoresense
{
	const byte sensorid;
	void (*func)(byte*, int);
};

const ReadCoresense readcore[] = {
	// Metsense
	{0x00, ReadMacAdd}, // Mac address of Met/Lightsense board
	{0x01, ReadTMP112}, // temperature
	{0x02, ReadHTU21D}, // temperature, humidity
	{0x03, ReadHIH4030}, // humidity
	{0x04, ReadBMP180}, // temperature, pressure
	{0x05, ReadPR103J2}, // temperature
	{0x06, ReadTSL250ms}, // light
	{0x07, ReadMMA}, // acceleration force
	{0x08, ReadSPV}, // sound level
	{0x09, ReadTSYS01}, // temperature
	// Lightsense
	{0x0A, ReadHMC}, // magnetic field
	{0x0B, ReadHIH6130}, // temperature, humidity
	{0x0C, ReadAPDS}, // light
	{0x0D, ReadTSL260RD}, // light
	{0x0E, ReadTSL250RDls}, // light
	{0x0F, ReadMLX}, // light
	{0x10, ReadML8511}, // UV index
	{0x13, ReadTMP421}, // temperature
	// Chem
	{0x2A, ReadChem}, // chemical sensors, temperature, humidity, pressure
	// Alpha
	// {0x28, ReadAlphaHisto}, // particle histogram
	// {0x29, ReadAlphaSerial}, // serial number of alpha sensor
	// {0x30, ReadAlphaFWver}, // FW version of alpha sesnor
	// {0x31, ReadAlphaConfig}, // configuration of alpha sensor
	// // Rain gauge OnSet
	// {0x37, ReadOnSet}, // rain gauge
	// // Soil moisture Decagon
	// {0x38, ReadDecagon}, // soil temperature, soil electric conductivity, soil volumetric water content
};

int numCoreRead = sizeof(readcore)/sizeof(readcore[0]);

void CallReadCore(byte *data, int length)
{
	SerialUSB.println("to call one of core reading function");
	SerialUSB.println(data[0], HEX);

	byte thisid;
	byte sensorReading[1024];
	int readinglength = 0;

	bool enable = GetEnable(data[0]);
	SerialUSB.println("get enable");
	SerialUSB.println(enable);

	if (!enable)
		return;

	for (int i = 0; i < numCoreRead; i++)
	{
		const ReadCoresense *rc = readcore + i;
		if (rc->sensorid == data[0])
		{
			SerialUSB.println("found matching core reading function");
			rc->func(sensorReading, readinglength);
			break;
		}
	}
}
