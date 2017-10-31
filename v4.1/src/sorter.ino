
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

int numtype = 4;

void SortReading(byte *dataReading, int length)
{

	int datalength = dataReading[3];
	bool checkcrc = CheckCRC(dataReading[datalength + 4]);
	int protocol = dataReading[1] & 0x0f;
	if (checkcrc && (protocol == 2))
	{
		byte typebyte = (dataReading[1] >> 4) & 0x0f;

		byte data[datalength];
		for (int i = 0; i < datalength; i++)
			data[i] = dataReading[4 + i];

		for (int i = 0; i < numtype; i++)
		{
			const FunctionType *ft = functype + i;
			if (ft->funcid == typebyte)
			{
				ft->func(data, datalength);
				break;
			}
		}
	}
	else
		ReturnFalse();
	
	SerialUSB.println("data ");
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
	void (*func)();
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
	// Lightsense
	{0x09, ReadTSYS01}, // temperature
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

int numCoresensors = 25;

void CallReadCore(byte *data, int length)
{
	for (int i = 0; i < length; i++)
	{
		SerialUSB.print("data ");
		SerialUSB.print(data[i]);

		for (int j = 0; j < numCoresensors; j++)
		{
			const ReadCoresense *fn = readcore + j;

			SerialUSB.print(" sensorid from struct ");
			SerialUSB.print(fn->sensorid);
			//if (strcmp(fn->sensorid, data) == 0)
			if (fn->sensorid == data[i])
			{
				SerialUSB.print(" data ");
				SerialUSB.print(" RIGHT ");
				fn->func();
				break;
			}
		}
	}

	SerialUSB.println(" ");
}

void CallEnableCore(byte *data, int length)
{
	// put the sensor id in to enable table
}

void CallDisableCore(byte *data, int length)
{
	// get the sensor id out from enable table
}
