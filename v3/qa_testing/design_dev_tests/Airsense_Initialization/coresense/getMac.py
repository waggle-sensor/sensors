# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
import serial
import time
import commands
port = serial.Serial('/dev/waggle_coresense', 115200)
while (1):
    line = port.readline()
    if (line.startswith("4. Unique Board ID -")):
        print line.split("-")[1].strip()
        break;

