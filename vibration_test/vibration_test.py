# for mma8452q
import sys
import argparse
from serial import Serial, SerialException

import time


def read(file):
    if serial.inWaiting() > 0:
        reading = serial.read(serial.inWaiting())
        file.write(reading)
        # print(reading)
        # print(serial.read(serial.inWaiting()))
    else:
        time.sleep(0.05)


if __name__ == '__main__':
    # with Serial('/dev/ttyACM0', baudrate=115200, timeout=180) as serial:
    with Serial('/dev/waggle_coresense', baudrate=115200, timeout=180) as serial:
        timestr = time.strftime("%Y%m%d-%H%M%S")
        with open(timestr + '_vib_data.txt', 'wb') as file:
            end_byte = bytearray()
            end_byte.append(0x55)
            end_byte.append(0x55)
            try:
                st = time.time()
                while True:
                    read(file)
                    et = time.time()
                    if (et - st) >= 1:
                        file.write(end_byte)
                        st = time.time()
                        # beark
            except:
                pass
