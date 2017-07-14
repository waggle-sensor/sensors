#!/usr/bin/env python3
from serial import Serial
import sys
import re
import time
import datetime
import argparse

from met import *
from light import *
from serialread import *
from alpha import *
from cmd import *

metsense = Metsense()
lightsense = Lightsense()
serialread = Serialread()
alphasensor = Alphasensor()
commands = Commands()

# linehex = 64
# val = []
# for i in range(linehex):
#     val.append(0x00)

parser = argparse.ArgumentParser(
	description='Now this python script can use three arguments. At lease, you have to identify a serial port.')

parser.add_argument('-s', dest='serial_device', help='Path to serial port')
parser.add_argument('-c', dest='command_list', help='Path to command list')
parser.add_argument('-r', dest='repeat', help='Repeat the command list', action='store_true')

args = parser.parse_args()
print(args)

# Read commands from a file
CMD = []
CMDlist = []
CMDinit = []
if args.command_list is not None:
	loop = False
	with open(args.command_list, 'r') as file:
		for line in file:
			
			if 'loop' in line:
				loop = True
				continue

			if loop == False:
				CMDinit.append(line.strip())
			else:
				CMD.append(line.strip())
	CMDlist = CMD
	CMDinit.extend(CMD)
	CMD = CMDinit
	# print(CMD)

with Serial(args.serial_device, baudrate=115200, timeout=10) as ser:
	while True:
		try:
			if len(CMD) == 0:
				if args.repeat is not False:
					CMD.extend(CMDlist)
					cmd = CMD[0]
					del CMD[0]
				else:
					cmd = input('$ ')
			else:
				cmd = CMD[0]
				del CMD[0]

			if cmd == 'exit':
				break

			item, comm = commands.GetCmd(cmd)
			print (str(datetime.datetime.now()).strip().split('.')[0])

			# a = str(datetime.datetime(2017, 7, 13, 14, 44, 0, 0) - datetime.datetime.now())
			# b = a.strip().split('.')[0].split(':')
			# if int(b[0]) == 0 and int(b[1]) == 0 and int(b[2]) < 30:
			# 	exit(0)
			# else:
			# 	print(a)
			# print(comm)

			ser.write(comm)
			ser.write(b'\n')

			while True:
				line = ser.readline().decode()
				# print(line)

				if len(line) == 0:
					print('timeout')
					break

				match = re.match('(ok:|err:|data|end:) (.*)', line)

				if match is None:
					continue

				status, text = match.groups()
				# print(status)
				if status == 'end:':
					# print (text)
					break


				# test shpark change hex string to hex integer
				text_spl = text.strip().split(" ")
				
				# the first byte of data is sensor identification number
				sensorID = int(text_spl[0], 16)

				if sensorID < 0x10:
					return_val = metsense.metDecode(sensorID, text_spl[1:])

				elif sensorID < 0x20:
					return_val = lightsense.lightDecode(sensorID, text_spl[1:])

				elif sensorID >= 0xc1 and sensorID <= 0xc3:
					return_val = serialread.serialDecode(sensorID, text_spl[1:])

				elif sensorID == 0x28:
					return_val = alphasensor.alphaDecode(item, text_spl[1:])
				else:
					print (text)
					continue


				if isinstance(return_val, tuple):
					for val in return_val:
						print(val)
				else:
					print (return_val)


		except KeyboardInterrupt:
			break
