
const int numEnable = sizeof(enabletable)/sizeof(enabletable[0]);

void EnableSensor(byte thisid)
{
	thisid = Checkid(thisid);

	for (int i = 0; i < numEnable; i++)
	{
		EnabledTable *et = enabledtable + i;
		if (et->enabledsensorid == thisid)
		{
			et->enabled = true;
			break;
		}
	}
}
void DisableSensor(byte thisid)
{
	thisid = Checkid(thisid);

	for (int i = 0; i < numEnable; i++)
	{
		EnabledTable *et = enabledtable + i;
		if (et->enabledsensorid == thisid)
		{
			et->enabled = true;
			break;
		}
	}
}
bool GetEnable(byte thisid)
{
	thisid = Checkid(thisid);

	for (int i = 0; i < numEnable; i++)
	{
		EnabledTable *et = enabledtable + i;
		if (et->enabledsensorid == id)
			return et->enabled;
	}
	return false;
}
byte Checkid(byte thisid)
{
	if (0x28 <= thisid && thisid <= 0x31)
		thisid = 0x30;   // option for alpha sensor
	else if (thisid == 0x16)
		thisid = 0x2A;   // option for chem config

	return thisid;
}



void CallDisableCore(byte *thisid, int length)
{
	if (0x28 <= thisid[0] && thisid[0] <= 0x31)
		thisid[0] = 0x30;

	for (int i = 0; i < numEnable; i++)
	{
		EnabledSensorTable *est = sensortable + i;
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
	for (int i = 0; i < numEnable; i++)
	{
		EnabledSensorTable *est = sensortable + i;
		if (est->enabledsensorid == thisid)
		{
			est->enabled = false;
			break;
		}
	}
}