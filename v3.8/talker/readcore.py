# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
from RTlist import *
import math

class Coresense():

	def decodeTMP112(self, textlist):

		if ((textlist[0] & 0x80) == 0x00):
			# it is a positive temperature
			Temp_uint16 = textlist[0];
			Temp_uint16 = Temp_uint16 << 5;
			Temp_uint16 = Temp_uint16 | (textlist[1] >> 3);
			CalculatedTemperature = (Temp_uint16 & 0x0FFF) * 0.0625;
		else:
			textlist[0] = ~textlist[0];
			textlist[1] = ~textlist[1];
			Temp_uint16 = textlist[0];
			Temp_uint16 = Temp_uint16 << 5;
			Temp_uint16 = Temp_uint16 | (textlist[1] >> 3);
			CalculatedTemperature = (Temp_uint16 & 0x0FFF)*-0.0625;


	def decodePR103J2(self, textlist):
		# raw register
		raw_temp = int(textlist[0])
		# Temperature calculation, call a function to calculate
		temp_val = getRT(raw_temp) * 100
		temp_val = math.floor(temp_val) / 100
		return [temp_val]
