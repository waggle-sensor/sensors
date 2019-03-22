# for mma8452q
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


with Serial(sys.argv[1], baudrate=115200, timeout=180) as ser:
    # sync to incoming frames
    get_frame(ser)

    total = 0
    start = time.time()

    print('# start', start)

    while True:
        data = get_frame(ser)
        total += 1
        rate = total / (time.time() - start)

        if total > 100 and abs(rate - 800) > 20:
            print('# error rate drift')
            sys.exit(1)

        print(data.hex())
