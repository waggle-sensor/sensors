from RTlist import *
import math

def metDecode(ID, line):
	# Call function according to the sensor ID
	met_dict = {}
	if ID == int(0x01):
		met_dict['TMP112'] = TMP112(line)
		return met_dict
	elif ID == int(0x02):
		met_dict['HTU21D'] = HTU21D(line)
		return met_dict
	elif ID == int(0x03):
		met_dict['BMP180'] = BMP180(line)
		return met_dict
	elif ID == int(0x04):
		met_dict['PR103J2'] = PR103J2(line)
		return met_dict
	elif ID == int(0x05):
		met_dict['TSL250'] = TSL250(line)
		return met_dict
	elif ID == int(0x06):
		met_dict['MMA8452'] = MMA8452(line)
		return met_dict
	elif ID == int(0x07):
		met_dict['SPV1840'] = SPV1840(line)
		return met_dict
	elif ID == int(0x08):
		met_dict['TSYS01'] = TSYS01(line)
		return met_dict

	else:
		return 0


def TMP112(line):
	text_spl = line.strip().split(' ')
	val1 = int(text_spl[1], 16)
	val2 = int(text_spl[2], 16)

	# hex to float data transformation, temperature
	if ((val1 & 0x80) == 0x00):
		int_val = val1
		int_val = int_val << 5
		int_val = int_val | (val2 >> 3)
		float_val = (int_val & 0x0FFF) * 0.0625

	else:
		val1 = ~val1
		val2 = ~val2
		int_val = val1
		int_val = int_val << 5
		int_val = int_val | (val2 >> 3)
		float_val = (int_val & 0x0FFF)*-0.0625

	return round(float_val, 2)
	# print (float_val)

def HTU21D(line):
	text_spl = line.strip().split(' ')
	# Temperature
	val1 = int(text_spl[1], 16)
	val2 = int(text_spl[2], 16)
	# Humidity
	val3 = int(text_spl[3], 16)
	val4 = int(text_spl[4], 16)

	# Temperature calculation
	rawTemperature = (val1 << 8) | val2
	rawTemperature &= 0xFFFC
	tempTemperature = rawTemperature / 65536.0
	realTemperature = round(175.72 * tempTemperature - 46.85, 2)

	# Humidity calculation
	rawHumidity = (val3 << 8) | val4
	rawHumidity &= 0xFFFC
	tempRH = rawHumidity / 65536.0
	rh = -6 + (125.0 * tempRH)
	humid = (((rawHumidity * 12500) >> 16) - 600) / 100.0;

	return realTemperature, humid

def BMP180(line):
	text_spl = line.strip().split(' ')
	# Temperature
	val1 = int(text_spl[1], 16) << 24
	val2 = int(text_spl[2], 16) << 16
	val3 = int(text_spl[3], 16) << 8
	val4 = int(text_spl[4], 16)
	# Pressure
	val5 = int(text_spl[5], 16) << 24
	val6 = int(text_spl[6], 16) << 16
	val7 = int(text_spl[7], 16) << 8
	val8 = int(text_spl[8], 16)


	val_temp = val1 | val2 | val3 | val4
	# Temperature calculation
	temp_val = (val_temp + 8) >> 4;
	temp_val /= 10;

	# Pressure formation
	val_press = val5 | val6 | val7 | val8

	return temp_val, val_press

def PR103J2(line):
	text_spl = line.strip().split(' ')
	# Temperature
	val1 = int(text_spl[1], 16) << 8
	val2 = int(text_spl[2], 16)

	raw_temp = val1 | val2
	# Temperature calculation, call a function to calculate
	temp_val = round(getRT(raw_temp), 2)
	return temp_val

def TSL250(line):
	text_spl = line.strip().split(' ')
	# light sensor
	val1 = int(text_spl[1], 16) << 8
	val2 = int(text_spl[2], 16)

	raw_light = val1 | val2
	return raw_light

def MMA8452(line):
	text_spl = line.strip().split(' ')
	# Acceleration
	# gx 
	val1 = int(text_spl[1], 16) << 8
	val2 = int(text_spl[2], 16)
	# gy
	val3 = int(text_spl[3], 16) << 8
	val4 = int(text_spl[4], 16)
	# gz
	val5 = int(text_spl[5], 16) << 8
	val6 = int(text_spl[6], 16)

	val = [val1 | val2, val3 | val4, val5 | val6]
	# Acceleration calculation
	val = [float(x) / ((1 << 12) / 4) for x in val]
	# Average of the acceleration
	avg = math.sqrt(sum([math.pow(x, 2) for x in val]))
	val.append(avg)
	# Round values with 2 decimal points
	val = [round(x, 2) for x in val]
	return val


def SPV1840(line):
	text_spl = line.strip().split(' ')
	# Sound level
	val1 = int(text_spl[1], 16) << 8
	val2 = int(text_spl[2], 16)

	raw_light = val1 | val2
	return raw_light

def TSYS01(line):
	text_spl = line.strip().split(' ')
	# Temperature
	val1 = int(text_spl[1], 16) << 24
	val2 = int(text_spl[2], 16) << 16
	val3 = int(text_spl[3], 16) << 8
	val4 = int(text_spl[4], 16)

	temp_val = val1 | val2 | val3 | val4
	# From 100th of temperature to temperature
	temp_val = temp_val / 100.0
	return temp_val
	