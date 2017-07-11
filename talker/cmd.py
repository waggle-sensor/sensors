

class Commands:

	def GetCmd(self, line):
		return_command = []

		try:
			cmd, args = line.strip().split(' ', 1)
			return_command.append(cmd)
		except:
			return None, line.encode()
			

		# print (return_command)

		value_count = 0
		key = ''
		if cmd == '2SPIwrite':
			arg = args.strip().split(' ')
		
			maxSpeed = arg[0].to_bytes(3, byteorder='big')
			for i in maxSpeed:
				return_command.append()
			# return_command.

		elif cmd == 'Coreread':

			for arg in args.strip().split(' '):

				if 'met' in arg:
					return_command.extend(["tmp112", "htu21d", "bmp180", "pr103j2", "tsl250", "mma8452q", "spv1840", "tsys01"])
					key = None
				elif 'light' in arg:
					return_command.extend(["hmc5883l", "hih6130", "apds9006", "tsl260rd", "tsl250rd", "mlx75305", "ml8511", "tmp421"])
					key = None
				elif 'chem' in arg:
					return_command.extend(["chem"])
					key = None
				else:
					return_command.append(arg)
					key = None


		elif cmd == 'SPIread':

			for arg in args.strip().split(' '):
			
				if value_count > 0:
					return_command.append(str(hex(int(arg))))
					value_count -= 1
					continue

				elif 'fan_power' in arg:
					return_command.extend(["0x42", "0x00"])
					value_count = 1
					key = 'fan_power'
				elif 'laser_power' in arg:
					return_command.extend(["0x42", "0x00"])
					value_count = 1
					key = 'laser_power'
				elif 'power_off' in arg:
					return_command.extend(["0x03", "0x01"])
					key = 'power_off'
				elif 'power_on' in arg:
					return_command.extend(["0x03", "0x00"])
					key = 'power_on'
				elif 'serial' in arg:
					return_command.extend(["0x10"])
					return_command.extend(["0"] * 16)
					key = 'serial'
				elif 'version' in arg:
					return_command.extend(["0x3F"])
					return_command.extend(["0"] * 60)
					key = 'version'
				elif 'config' in arg:
					return_command.extend(["0x3C"])
					return_command.extend(["0"] * 256)
					key = 'config'
				elif 'histogram' in arg:
					return_command.extend(["0x30"])
					return_command.extend(["0"] * 62)
					key = 'histogram'

				else:
					return_command.append(arg)
					key = None
					
		else:
			return None, line.encode()

		return key, ' '.join(return_command).encode()
		