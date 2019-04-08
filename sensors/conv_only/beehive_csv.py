# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
from read_data import read_data
from chemsense import import_data


if __name__ == '__main__':
	xl_data = {}
	xl_data = import_data(xl_data)

	read_data(xl_data)
