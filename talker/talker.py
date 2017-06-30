#!/usr/bin/env python3
from serial import Serial
import sys
import re

from met import *
from light import *
from chem import *
from cmd import *

metsense = Metsense()
lightsense = Lightsense()
chemsense = Chemsense()
commands = Commands()


# linehex = 64
# val = []
# for i in range(linehex):
#     val.append(0x00)

with Serial(sys.argv[1], baudrate=9600, timeout=5) as ser:
    while True:
        try:
            cmd = input('$ ')
            # cmd = '2request met light chem chem chem mac'

            comm = commands.GetCmd(cmd)
            print(comm)
            # dol = ' '.join(comm).encode()
            # print(dol)

            ser.write(cmd.encode())
            ser.write(b'\n')

            while True:
                line = ser.readline().decode()

                if len(line) == 0:
                    print('timeout')
                    break

                match = re.match('(ok:|err:|data) (.*)', line)

                if match is None:
                    continue

                status, text = match.groups()

                # print(status)
                if status == 'ok:' or status == 'err:':
                    # print("hello hell")
                    print (text)
                    break
                # else:
                #     print ("Please print anything")

                print(text)
                # print(type(text))
                # # print(match.group())

                # # test shpark change hex string to hex integer
                # text_spl = text.strip().split(" ")
                # # Grab sensor ID
                # sensorID = int(text_spl[0])

                # # Call function according to the sensor ID
                # if sensorID == 0x00:
                #     return_val = chemsense.macDecode(text)
                # elif sensorID < 0x10:
                #     return_val = metsense.metDecode(sensorID, text)
                # elif sensorID < 0x20:
                #     return_val = lightsense.lightDecode(sensorID, text)
                # elif sensorID < 0x40:
                #     return_val = chemsense.ChemDecode(text)
                # else:
                #     continue


                # if isinstance(return_val, tuple):
                #     for val in return_val:
                #         print(val)
                # else:
                #     print (return_val)


        except KeyboardInterrupt:
            break
