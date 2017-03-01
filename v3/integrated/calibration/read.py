import serial, time, sys

ser = serial.Serial('/dev/ttyACM'+sys.argv[1], 115600)
ser.flushInput()
ser.flushOutput()
while 1:

    serial_line = ser.readline()
    print int(time.time()), serial_line,
    time.sleep(0.001)

ser.close() # Only executes once the loop exits
            
