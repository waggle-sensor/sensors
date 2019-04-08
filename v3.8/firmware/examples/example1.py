# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
from serial import Serial
import sys


def sendcommand(s, cmd):
    s.write(cmd)
    s.write(b'\r')

    lines = []

    while True:
        line = s.readline()

        if line.startswith(b'ok:'):
            break

        if line.startswith(b'error:'):
            raise RuntimeError(line.split(b':')[1].strip())

        lines.append(line)

    return lines


with Serial(sys.argv[1], timeout=10) as s:
    print(sendcommand(s, b'ver'))
    print(sendcommand(s, b'id'))
