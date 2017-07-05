#!/usr/bin/env python3
from serial import Serial
import sys
import re
import time
import datetime

from met import *
from light import *
from chem import *
from alpha import *
from cmd import *

metsense = Metsense()
lightsense = Lightsense()
chemsense = Chemsense()
alphasensor = Alphasensor()
commands = Commands()

t = 0
first = True

# linehex = 64
# val = []
# for i in range(linehex):
#     val.append(0x00)

with Serial(sys.argv[1], baudrate=115200, timeout=10) as ser:
	while True:
		try:
			cmd = input('$ ')

			if cmd == 'exit':
				break

			# if t == 0:
			# 	time.sleep(60)

			# if first == False:
			# 	test_cmd = ['2read met light', '2read alpha histogram', '2read alpha config']
			# 	cmd = test_cmd[t]
				
			# 	if t == 0:
			# 		t = 1
			# 	elif t == 1:
			# 		t = 2
			# 	else:
			# 		t = 0

			# elif first == True:
			# 	first = False
			# 	cmd = '2read alpha power_on'

			# cmd = '2request met light chem chem chem mac'

			item, comm = commands.GetCmd(cmd)
			# print(comm)
			# dol = ' '.join(comm).encode()
			# print(dol)

			ser.write(comm)
			ser.write(b'\n')
			print (str(datetime.datetime.now()).strip().split('.')[0])

			while True:
				line = ser.readline().decode()
				# print(line)

				if len(line) == 0:
					print('timeout')
					break

				match = re.match('(ok:|err:|data) (.*)', line)

				if match is None:
					continue

				status, text = match.groups()

				# print(status)
				# if status == 'ok:' or status == 'err:':
				if status == 'ok:':
					# print("hello hell")
					# print (text)
					break
				# else:
				#     print ("Please print anything")

				# print(text)
				# print(type(text))
				# # print(match.group())

				# test shpark change hex string to hex integer
				text_spl = text.strip().split(" ")
				# Grab sensor ID
				sensorID = int(text_spl[0], 16)
				# print(text_spl[0], sensorID)

				# Call function according to the sensor ID
				if sensorID == 0x00:
					return_val = chemsense.macDecode(text)

				elif sensorID < 0x10:
					return_val = metsense.metDecode(sensorID, text)

				elif sensorID < 0x20:
					return_val = lightsense.lightDecode(sensorID, text)

				elif sensorID < 0x40:
					return_val = chemsense.chemDecode(text)

				elif sensorID == 0x40:
					return_val = alphasensor.alphaDecode(item, text_spl)
				else:
					print (text)
					break


				if isinstance(return_val, tuple):
					for val in return_val:
						print(val)
				else:
					print (return_val)


		except KeyboardInterrupt:
			break
