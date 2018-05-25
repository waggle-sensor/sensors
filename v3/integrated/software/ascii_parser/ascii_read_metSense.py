#!/usr/bin/python2.7
import serial, time, sys
import pr103j2_calib
import numpy as np
import sys

adc_bits = 15 # full range is 16 bits, but only 15 for +ve side... 
adc_fs = 2.04
adc_volts_per_div = adc_fs / pow(2, adc_bits)

ambinet_T = 25.00

R1 = 12000
R2 = 18000
APD_Req = 5130
APD_scale_fac = 1.06

SAM3x_ADC_RES = 12
SAM3X_ADC_Counts = pow(2,12)


v3 = 3.27 #3.27
v5 = 4.38 #4.38

hih4030_r1=15000.0
hih4030_r2=45300.0
hih4030_vx=0.16

pr103j2_TC = np.array(pr103j2_calib.pr103j2_TC)
pr103j2_R = np.array(pr103j2_calib.pr103j2_R)

mcp_ad_sensors=['L_APDS9006020:','L_TSL261RD:','L_TSL251RD:','L_MLX75305:','L_ML8511:']
mcp_ad_sensors_subtract_this= [0,0.0045,0.0044,0.055,0.85]
mcp_ad_sensors_unit=["Lux","uW/cm2", "uW/cm2", "uW/cm2", "mW/cm2"]
mcp_ad_sensors_multiply_by=[pow(10,6)/(APD_Req*APD_scale_fac*0.4),67.5676,67.5676,(1/0.007),(15/1.75)]

sam3_ad_sensors=["M_TSL251:","M_PR103J2_Temp:","M_HIH4030:"]
sam3_ad_sensors_subtract_this=[0.0007,0,hih4030_vx]
sam3_ad_sensors_unit=["uW/cm2","C","%RH"]
sam3_ad_sensors_multiply_by=[67.5676,1,1/0.0062]
sam3_ad_sensors_value = [(v3/pow(2,SAM3x_ADC_RES)),1,( v3 * (hih4030_r1+ hih4030_r2) ) / (v5 * 4096 * hih4030_r2)]

ser = serial.Serial('/dev/ttyACM'+sys.argv[1], 115600)
ser.flushInput()
ser.flushOutput()

while 1:

    serial_line = ser.readline()
    sensor_tuple = serial_line.split(" ")
    
    if sensor_tuple[0] in mcp_ad_sensors:
        value = int(sensor_tuple[1].split('\r')[0])
        voltage_adc = value * adc_volts_per_div
        voltage_actual = (voltage_adc * (R1 + R2)) / R2
        sensor_value = voltage_actual-mcp_ad_sensors_subtract_this[mcp_ad_sensors.index(sensor_tuple[0])]
        sensor_value = sensor_value * mcp_ad_sensors_multiply_by[mcp_ad_sensors.index(sensor_tuple[0])]
        print int(time.time()), sensor_tuple[0], sensor_value, mcp_ad_sensors_unit[mcp_ad_sensors.index(sensor_tuple[0])]
    
    elif sensor_tuple[0] in sam3_ad_sensors:
        value = int(sensor_tuple[1].split('\r')[0])
        
        if sensor_tuple[0] == "M_PR103J2_Temp:":
            voltage_actual = (float(value)/ SAM3X_ADC_Counts) * v3
            prj_resistance = ( 47.0 * ( SAM3X_ADC_Counts - value) ) / value
            sensor_value = pr103j2_TC.flat[np.abs(pr103j2_R - (float(prj_resistance)*1000)).argmin()]
            ambinet_T = sensor_value
        else:
            voltage_actual = value * sam3_ad_sensors_value[sam3_ad_sensors.index(sensor_tuple[0])]
            sensor_value = voltage_actual-sam3_ad_sensors_subtract_this[sam3_ad_sensors.index(sensor_tuple[0])]
            sensor_value = sensor_value * sam3_ad_sensors_multiply_by[sam3_ad_sensors.index(sensor_tuple[0])]
            if sensor_tuple[0] == "M_HIH4030:":
                sensor_value=sensor_value/(1.0546 - 0.00216 * ambinet_T)
                
        sensor_value = round(sensor_value,3)
        print int(time.time()), sensor_tuple[0], sensor_value, sam3_ad_sensors_unit[sam3_ad_sensors.index(sensor_tuple[0])]

    
    else:
        print int(time.time()), serial_line,
    time.sleep(0.001)

ser.close() # Only executes once the loop exits
            



