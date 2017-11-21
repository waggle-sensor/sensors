
byte sensorReading[1024];
int readingLength = 0;

void SortReading(byte *packet, int dataLength)
{
	PacketInit();
	BusPacketInit();
	byte *subpacket = packet + 4;  // put subpacket value as address of last packet byte
	while (subpacket < &packet[dataLength + 3])
	{
		byte type = subpacket[0];
		// byte ack = subpacket[1] & 0x80;
		byte paramLength = subpacket[1] & 0x7F;
		byte id = subpacket[2];

		SerialUSB.print("parameter length   ");
		SerialUSB.println(paramLength);

		byte Asubpacket[paramLength + 1];
		for (int i = 0; i < paramLength + 1; i++)
			Asubpacket[i] = subpacket[i + 1];

		for (int i = 0; i < numType; i++)
		{
			const FunctionType *ft = functype + i;
			if (ft->funcid == type)
			{
				ft->func(Asubpacket, id);
				break;
			}
		}
		subpacket += paramLength + 2;
	}
	int SensorReadingLength = ReturnPacketLength();
	int BusReadingLength = BusReturnPacketLength();
	if (SensorReadingLength > 4)
		PacketSender(0x01);
	if (BusReadingLength > 4)
		BusPacketSender(0x01);

}

void SensorInit()
{
	// Enable mandatory sensors
	for (int i = 0; i < numMand; i++)
	{
		const MandatorySensor *ms = mandsensor + i;
		ms->enableFunc();
	}

	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		s->initFunc();
	}
}

void SensorInit(byte *data, byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->initFunc();
			break;
		}
	}
}

void SensorConfig(byte *data, byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->configFunc();
			break;
		}
	}
}

void SensorEnable(byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->enableFunc();
			break;
		}
	}
}

void SensorEnable(byte *data, byte id)
{
	SensorEnable(id);
}

void SensorDisable(byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->disableFunc();
			break;
		}
	}
}

void SensorDisable(byte *data, byte id)
{
	SensorDisable(id);
}

void SensorRead(byte *data, byte id)
{
	bool enable = GetEnable(id);

	if (!enable)
		return;

	int paramLength = data[0] & 0x7F;
	int repeat = 0;
	int interval = 0;
	if (paramLength == 2)
		repeat = data[1];
	else if (paramLength == 3)
	{
		repeat = data[1];
		interval = 1000 / data[2];
	}

	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			if (id == 0x2A)
				repeat = 3;
			
			if (paramLength > 1 || id == 0x2A)
			{
				for (int i = 0; i < repeat; i++)
				{
					s->readFunc(sensorReading, &readingLength);
					Packetization(id, sensorReading, readingLength);
					delay(interval);
				}
				break;
			}

			s->readFunc(sensorReading, &readingLength);
			Packetization(id, sensorReading, readingLength);
			break;
		}
	}
}


void SensorWrite(byte *data, byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Sensor *s = sensor + i;
		if (s->sensorid == id)
		{
			s->writeFunc(data);
			break;
		}
	}
}





void BusInit(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->initFunc(data);
			break;
		}
	}
}

void BusConfig(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->configFunc(data);
			break;
		}
	}
}
void BusEnable(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->enableFunc();
			break;
		}
	}
}
void BusDisable(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->disableFunc();
			break;
		}
	}
}
void BusRead(byte *data, byte id)
{
	for (int i = 0; i < numBus; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{			
			b->readFunc(data, sensorReading, &readingLength);
			BusPacketization(id, sensorReading, readingLength);
			break;
		}
	}
}
void BusWrite(byte *data, byte id)
{
	for (int i = 0; i < numSensor; i++)
	{
		const Bus *b = bus + i;
		if (b->busid == id)
		{
			b->writeFunc(data);
			break;
		}
	}
}

