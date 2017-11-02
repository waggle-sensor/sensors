
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

	bool checkcrc = CheckCRC(dataReading[datalength + 4]);

	byte typebyte = 0;
	byte paramlength = 0;

	if (checkcrc && (request == 0) && (protocol == 2) && (datalength + 6 == packetLength))
	{
        PacketInit();

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
					ft->func(subpacket + 1, paramlength);
					break;
				}
			}
			subpacket += paramlength + 1;
		}
	}

    PacketSender();
}

void ReturnFalse()
{
	SerialUSB.print("WRONG");
}

void CallInitCore(byte *data, int length)
{
	if (data[0] == 0x30)
		InitAlphasensor();
	else
		ReturnFalse();
}

struct ReadCoresense
{
	const byte sensorid;
	void (*func)(byte*, int*);
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
	{0x28, ReadAlphaHisto}, // particle histogram
	{0x29, ReadAlphaSerial}, // serial number of alpha sensor
	{0x30, ReadAlphaFWver}, // FW version of alpha sesnor
	{0x31, ReadAlphaConfig}, // configuration of alpha sensor
	// // Rain gauge OnSet
	// {0x37, ReadOnSet}, // rain gauge
	// // Soil moisture Decagon
	// {0x38, ReadDecagon}, // soil temperature, soil electric conductivity, soil volumetric water content
};

int numCoreRead = sizeof(readcore)/sizeof(readcore[0]);

void CallReadCore(byte *data, int length)
{
	byte thisid = data[0];
	byte sensorReading[1024];
	int readingLength = 0;

	bool enable;
	if (0x28 <= thisid && thisid <= 0x31)
		enable = GetEnable(0x30);
	else
		enable = GetEnable(thisid);

	// SerialUSB.print("GetEnable ");
	// SerialUSB.println(enable);

	if (!enable)
	{
		Packetization(thisid, 0xFF);
		return;
	}

	for (int i = 0; i < numCoreRead; i++)
	{
		const ReadCoresense *rc = readcore + i;
		if (rc->sensorid == thisid)
		{
			rc->func(sensorReading, &readingLength);
			Packetization(sensorReading, readingLength, thisid);
			break;
		}
	}
}
