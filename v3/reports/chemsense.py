# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
# Conversion for chemsense
# chemsense version2, no data of IMU is comming from chemsense --> chemsense FW issue

import math
import os

def import_data(xl_data, base_dir='./'):
    inputcsv = os.path.join(base_dir, 'calib_data.csv')
    with open(inputcsv) as cal:
        for row in cal:
            rowValues = row.strip().split(';')
            chem_id = rowValues[1]

            xl_data[chem_id] = {
                'reducing_gases':{'sensitivity': rowValues[-42], 'baseline40': rowValues[-21], 'Mvalue': rowValues[-7]},   # IRR = RESP, baseline = Izero@40C
                'oxidizing_gases': {'sensitivity': rowValues[-41], 'baseline40': rowValues[-20], 'Mvalue': rowValues[-6]},
                'so2': {'sensitivity': rowValues[-40], 'baseline40': rowValues[-19], 'Mvalue': rowValues[-5]},
                'h2s': {'sensitivity': rowValues[-39], 'baseline40': rowValues[-18], 'Mvalue': rowValues[-4]},
                'o3': {'sensitivity': rowValues[-38], 'baseline40': rowValues[-17], 'Mvalue': rowValues[-3]},
                'no2': {'sensitivity': rowValues[-37], 'baseline40': rowValues[-16], 'Mvalue': rowValues[-2]},
                'co': {'sensitivity': rowValues[-36], 'baseline40': rowValues[-15], 'Mvalue': rowValues[-1]}
            }

    return xl_data

def new_line_a(sep, key):
    new_line = ''
    for i in range(len(sep)):
        if i == 5:
            new_line = new_line + key + ';'
        elif i == len(sep) - 1:
            new_line = new_line + sep[i]
        else:
            new_line = new_line + sep[i] + ';'
    return new_line

def chemical_sensor(value, xl_data):
    for key, in_list in value.items():
        if key != 'id' and key != 'temp':
            if value['id'] in xl_data:
                new_key = key + '_pp'
                sep = value[key][1].strip().split(';')

                line = new_line_a(sep, new_key)
                value[key][1] = line

                Tzero = 40.0
                Tavg = value['temp']/4
                IpA = float(value[key][0])
                sensitivity = float(xl_data[value['id']][key]['sensitivity'])
                baseline = float(xl_data[value['id']][key]['baseline40'])
                Minv = float(xl_data[value['id']][key]['Mvalue'])

                Afactor = round(math.exp((Tavg - Tzero)/Minv), 2)
                InA = IpA/1000.0 - baseline*Afactor
                converted = InA / sensitivity
                value[key][0] = converted
            else:
                new_key = key + '_not_in_spec_dataset'
                sep = value[key][1].strip().split(';')

                line = new_line_a(sep, new_key)
                value[key][1] = line

    return value


def convert(value, xl_data):
    if value['temp'] == 123456789:
        return 0
    else:
        base_temperature = round((value['temp'] / 5), 2)
        value = chemical_sensor(value, xl_data)

    return value
