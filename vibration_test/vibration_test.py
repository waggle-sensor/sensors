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
    # sync to incoming frames
    get_frame(ser)

    total = 0
    start = time.time()

    print('# start', start, flush=True)

    # sample 15min of data
    while time.time() - start < args.seconds:
        data = get_frame(ser)
        total += 1
        rate = total / (time.time() - start)

        # show status every 10000 frames
        if total % 10000 == 0:
            print('# time', time.time() - start, flush=True)
            print('# rate', rate, flush=True)

        if total > 100 and abs(rate - 800) > 50:
            print('# error rate', rate, flush=True)
            sys.exit(1)

        print(data.hex())
