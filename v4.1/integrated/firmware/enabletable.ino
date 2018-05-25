
void EnableSensor(byte thisid)
{
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
	for (int i = 0; i < numEnabled; i++)
	{
		EnabledTable *et = enabledtable + i;
		if (et->enabledsensorid == thisid)
		{
			SerialUSB.println(et->enabled);
			return et->enabled;
		}
	}
	return false;
}
