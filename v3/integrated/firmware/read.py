# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
import serial, time, sys

ser = serial.Serial('/dev/ttyACM'+sys.argv[1], 115600)
ser.flushInput()
ser.flushOutput()
while 1:

    serial_line = ser.readline()
    print int(time.time()), serial_line,
    time.sleep(0.01)

ser.close() # Only executes once the loop exits
            
