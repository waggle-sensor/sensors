class Chemsense():

	def macDecode(self, line):
		text_spl = line.strip().split(' ')
		# data = ''

		Mac_dict = {}
		if len(text_spl) == 2:
			# if it is the Mac addr for Met/Light board,
			Met_Mac = int(text_spl[1])
			Mac_dict['MetMac'] = Met_Mac
			# print(type(Met_Mac))
			return Mac_dict
		elif len(text_spl) > 2:
			# else if it is a line from Chemsense board,
			new_line = self.chemLine(line)

			# Grap Chemsense Mac address only
			temp = new_line.strip().split(' ')
			if len(temp) > 2:
				temp = temp[0].split('=')
				Chem_Mac = temp[1]
				Mac_dict['ChemMac'] = Chem_Mac
			# print(Chem_Mac)
			return Mac_dict
		else:
			Mac_dict['ChemMac'] = None
			return Mac_dict

	def chemLine(self, line):
		# For the chemsense data,
		# Grap line and change to human readable char
		text_spl = line.strip().split(' ')
		data = ''

		for i in range(1, len(text_spl)):
			a = chr(int(text_spl[i], 16))
			data = data + a

		return data

	def chemDecode(self, line):
		new_line = self.chemLine(line)

		chem_dict = {}
		temp = new_line.strip().split(' ')

		if len(temp) < 2:
			chem_dict['CHEM'] = None
			return chem_dict


		for i in range(1, len(temp)):
			a_data = temp[i].split('=')

			key = a_data[0]
			val = a_data[1]

			if a_data[0] != 'BAD' and a_data[0] != 'SQN':
				if 'SH' in key or 'HD' in key or 'LP' in key or 'AT' in key or 'LT' in key:
					val = float(val)/100.0
					chem_dict[key] = val
				else:
					chem_dict[key] = int(val)

		return chem_dict