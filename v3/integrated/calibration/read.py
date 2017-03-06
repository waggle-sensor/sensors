#!/usr/bin/python2.7
import serial, time, sys
mcp_ad_sensors=['APDS9006020:','TSL260RD:','TSL250RD:','MLX75305:','ML8511:']

mcp_ad_sensors_subtract_this= [0,0.0045,0.0044,0.055,0.99]
mcp_ad_sensors_unit=["Lux","uW/cm2", "uW/cm2", "uW/cm2", "mW/cm2"]
R1 = 12000
R2 = 18000
APD_Req = 5130
APD_scale_fac = 1.06
mcp_ad_sensors_multiply_by=[pow(10,6)/(APD_Req*APD_scale_fac*0.4),67.5676,67.5676,(1/0.007),(15/1.75)]

adc_bits = 15 # full range is 16 bits, but only 15 for +ve side... 
adc_fs = 2.04
adc_volts_per_div = adc_fs / pow(2, adc_bits)

ser = serial.Serial('/dev/waggle_coresense', 115600)
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
        print int(time.time()), sensor_tuple[0], voltage_actual, sensor_value, mcp_ad_sensors_unit[mcp_ad_sensors.index(sensor_tuple[0])]
        
    else:
        print ''
    time.sleep(0.001)

ser.close() # Only executes once the loop exits
            



