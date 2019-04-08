# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
import time
import threading
import commands
from coresense_InotifyKernel import *

if __name__ == "__main__":
    commL = communicatorLoader()
    Monitor('/dev')
    print "--------------------------------------"
    commL.stop()
    while len(threading.enumerate()) > 1:
        print threading.enumerate()
        time.sleep(1)
        print "shutting down..."
    commands.getoutput("rm *.pyc")
