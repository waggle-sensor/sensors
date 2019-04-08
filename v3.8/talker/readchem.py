# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
class Serialread():

	def serialDecode(self, ID, textlist):
		# if ID == 0xC3:
		# 	return self.chemDecode(textlist)

		return self.chemDecode(textlist)

	def chemDecode(self, textlist):
		data = ''
		for i in range(len(textlist)):
			charactor = chr(int(textlist[i], 16))
			data = data + charactor

		print(data)

		chem_dict = {}
		temp = data.strip().split(' ')

		if len(temp) < 2:
			chem_dict['CHEM'] = None
			return chem_dict


		for i in range(len(temp)):
			a_data = temp[i].split('=')

			key = a_data[0]
			val = a_data[1]

			if 'SQN' in key:
				continue
			elif 'BAD' in key:
				chem_dict['ChemMac'] = val
			elif 'SH' in key or 'HD' in key or 'LP' in key or 'AT' in key or 'LT' in key:
				val = float(val)/100.0
				chem_dict[key] = val
			else:
				chem_dict[key] = [int(val)]

		return chem_dict
