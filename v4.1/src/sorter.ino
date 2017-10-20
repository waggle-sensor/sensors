
void SortReading(byte *dataReading, int length)
{
	while (length != 0)
	{
		int datalength = dataReading[3];
		if (dataReading[0] == 0xaa && dataReading[datalength + 5] == 0x55)
		{
			bool checkcrc = CheckCRC(dataReading[datalength + 4]);
			if (checkcrc)
			{
				byte data[datalength];
				for (int i = 0; i < datalength; i++)
					data[i] = dataReading[4 + i];
				CallFunction((const char) data[0]);
			}
			else
				DeleteReading(dataReading, length, datalength);
		}
		else
			DeleteReading(dataReading, length, datalength);
	}
}

int DeleteReading(byte *dataReading, int length, int datalength)
{
	length -= datalength - 6;
	if (length > 6)
	{
		int newfirst = sizeof(dataReading) - (datalength + 5);
		for (int i = 0; i < newfirst; i++)
		{
			dataReading[i] = dataReading[datalength + 6 + i];
			dataReading[i + 1] = '\0';				
		}
	}
	else
		length = 0;
}

bool CheckCRC(byte crc)
{
	if (crc == 0)
		return true;
	else
		return false;
}

struct Conversion
{
	const byte sensorid;
	void (*func)();
};

const Conversion conv[] = {
	{0x00, ReadMacAdd},
	{0x01, ReadTMP112},
	{0x02, ReadHTU21D},
	{0x03, ReadHIH4030},
	{0x04, ReadBMP180},
	{0x05, ReadPR103J2},
	{0x06, ReadTSL250ms},
	{0x07, ReadMMA},
	{0x08, ReadSPV},
	{0x09, ReadTSYS01},
	{0x0A, ReadHMC},
	{0x0B, ReadHIH6130},
	{0x0C, ReadAPDS},
	{0x0D, ReadTSL260RD},
	{0x0E, ReadTSL250RDls},
	{0x0F, ReadMLX},
	{0x10, ReadML8511},
	{0x13, ReadTMP421},
	{0x15, ReadChem},
};

int numfunc = sizeof(conv);

void CallFunction(const byte data)
{
	// for (int..)
	// {
	// 	for each bytes:
	// 		do under:
	
	for (int i = 0; i < numfunc; i++)
	{
		const Conversion *fn = conv + i;
		//if (strcmp(fn->sensorid, data) == 0)
		if (fn->sensorid == data)
			fn->func();
	}
}
