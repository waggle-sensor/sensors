from RTlist import *
import math

class Metsense():

	def metDecode(self, ID, line):
		# Call function according to the sensor ID
		met_dict = {}
		if ID == 0x01:
			met_dict['TMP112'] = self.TMP112(line)
			return met_dict
		elif ID == 0x02:
			met_dict['HTU21D'] = self.HTU21D(line)
			return met_dict
		elif ID == 0x03:
			met_dict['BMP180'] = self.BMP180(line)
			return met_dict
		elif ID == 0x04:
			met_dict['PR103J2'] = self.PR103J2(line)
			return met_dict
		elif ID == 0x05:
			met_dict['TSL250'] = self.TSL250(line)
			return met_dict
		elif ID == 0x06:
			met_dict['MMA8452'] = self.MMA8452(line)
			return met_dict
		elif ID == 0x07:
			met_dict['SPV1840'] = self.SPV1840(line)
			return met_dict
		elif ID == 0x08:
			met_dict['TSYS01'] = self.TSYS01(line)
			return met_dict

		else:
			return 0


	def TMP112(self, line):
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

		if float_val < -250:
		# When I2C is not available, return "none"
			return;
		else:
			return round(float_val, 2)
		

	def HTU21D(self, line):
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

		if realTemperature > 120 and humid > 110:
		# When I2C is not available, return "none"
			return;
		else:
			return realTemperature, humid

	def BMP180(self, line):
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

	def PR103J2(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		raw_temp = val1 | val2
		# Temperature calculation, call a function to calculate
		temp_val = getRT(raw_temp) * 100
		temp_val = math.floor(temp_val) / 100
		return temp_val

	def TSL250(self, line):
		text_spl = line.strip().split(' ')
		# light sensor
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		raw_light = val1 | val2
		return raw_light

	def MMA8452(self, line):
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


	def SPV1840(self, line):
		text_spl = line.strip().split(' ')
		# Sound level
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		raw_light = val1 | val2
		return raw_light

	def TSYS01(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 24
		val2 = int(text_spl[2], 16) << 16
		val3 = int(text_spl[3], 16) << 8
		val4 = int(text_spl[4], 16)

		temp_val = val1 | val2 | val3 | val4
		# From 100th of temperature to temperature
		temp_val = temp_val / 100.0
		
		if temp_val > 210:
		# When I2C is not available, return "none"
			return;
		else:
			return temp_val
		