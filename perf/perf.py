import argparse
import time
from serial import Serial

parser = argparse.ArgumentParser()
parser.add_argument('device')
args = parser.parse_args()


with Serial(args.device, baudrate=115200, timeout=180) as ser:
    ser.flushInput()

    sample_time_total = 0.0
    total = 0
    log_time = time.perf_counter()

    while True:
        sample_time = time.perf_counter()
        ser.read(1)
        sample_time_total += time.perf_counter() - sample_time
        total += 1

        if sample_time - log_time > 5:
            log_time = sample_time
            rate = total / sample_time_total
            print(rate)
