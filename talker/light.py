import math

class Lightsense():

	def lightDecode(self, ID, line):
		# Call function according to the sensor ID
		light_dict = {}
		if ID == 0x10:
			light_dict['HMC5883'] = self.decodeHMC5883(line)
			return light_dict
		elif ID == 0x11:
			light_dict['HIH6130'] = self.decodeHIH6130(line)
			return light_dict
		elif ID == 0x12:
			light_dict['APDS9006'] = self.decodeAPDS9006(line)
			return light_dict
		elif ID == 0x13:
			light_dict['TSL260RD'] = self.decodeTSL260RD(line)
			return light_dict
		elif ID == 0x14:
			light_dict['TSL250RD'] = self.decodeTSL250RD(line)
			return light_dict
		elif ID == 0x15:
			light_dict['MLX75305'] = self.decodeMLX75305(line)
			return light_dict
		elif ID == 0x16:
			light_dict['ML8511'] = self.decodeML8511(line)
			return light_dict
		elif ID == 0x17:
			light_dict['TMP421'] = self.decodeTMP421(line)
			return light_dict

		else:
			return 0

	def decodeHMC5883(self, line):
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

		for i in range(len(val)):
			# if the value is negative
			if (val[i] & 0x8000) == 0x8000:
				val[i] -= 0x10000

		# From 100th of magnetic field to magnetic field
		val = [float(x) / 100.0 for x in val]
		# orientation need to be calcuated in val[3]
		return val


	def decodeHIH6130(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)
		# Humidity
		val3 = int(text_spl[3], 16) << 8
		val4 = int(text_spl[4], 16)

		val = [val1 | val2, val3 | val4]

		for i in range(len(val)):
			# if the value is negative
			if (val[i] & 0x8000) == 0x8000:
				val[i] -= 0x10000

		val = [x / 100. for x in val]

		return val

	def lightSensors(self, line):
		text_spl = line.strip().split(' ')
		# Raw light
		val1 = int(text_spl[1], 16) << 8
		val2 = int(text_spl[2], 16)

		val = val1 | val2

		if val == 65535:
			return
		else:
			return val

	def decodeAPDS9006(self, line):
		return self.lightSensors(line)

	def decodeTSL260RD(self, line):
		return self.lightSensors(line)

	def decodeTSL250RD(self, line):
		return self.lightSensors(line)

	def decodeMLX75305(self, line):
		return self.lightSensors(line)

	def decodeML8511(self, line):
		return self.lightSensors(line)

	def decodeTMP421(self, line):
		text_spl = line.strip().split(' ')
		# Temperature
		val1 = int(text_spl[1], 16) << 8;
		val2 = int(text_spl[2], 16)

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