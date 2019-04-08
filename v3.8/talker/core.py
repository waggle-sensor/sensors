# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
from RTlist import *
import math

class Coresense():

	def coreDecode(self, ID, textlist):
		core_dict = {}
		value = [float(x) / 100. for x in textlist]

		if  ID == 0x00:
			core_dict['MetMac'] = textlist
			return core_dict
		elif ID == 0x01:
			core_dict['TMP112'] = value
			return core_dict
		elif ID == 0x02:
			core_dict['HTU21D'] = value
			return core_dict
		elif ID == 0x03:
			core_dict['BMP180'] = value
			return core_dict
		elif ID == 0x04:
			core_dict['PR103J2'] = self.decodePR103J2(textlist)
			return core_dict
		elif ID == 0x05:
			core_dict['TSL250'] = textlist
			return core_dict
		elif ID == 0x06:
			core_dict['MMA8452'] = value
			return core_dict
		elif ID == 0x07:
			core_dict['SPV1840'] = textlist
			return core_dict
		elif ID == 0x08:
			core_dict['TSYS01'] = value
			return core_dict

		if ID == 0x10:
			core_dict['HMC5883'] = value
			return core_dict
		elif ID == 0x11:
			core_dict['HIH6130'] = value
			return core_dict
		elif ID == 0x12:
			core_dict['APDS9006'] = textlist
			return core_dict
		elif ID == 0x13:
			core_dict['TSL260RD'] = textlist
			return core_dict
		elif ID == 0x14:
			core_dict['TSL250RD'] = textlist
			return core_dict
		elif ID == 0x15:
			core_dict['MLX75305'] = textlist
			return core_dict
		elif ID == 0x16:
			core_dict['ML8511'] = textlist
			return core_dict
		elif ID == 0x17:
			core_dict['TMP421'] = value
			return core_dict

		else:
			return 0

	def decodePR103J2(self, textlist):
		# raw register
		raw_temp = int(textlist[0])
		# Temperature calculation, call a function to calculate
		temp_val = getRT(raw_temp) * 100
		temp_val = math.floor(temp_val) / 100
		return [temp_val]
