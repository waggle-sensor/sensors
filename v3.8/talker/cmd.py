# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
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

		if cmd == 'Coreread':

			for arg in args.strip().split(' '):

				if 'met' in arg:
					return_command.extend(["tmp112", "htu21d", "bmp180", "pr103j2", "tsl250", "mma8452q", "spv1840", "tsys01"])
					key = None
				elif 'light' in arg:
					return_command.extend(["hmc5883l", "hih6130", "apds9006", "tsl260rd", "tsl250rd", "mlx75305", "ml8511", "tmp421"])
					key = None
				else:
					return_command.append(arg)
					key = None

			# Corewrite don't need to translate inputs (mac, 12345) to hex


		elif cmd == 'Serialconfig':
			values = [int(x) for x in args.strip().split(' ')]

			return_command.append("0x{:02x}".format(values[0]))
			return_command.extend(["0x{:02x}".format(values[1] >> 16), "0x{:02x}".format((values[1] >> 8) & 0xff), "0x{:02x}".format(values[1] & 0xff)])
			return_command.extend(["0x{:02x}".format(values[2] >> 16), "0x{:02x}".format((values[2] >> 8) & 0xff), "0x{:02x}".format(values[2] & 0xff)])
			return_command.append("0x{:02x}".format(values[3]))

		elif cmd == 'Serialread':
			return_command.append("0x{:02x}".format(int(args)))

		elif cmd == 'Serialpower':
			values = [int(x) for x in args.strip().split(' ')]
			for i in range(len(values)):
				return_command.append("0x{:02x}".format(values[i]))
			print(return_command)

			# To write something through serial, need to implement elif function to translate inputs to hex string



		elif cmd == 'SPIconfig':
			values = args.strip().split(' ')
			values[0] = int(values[0])
			values[1] = int(values[1])

			return_command.append("0x{:02x}".format(values[0]))
			return_command.extend(["0x{:02x}".format(values[1] >> 16), "0x{:02x}".format((values[1] >> 8) & 0xff), "0x{:02x}".format(values[1] & 0xff)])
			
			if 'MSB' in values[2]:
				return_command.append("0x01")
			else:
				return_command.append("0x00")

			if '0' in values[3]:
				return_command.append("0x00")
			elif '1' in values[3]:
				return_command.append("0x04")
			elif '2' in values[3]:
				return_command.append("0x08")
			else:
				return_command.append("0x0c")

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
					return_command.append("0x{:02x}".format(int(arg)))
					key = None
					
		else:
			return None, line.encode()

		return key, ' '.join(return_command).encode()
		
