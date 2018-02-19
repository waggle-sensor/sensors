# Conversion for chemsense
# chemsense version2, no data of IMU is comming from chemsense --> chemsense FW issue

import math

def import_data(xl_data):
    inputcsv = './calib_data.csv'
    with open(inputcsv) as cal:
        for row in cal:
            rowValues = row.strip().split(';')
            chem_id = row[1]

            xl_data[chem_id] = {
                'Ireducing_gases':{'sensitivity': rowValues[-42], 'baseline40': rowValues[-21], 'Mvalue': rowValues[-7]},   # IRR = RESP, baseline = Izero@40C
                'oxidizing_gases': {'sensitivity': rowValues[-41], 'baseline40': rowValues[-20], 'Mvalue': rowValues[-6]},
                'so2': {'sensitivity': rowValues[-40], 'baseline40': rowValues[-19], 'Mvalue': rowValues[-5]},
                'h2s': {'sensitivity': rowValues[-39], 'baseline40': rowValues[-18], 'Mvalue': rowValues[-4]},
                'o3': {'sensitivity': rowValues[-38], 'baseline40': rowValues[-17], 'Mvalue': rowValues[-3]},
                'no2': {'sensitivity': rowValues[-37], 'baseline40': rowValues[-16], 'Mvalue': rowValues[-2]},
                'co': {'sensitivity': rowValues[-36], 'baseline40': rowValues[-15], 'Mvalue': rowValues[-1]}
            }

    return xl_data


def chemical_sensor(value, xl_data):
    for key, in_list in value.items():
        if key != 'id' and key != 'temp':
            IpA = value[key][0]

            Tzero = 40.0

            if value['id'] in xl_data:
                Tavg = value['temp']
                sensitivity = xl_data[value['id']][key]['sensitivity']
                baseline = xl_data[value['id']][key]['baseline40']
                Minv = xl_data[value['id']][key]['Mvalue']

                InA = float(IpA)/1000.0 - baseline*math.exp((Tavg - Tzero) / Minv)
                converted = InA / sensitivity
                value[key][0] = converted
            else:
                value[key][0] = IpA / 1000

    return value


def convert(value, xl_data):
    if value['temp'] == 123456789:
        return 0
    else:
        base_temperature = round((value['temp'] / 5), 2)
        chemical_sensor(value, xl_data)

    return value
