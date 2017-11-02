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
			# 	cmd = '022101'
#			elif '3' in cmd:
#				cmd = '023100'

			cmd = 'aa020102%s0055' % (cmd,)  # preamble(aa) type|protocel(02) sequence(01) DATAlength(%s) data(%s) crc=true(00) postscript(55)
			# cmd = 'aa0201012A0055'
			print(cmd)

			ser.write(bytes(bytearray.fromhex(cmd)))
			ser.write(b'\n')

			while True:
				line = ser.readline().decode()
				print(line)
				if 'end' in line:
					break

		except KeyboardInterrupt:
			break
		# except Exception as ex:
		# 	print(ex)
