
void EnableSensor(byte thisid)
{
	thisid = Checkid(thisid);

	for (int i = 0; i < numEnabled; i++)
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
	for (int i = 0; i < numEnabled; i++)
	{
		EnabledTable *et = enabledtable + i;
		if (et->enabledsensorid == thisid)
		{
			et->enabled = false;
			break;
		}
	}
}
bool GetEnable(byte thisid)
{
	thisid = Checkid(thisid);

	for (int i = 0; i < numEnabled; i++)
	{
		EnabledTable *et = enabledtable + i;
		if (et->enabledsensorid == thisid)
			return et->enabled;
	}
	return false;
}
byte Checkid(byte thisid)
{
	if (0x28 <= thisid && thisid <= 0x31)
		thisid = 0x28;   // option for alpha sensor
	else if (thisid == 0x16)
		thisid = 0x2A;   // option for chem config

	return thisid;
}

