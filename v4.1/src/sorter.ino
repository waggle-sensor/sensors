
struct FunctionType
{
	const byte funcid;
	void (*func)(byte*, int);
};


const FunctionType functype[] = {
    {0x01, initSensor},
	{0x02, configureSensor},
	{0x03, enableSensor},
    {0x04, disableSensor},
	{0x05, readSensor},
    {0x06, writeSensor},

    {0x11, initBus},
	{0x12, configureBus},
	{0x13, enableBus},
    {0x14, disableBus},
	{0x15, readBus},
    {0x16, writeBus},
};

const int numtype = sizeof(functype)/sizeof(functype[0]);
const int numSensor = sizeof(sensor)/sizeof(sensor[0]);
const int numBus = sizeof(bus)/sizeof(bus[0]);

void SortReading(byte *dataReading, int packetLength)
{	
	int request = dataReading[1] & 0xF0;
	int protocol = dataReading[1] & 0x0F;
	int datalength = dataReading[3];

	bool checkcrc = CheckCRC(dataReading[datalength + 4]);

	byte typebyte = 0;
	byte paramlength = 0;

	bool exceptionCheck = false;
	int totalSubpacket = 0;

	// for (int i = 0; i < packetLength; i++)
	//     SerialUSB.write(dataReading[i]);

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
					if (subpacket[1] == 0x16)
					{
						totalSubpacket--;
						exceptionCheck = true;
						ReadChemconfig();
						break;
					}
					else if (subpacket[1] == 0x31)
					{
						totalSubpacket--;
						exceptionCheck = true;
						ReadAlphaConfig();
						break;
					}

					exceptionCheck = false;
					ft->func(subpacket + 1, paramlength);
					break;
				}
			}
			subpacket += paramlength + 1;
			totalSubpacket++;
		}
		if (!exceptionCheck || totalSubpacket > 0)
			PacketSender(0x01);  // last packet of this request
	}
}


void SensorInit()
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		ft->initFunc();
	}
}

void SensorInit(byte *data, int length)
{
	byte thisid = data[0];
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (ft->funcid == thisid)
			ft->initFunc();
	}
}

void SensorConfig (byte *data, int length)
{
	return;
}


void SensorEnable (byte *data, int length)
{
	byte thisid = data[0];
	for (int i = 0; i < numSensor; i++)
	{
		if (ft->funcid == thisid)
		{
			const Sensor *s = sensor + i;
			ft->enableFunc();
		}
	}
}

void SensorDiable(byte *data, int length)
{
	byte thisid = data[0];
	for (int i = 0; i < numSensor; i++)
	{
		if (ft->funcid == thisid)
		{
			const Sensor *s = sensor + i;
			ft->disableFunc();
		}
	}
}

void SensorRead(byte *data, int length)
{	
	byte thisid = data[0];
	bool enable = GetEnable(thisid);

	if (!enable)
		break;

	int repeat = 0;
	int interval = 0;
	if (length == 2)
		repeat = data[1];
	else if (length == 3)
	{
		repeat = data[1];
		interval = data[2];
	}

	byte sensorReading[1024];
	int readingLength = 0;
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (rc->sensorid == thisid)
		{
			if (thisid == 0x2A)
				repeat = 3;
			
			if (length > 1 || thisid == 0x2A)
			{
				for (int i = 0; i < repeat; i++)
				{
					rc->readFunc(sensorReading, &readingLength);
					Packetization(thisid, sensorReading, readingLength);
					delay(interval);
				}
				break;
			}

			rc->readFunc(sensorReading, &readingLength);
			Packetization(thisid, sensorReading, readingLength);
			break;
		}
	}
}


void SensorWrite(byte *data, int length)
{
	return;
}

void BusConfig(byte *data, int length)
{
	return;
}

void BusInit(byte *data, int length)
{
	return;
}

void BusEnable(byte *data, int length)
{
	return;
}

void BusWrite(byte *data, int length)
{
	return;
}

void BusRead(byte *data, int length)
{
	return;
}

void BusDisable(byte *data, int length)
{
	return;
}
