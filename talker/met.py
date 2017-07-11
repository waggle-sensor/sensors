from RTlist import *
import math

class Metsense():

	def metDecode(self, ID, line):
		# Call function according to the sensor ID
		met_dict = {}
		if  ID == 0x00:
			met_dict['MetMac'] = self.decodeMAC(line)
			return met_dict
		elif ID == 0x01:
			met_dict['TMP112'] = self.decodeTMP112(line)
			return met_dict
		elif ID == 0x02:
			met_dict['HTU21D'] = self.decodeHTU21D(line)
			return met_dict
		elif ID == 0x03:
			met_dict['BMP180'] = self.decodeBMP180(line)
			return met_dict
		elif ID == 0x04:
			met_dict['PR103J2'] = self.decodePR103J2(line)
			return met_dict
		elif ID == 0x05:
			met_dict['TSL250'] = self.decodeTSL250(line)
			return met_dict
		elif ID == 0x06:
			met_dict['MMA8452'] = self.decodeMMA8452(line)
			return met_dict
		elif ID == 0x07:
			met_dict['SPV1840'] = self.decodeSPV1840(line)
			return met_dict
		elif ID == 0x08:
			met_dict['TSYS01'] = self.decodeTSYS01(line)
			return met_dict

		else:
			return 0

	def decodeMAC(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 24
		val2 = int(text_spl[2], 16) << 16
		val3 = int(text_spl[3], 16) << 8
		val4 = int(text_spl[4], 16)

		return val1|val2|val3|val4


	def decodeTMP112(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		val = val1 | val2
		# From 100th of temperature to temperature

		# if the value is negative
		if (val & 0x8000) == 0x8000:
			val -= 0x10000

		val = val / 100.0
		
		if val > 255:
		# When I2C is not available, return "none"
			return;
		else:
			return val		

	def decodeHTU21D(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		# Humidity
		val3 = int(text_spl[3], 16) << 8
		val4 = int(text_spl[4], 16)

		val = [val1 | val2, val3 | val4]
		if (val[0] & 0x8000) == 0x8000:
			val[0] -= 0x10000
		
		val = [x / 100. for x in val]

		if val[0] > 990 and val[1] > 990:
		# When I2C is not available, return "none"
			return;
		else:
			return val

	def decodeBMP180(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)
		# Pressure
		val3 = int(text_spl[3], 16) << 24
		val4 = int(text_spl[4], 16) << 16
		val5 = int(text_spl[5], 16) << 8
		val6 = int(text_spl[6], 16)

		val = [val1 | val2, val3 | val4 | val5 | val6]
		if (val[0] & 0x8000) == 0x8000:
			val[0] -= 0x10000
			
		val = [x / 100. for x in val]

		return val

	def decodePR103J2(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		raw_temp = val1 | val2
		# Temperature calculation, call a function to calculate
		temp_val = getRT(raw_temp) * 100
		temp_val = math.floor(temp_val) / 100
		return temp_val

	def decodeTSL250(self, line):
		text_spl = line.strip().split(' ')
		# light sensor
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		raw_light = val1 | val2
		return raw_light

	def decodeMMA8452(self, line):
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
		# norm
		val7 = int(text_spl[7], 16) << 8
		val8 = int(text_spl[8], 16)

		val = [val1 | val2, val3 | val4, val5 | val6, val7 | val8]
		for i in range(len(val)):
			if (val[i] & 0x8000) == 0x8000:
				val[i] -= 0x10000

		val = [x / 100. for x in val]
		return val


	def decodeSPV1840(self, line):
		text_spl = line.strip().split(' ')
		# Sound level
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		raw_light = val1 | val2
		return raw_light

	def decodeTSYS01(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		val = val1 | val2
		if (val & 0x8000) == 0x8000:
			val -= 0x10000
		# From 100th of temperature to temperature
		val = val / 100.0
		
		if val > 210:
		# When I2C is not available, return "none"
			return;
		else:
			return val
		