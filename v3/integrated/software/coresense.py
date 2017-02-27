#!/usr/bin/python
import time
import threading
import commands
from coresense_InotifyKernel import *

if __name__ == "__main__":
    which_dev = sys.argv[1]
    commL = communicatorLoader()
    Monitor('/tmp',which_dev) #Monitor('/dev')
    print "--------------------------------------"
    commL.stop()
    while len(threading.enumerate()) > 1:
        print threading.enumerate()
        time.sleep(1)
        print "shutting down..."
    commands.getoutput("rm *.pyc")
