# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
from read_data import read_data
from chemsense import import_data
import os


if __name__ == '__main__':
    data_directory = os.path.dirname(os.path.realpath(__file__))

    xl_data = {}
    xl_data = import_data(xl_data, base_dir=data_directory)

    read_data(xl_data)
