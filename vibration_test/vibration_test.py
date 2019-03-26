# for mma8452q
import argparse
import sys
import time
from serial import Serial


MSG_FRAME = 0x7e
MSG_ESC = 0x7d


def get_frame(reader):
    data = []

    while True:
        b = reader.read(1)
        if len(b) == 0:
            break
        if b[0] == MSG_FRAME:
            break
        if b[0] == MSG_ESC:
            b = reader.read(1)
            data.append(b[0] ^ 0x20)
        else:
            data.append(b[0])
    
    return bytes(data)


parser = argparse.ArgumentParser()
parser.add_argument('device')
parser.add_argument('seconds', type=float)
args = parser.parse_args()

with Serial(args.device, baudrate=115200, timeout=180) as ser:
    # sync to serial stream
    get_frame(ser)

    start = time.time()
    total = 0
    sample_time_total = 0
    print('# start', start, flush=True)

    while time.time() - start < args.seconds:
        start_sample = time.time()
        data = get_frame(ser)
        sample_time_total += time.time() - start_sample
        total += 1
        rate = total / sample_time_total

        # show status every 10000 frames
        if total % 10000 == 0:
            print('# total', total)
            print('# time', time.time() - start)
            print('# rate', rate, flush=True)

        print(time.time(), data.hex())
