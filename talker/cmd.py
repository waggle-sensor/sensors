

class Commands:

	def GetCmd(self, line):
		# assemble command
		line_cmd = line.strip().split(' ')
		cmd = line_cmd[0]

		if line_cmd[0] == '2read':
			for i in range(1, len(line_cmd)):
				if line_cmd[i] == 'met' or line_cmd[i] == 'light' or line_cmd[i] == 'chem':
					return self.AssembleCmd(line_cmd[i])
				# elif line_cmd[i] == 'light':
				# 	return self.AssembleCmd(line_cmd[i])
				# elif line_cmd[i] == 'chem':
				# 	return self.AssembleCmd(line_cmd[i])
				# elif line_cmd[i] == 'alpha':
				# 	cmd = cmd + self.AlphaComm(i, line)
				# 	return cmd
				else:
					return line
		else:
			return line
		# else:
		# 	continue


	# def MetCmd(self):
	# 	return ["2read", "tmp112", "htu21d", "bmp180", "pr103j2", "tsl250", "mma8452q", "spv1840", "tsys01"]

	# def LightCmd(self):
	# 	return ["2read", "hmc5883l", "hih6130", "apds9006", "tsl260rd", "tsl250rd", "mlx75305", "ml8511", "tmp421"]

	# def ChemCmd(self):
	# 	return ["2read", "chem"]

	def AssembleCmd(self, key):
		if key == 'met':
			comm = ["2read", "tmp112", "htu21d", "bmp180", "pr103j2", "tsl250", "mma8452q", "spv1840", "tsys01"]
		elif key == 'light':
			comm = ["2read", "hmc5883l", "hih6130", "apds9006", "tsl260rd", "tsl250rd", "mlx75305", "ml8511", "tmp421"]
		elif key == 'chem':
			comm = ["2read", "chem"]		

		dol = ' '.join(comm).encode()
		return dol
