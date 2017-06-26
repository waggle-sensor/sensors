def macDecode(line):
	text_spl = line.strip().split(' ')
	# data = ''

	Mac_dict = {}
	if len(text_spl) == 2:
		# if it is the Mac addr for Met/Light board,
		Met_Mac = int(text_spl[1])
		Mac_dict['MetMac'] = Met_Mac
		# print(type(Met_Mac))
		return Mac_dict
	else:
		# else if it is a line from Chemsense board,
		new_line = ChemLine(line)
		# for i in range(1, len(text_spl)):
		# 	a = chr(int(text_spl[i], 16))
		# 	data = data + a

		# Grap Chemsense Mac address only
		temp = new_line.strip().split(' ')
		if len(temp) > 2:
			temp = temp[0].split('=')
			Chem_Mac = temp[1]
			Mac_dict['ChemMac'] = Chem_Mac
		# print(Chem_Mac)
		return Mac_dict

def ChemLine(line):
	# For the chemsense data,
	# Grap line and change to human readable char
	text_spl = line.strip().split(' ')
	data = ''

	for i in range(1, len(text_spl)):
		a = chr(int(text_spl[i], 16))
		data = data + a

	return data

	# temp = data.split(' ')
	# temp = temp[0].split('=')
	# Chem_Mac = temp[1]
	# # print(Chem_Mac)
	# return Chem_Mac

def ChemDecode(line):
	new_line = ChemLine(line)

	chem_dict = {}
	temp = new_line.strip().split(' ')
	for i in range(1, len(temp)):
		a_data = temp[i].split('=')
		# print(a_data)
		# ChemSensorID = GetChemID(a_data[0])
		# print(ChemSensorID)
		key = a_data[0]
		val = a_data[1]

		if a_data[0] != 'BAD' and a_data[0] != 'SQN':
			if 'SH' in key or 'HD' in key or 'LP' in key or 'AT' in key or 'LT' in key:
				val = float(val)/100.0
				chem_dict[key] = val
			else:
				chem_dict[key] = int(val)

	return chem_dict
	# print (chem_dict)
	# print (new_line)
	# # Raw light
	# val1 = int(text_spl[1], 16)
	# val2 = int(text_spl[2], 16)

	# val = (val1 << 8) | val2
	# return val

# def GetChemID(key):
# 	if key == 'SHT':
# 		return 0x20
# 	elif key == 'SHH':
# 		return 0x21
# 	elif key == 'HDT':
# 		return 0x22
# 	elif key == 'HDH':
# 		return 0x23
# 	elif key == 'LPT':
# 		return 0x24
# 	elif key == 'LPP':
# 		return 0x25
# 	elif key == 'SUV':
# 		return 0x26
# 	elif key == 'SVL':
# 		return 0x27
# 	elif key == 'SIR':
# 		return 0x28
# 	elif key == 'IRR':
# 		return 0x29
# 	elif key == 'IAQ':
# 		return 0x2A
# 	elif key == 'SO2':
# 		return 0x2B
# 	elif key == 'H2S':
# 		return 0x2C
# 	elif key == 'OZO':
# 		return 0x2D
# 	elif key == 'NO2':
# 		return 0x2E
# 	elif key == 'CMO':
# 		return 0x2F
# 	elif key == 'AT0':
# 		return 0x30
# 	elif key == 'AT1':
# 		return 0x31
# 	elif key == 'AT2':
# 		return 0x32
# 	elif key == 'AT3':
# 		return 0x33
# 	elif key == 'LTM':
# 		return 0x34
# 	else:
# 		return 0