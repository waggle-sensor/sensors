import math

class Lightsense():

	def lightDecode(self, ID, textlist):
		# Call function according to the sensor ID
		light_dict = {}
		if ID == 0x10:
			light_dict['HMC5883'] = self.decodeHMC5883(textlist)
			return light_dict
		elif ID == 0x11:
			light_dict['HIH6130'] = self.decodeHIH6130(textlist)
			return light_dict
		elif ID == 0x12:
			light_dict['APDS9006'] = self.decodeAPDS9006(textlist)
			return light_dict
		elif ID == 0x13:
			light_dict['TSL260RD'] = self.decodeTSL260RD(textlist)
			return light_dict
		elif ID == 0x14:
			light_dict['TSL250RD'] = self.decodeTSL250RD(textlist)
			return light_dict
		elif ID == 0x15:
			light_dict['MLX75305'] = self.decodeMLX75305(textlist)
			return light_dict
		elif ID == 0x16:
			light_dict['ML8511'] = self.decodeML8511(textlist)
			return light_dict
		elif ID == 0x17:
			light_dict['TMP421'] = self.decodeTMP421(textlist)
			return light_dict

		else:
			return 0

	def decodeHMC5883(self, textlist):
		# Magnetic field
		# Gx
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)
		# Gy
		val3 = int(textlist[2], 16) << 8
		val4 = int(textlist[3], 16)
		# Gz
		val5 = int(textlist[4], 16) << 8
		val6 = int(textlist[5], 16)

		val = [val1 | val2, val3 | val4, val5 | val6]

		for i in range(len(val)):
			# if the value is negative
			if (val[i] & 0x8000) == 0x8000:
				val[i] -= 0x10000

		# From 100th of magnetic field to magnetic field
		val = [float(x) / 100.0 for x in val]
		# orientation need to be calcuated in val[3]
		return val


	def decodeHIH6130(self, textlist):
		# Temperature
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)
		# Humidity
		val3 = int(textlist[2], 16) << 8
		val4 = int(textlist[3], 16)

		val = [val1 | val2, val3 | val4]

		for i in range(len(val)):
			# if the value is negative
			if (val[i] & 0x8000) == 0x8000:
				val[i] -= 0x10000

		val = [x / 100. for x in val]

		return val

	def lightSensors(self, textlist):
		# Raw light
		val1 = int(textlist[0], 16) << 8
		val2 = int(textlist[1], 16)

		val = val1 | val2

		if val == 65535:
			return
		else:
			return val

	def decodeAPDS9006(self, textlist):
		return self.lightSensors(textlist)

	def decodeTSL260RD(self, textlist):
		return self.lightSensors(textlist)

	def decodeTSL250RD(self, textlist):
		return self.lightSensors(textlist)

	def decodeMLX75305(self, textlist):
		return self.lightSensors(textlist)

	def decodeML8511(self, textlist):
		return self.lightSensors(textlist)

	def decodeTMP421(self, textlist):
		# Temperature
		val1 = int(textlist[0], 16) << 8;
		val2 = int(textlist[1], 16)

		val = val1 | val2
		# if the value is negative
		if (val & 0x8000) == 0x8000:
			val -= 0x10000
		val /= 100.
		
		if val > 127:
		# When I2C is not available, return "none"
			return
		else:
			return val