import math

def lightDecode(ID, line):
	# Call function according to the sensor ID
	light_dict = {}
	if ID == 0x10:
		light_dict['HMC5883'] = HMC5883(line)
		return light_dict
	elif ID == 0x11:
		light_dict['HIH6130'] = HIH6130(line)
		return light_dict
	elif ID == 0x12:
		light_dict['APDS9006'] = APDS9006(line)
		return light_dict
	elif ID == 0x13:
		light_dict['TSL260RD'] = TSL260RD(line)
		return light_dict
	elif ID == 0x14:
		light_dict['TSL250RD'] = TSL250RD(line)
		return light_dict
	elif ID == 0x15:
		light_dict['MLX75305'] = MLX75305(line)
		return light_dict
	elif ID == 0x16:
		light_dict['ML8511'] = ML8511(line)
		return light_dict
	elif ID == 0x17:
		light_dict['TMP421'] = TMP421(line)
		return light_dict

	else:
		return 0

def HMC5883(line):
	text_spl = line.strip().split(' ')
	# Magnetic field
	# Gx
	val1 = int(text_spl[1], 16) << 8
	val2 = int(text_spl[2], 16)
	# Gy
	val3 = int(text_spl[3], 16) << 8
	val4 = int(text_spl[4], 16)
	# Gz
	val5 = int(text_spl[5], 16) << 8
	val6 = int(text_spl[6], 16)

	val = [val1 | val2, val3 | val4, val5 | val6]
	# From 100th of magnetic field to magnetic field
	val = [float(x) / 100.0 for x in val]
	# orientation need to be calcuated
	avg = math.sqrt(sum([math.pow(x, 2) for x in val]))
	val.append(avg)
	val = [round(x, 2) for x in val]
	return val


def HIH6130(line):
	text_spl = line.strip().split(' ')
	# Temperature
	val1 = int(text_spl[1], 16) << 8
	val2 = int(text_spl[2], 16)
	# Humidity
	val3 = int(text_spl[3], 16) << 8
	val4 = int(text_spl[4], 16)

	val = [val1 | val2, val3 | val4]

	# Temperature
	val_temp = round(float(val[0]) * 1.007e-2 - 40.0, 2)
	# Humidity
	val_humid = round(float(val[1]) * 6.10e-3, 2)
	return val_temp, val_humid

def LightSensors(line):
	text_spl = line.strip().split(' ')
	# Raw light
	val1 = int(text_spl[1], 16)
	val2 = int(text_spl[2], 16)

	val = (val1 << 8) | val2
	return val

def APDS9006(line):
	return LightSensors(line)

def TSL260RD(line):
	return LightSensors(line)

def TSL250RD(line):
	return LightSensors(line)

def MLX75305(line):
	return LightSensors(line)

def ML8511(line):
	return LightSensors(line)

def TMP421(line):
	text_spl = line.strip().split(' ')
	# Temperature
	val1 = int(text_spl[1], 16)
	val2 = int(text_spl[2], 16)

	val_temp = 0.0
	# Assemble the fraction
	bit = val2 & 0x01
	val_temp += (bit * 0.5) * (bit * 0.5) * (bit * 0.5) * (bit * 0.5)

	val2 >>= 1
	bit = val2 & 0x01
	val_temp += (bit * 0.5) * (bit * 0.5) * (bit * 0.5)

	val2 >>= 1
	bit = val2 & 0x01
	val_temp += (bit * 0.5) * (bit * 0.5)

	val2 >>= 1
	bit = val2 & 0x01
	val_temp += (bit * 0.5)

	# Add the MSB to the fraction
	val_temp += val1
	return val_temp