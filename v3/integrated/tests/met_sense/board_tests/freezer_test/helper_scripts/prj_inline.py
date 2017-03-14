import pr103j2_calib
import numpy as np
import sys

pr103j2_TC = np.array(pr103j2_calib.pr103j2_TC)
pr103j2_R = np.array(pr103j2_calib.pr103j2_R)

input_file  = open(sys.argv[1], "r")
output_file  = open("temp_file.file", "w")

for line in input_file:
    line_vals = line.split(' ')
    new_line = line
    if line_vals[1] == "M_PR103J2_Temp:":
        new_line = str(line_vals[0]) +' '+ str(line_vals[1]) + ' '+str(pr103j2_TC.flat[np.abs(pr103j2_R-(float(line_vals[2])*1000)).argmin()]) + '\r\n'
    output_file.write(new_line)
    
input_file.close()
output_file.close()
        