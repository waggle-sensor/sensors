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

output_file  = open("full_temp.file", "w")
input_file  = open("temp_file.file", "r")

for line in input_file:
    
    line_vals = line.split(' ')
    new_line = line
    
    if line_vals[1] == "M_PR103J2_Temp:":
    
        T = float(line_vals[2])
        
    elif line_vals[1] == "M_HIH4030:":
        v_counts = float(line_vals[2])
        vx=0.16
        v_sense  = v_counts * v3 / 4096
        v_hih4030 = v_sense * (r1+r2) / r2

        srh=((v_hih4030/v5)-vx)/0.0062
        trh=srh/(1.0546 - 0.00216 * T)
        new_line = str(line_vals[0]) +' '+ str(line_vals[1]) + ' '+str(round(trh,2))+ '\r\n'
    
    output_file.write(new_line)

    
input_file.close()
output_file.close()


