# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
Zc = [0] * 7
nA = [0] * 7
nAZ = [0] * 7
zcfL = [0] * 7
zcfH = [2.375,0,0,0,0,0,0]
scfL = [0.6,0,0,0,0,0,0]
scfH = [0.4,0,0,0,0,0,0]
Sc = [0] * 7
Tz = [0] * 7
nA = 0
T = 0

Sensors = ["CMO", "SO2", "NO2", "OZO", "H2S", "IRR", "IAQ", "SHT", "HDT"]


Zc[i] = nA[i] - nAz[i] - zcf * (T - Tz[i])


Sc[i] = 1 - (scf / 100) * (T - Tz[i])


Cx = Zc * Sc * 1/Sf




where:
nA is the output of the gas sensors on the PBay board 
T is the output of the temperature sensor on the PBay board

zcf is the zero temperature factor
scf is the span temperature factor

Tz is temperature at time of "re-zero"
nAz is PBay gas sensor output at the time of "re-zero"
