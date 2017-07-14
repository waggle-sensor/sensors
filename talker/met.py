from RTlist import *
import math

class Metsense():

	def metDecode(self, ID, textlist):
		# Call function according to the sensor ID
		met_dict = {}
		if  ID == 0x00:
			met_dict['MetMac'] = self.decodeMAC(textlist)
			return met_dict
		elif ID == 0x01:
			met_dict['TMP112'] = self.decodeTMP112(textlist)
			return met_dict
		elif ID == 0x02:
			met_dict['HTU21D'] = self.decodeHTU21D(textlist)
			return met_dict
		elif ID == 0x03:
			met_dict['BMP180'] = self.decodeBMP180(textlist)
			return met_dict
		elif ID == 0x04:
			met_dict['PR103J2'] = self.decodePR103J2(textlist)
			return met_dict
		elif ID == 0x05:
			met_dict['TSL250'] = self.decodeTSL250(textlist)
			return met_dict
		elif ID == 0x06:
			met_dict['MMA8452'] = self.decodeMMA8452(textlist)
			return met_dict
		elif ID == 0x07:
			met_dict['SPV1840'] = self.decodeSPV1840(textlist)
			return met_dict
		elif ID == 0x08:
			met_dict['TSYS01'] = self.decodeTSYS01(textlist)
			return met_dict

		else:
			return 0

	def decodeMAC(self, textlist):
		# Temperature
		val1 = int(textlist[0], 16) << 24
		val2 = int(textlist[1], 16) << 16
		val3 = int(textlist[2], 16) << 8
		val4 = int(textlist[3], 16)

		return val1|val2|val3|val4


	def decodeTMP112(self, textlist):
		# Temperature
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)

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

	def decodeHTU21D(self, textlist):
		# Temperature
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)

		# Humidity
		val3 = int(textlist[2], 16) << 8
		val4 = int(textlist[3], 16)

		val = [val1 | val2, val3 | val4]
		if (val[0] & 0x8000) == 0x8000:
			val[0] -= 0x10000
		
		val = [x / 100. for x in val]

		if val[0] > 990 and val[1] > 990:
		# When I2C is not available, return "none"
			return;
		else:
			return val

	def decodeBMP180(self, textlist):
		# Temperature
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)
		# Pressure
		val3 = int(textlist[2], 16) << 24
		val4 = int(textlist[3], 16) << 16
		val5 = int(textlist[4], 16) << 8
		val6 = int(textlist[5], 16)

		val = [val1 | val2, val3 | val4 | val5 | val6]
		if (val[0] & 0x8000) == 0x8000:
			val[0] -= 0x10000
			
		val = [x / 100. for x in val]

		return val

	def decodePR103J2(self, textlist):
		# Temperature
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)

		raw_temp = val1 | val2
		# Temperature calculation, call a function to calculate
		temp_val = getRT(raw_temp) * 100
		temp_val = math.floor(temp_val) / 100
		return temp_val

	def decodeTSL250(self, textlist):
		# light sensor
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)

		raw_light = val1 | val2
		return raw_light

	def decodeMMA8452(self, textlist):
		# Acceleration
		# gx 
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)
		# gy
		val3 = int(textlist[2], 16) << 8
		val4 = int(textlist[3], 16)
		# gz
		val5 = int(textlist[4], 16) << 8
		val6 = int(textlist[5], 16)
		# norm
		val7 = int(textlist[6], 16) << 8
		val8 = int(textlist[7], 16)

		val = [val1 | val2, val3 | val4, val5 | val6, val7 | val8]
		for i in range(len(val)):
			if (val[i] & 0x8000) == 0x8000:
				val[i] -= 0x10000

		val = [x / 100. for x in val]
		return val


	def decodeSPV1840(self, textlist):
		# Sound level
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)

		raw_light = val1 | val2
		return raw_light

	def decodeTSYS01(self, textlist):
		# Temperature
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)

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
		