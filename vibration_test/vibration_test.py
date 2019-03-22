# for mma8452q
import sys
from serial import Serial
from io import BytesIO
import time


MSG_FRAME = 0x7e
MSG_ESC = 0x7d


def decode_frame(reader, writer):
    while True:
        b = reader.read(1)
        if len(b) == 0:
            break
        if b[0] == MSG_FRAME:
            break
        if b[0] == MSG_ESC:
            b = reader.read(1)
            writer.write(bytes([b[0] ^ 0x20]))
        else:
            writer.write(bytes([b[0]]))


def get_frame_data(reader):
    writer = BytesIO()
    decode_frame(reader, writer)
    return writer.getvalue()


with Serial(sys.argv[1], baudrate=115200, timeout=180) as ser:
    # sync to incoming frames
    get_frame_data(ser)

    total = 0
    start = time.time()

    while True:
        data = get_frame_data(ser)
        total += 1
        rate = total / (time.time() - start)
        print(data.hex(), round(rate))
