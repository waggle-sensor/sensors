# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
import pr103j2_calib
import numpy as np
import sys
pr103j2_TC = np.array(pr103j2_calib.pr103j2_TC)
pr103j2_R = np.array(pr103j2_calib.pr103j2_R)
print pr103j2_TC.flat[np.abs(pr103j2_R - (float(sys.argv[1])*1000)).argmin()]
