# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
import sys

v3 = 3.27 #3.27
v5 = 4.38 #4.38

r1=15000.0
r2=45300.0

v_counts = int(sys.argv[1])
T = float(sys.argv[2])

vx=0.16
v_sense  = v_counts * v3 / 4096
v_hih4030 = v_sense * (r1+r2) / r2

srh=((v_hih4030/v5)-vx)/0.0062
trh=srh/(1.0546 - 0.00216 * T)

print trh
