
void SortReading(byte *dataReading, int length)
{
	int datalength = dataReading[3];
	bool checkcrc = CheckCRC(dataReading[datalength + 4]);
	if (checkcrc)
	{
		byte data[datalength];
		for (int i = 0; i < datalength; i++)
			data[i] = dataReading[4 + i];
		CallReadFunction(data);
	}
	else
		ReturnFalse();
}

void ReturnFalse()
{
	// send any sign that the request packet is not correct
}

bool CheckCRC(byte crc)
{
	if (crc == 0)
		return true;
	else
		return false;
}

struct ReadCoresense
{
	const byte sensorid;
	void (*func)();
};

const ReadCoresense readcore[] = {
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

int numreadcore = sizeof(readcore);

void CallReadFunction(byte *data)
{
	// assume the input byte array contains three subpackets

	// for (int..)
	// {
	// 	for each bytes:
	// 		do under:

	for (int i = 0; i < sizeof(data); i++)
	{
		SerialUSB.print("data");
		SerialUSB.println(data[i]);
	}

	// SerialUSB.println(String(data));
	
	for (int i = 0; i < numreadcore; i++)
	{
		const ReadCoresense *fn = readcore + i;
		//if (strcmp(fn->sensorid, data) == 0)
		if (fn->sensorid == data[0])
			fn->func();
	}
}
