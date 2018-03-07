#!/usr/bin/python3

import serial
import time

s = serial.Serial('/dev/waggle_coresense', 115200)

try:
   for i in range(1000):
       print(s.readline())
       time.sleep(0.1)
except (KeyboardInterrupt, Exception) as ex:
   print(str(ex))
finally:
   s.close()
