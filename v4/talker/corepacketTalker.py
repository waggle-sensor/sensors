#!/usr/bin/env python3
from serial import Serial
import sys
import re
import time
import datetime
import argparse

import binascii

# from core import *
# from serialread import *
# from alpha import *
# from cmd import *

# coresense = Coresense()
# serialread = Serialread()
# alphasensor = Alphasensor()
# commands = Commands()

# linehex = 64
# val = []
# for i in range(linehex):
#     val.append(0x00)

parser = argparse.ArgumentParser(
	description='Now this python script can use three arguments. At lease, you have to identify a serial port.')

parser.add_argument('-s', dest='serial_device', help='Path to serial port')
# parser.add_argument('-c', dest='command_list', help='Path to command list')
# parser.add_argument('-r', dest='repeat', help='Repeat the command list', action='store_true')

args = parser.parse_args()
print(args)

with Serial(args.serial_device, baudrate=115200, timeout=4) as ser:
	while True:
		try:
			cmd = input('$ ')

			if cmd == 'exit':
				break

			print (str(datetime.datetime.now()).strip().split('.')[0])
			print(cmd)

			# if '1' in cmd:
			# 	cmd = '022104'
			# elif '2' in cmd:
			# 	cmd = '024101'
#			elif '3' in cmd:
#				cmd = '023100'

			cmd = 'aa02%s0055' % (cmd,)
			# cmd = 'aa02 04 01 0501%s 0055' % (cmd,)
			# cmd = 'aa0201012A0055'
			print(cmd)

			ser.write(bytes(bytearray.fromhex(cmd)))
			ser.write(b'\n')

			while True:
				line = ser.readline()
				# 				.decode()

				# print(len(line))
				print(str(line))

				# if (line[2] == 0x16):
				# 	print(line.decode("utf-8"))
					
				if 'U' in str(line):
					if (len(line) > 0):
						check = line[2] & 0x80
					else:
						check = 0

					if check == 0x80:
						break
				elif 'End' in str(line):
					break

		except KeyboardInterrupt:
			break
		# except Exception as ex:
		# 	print(ex)
