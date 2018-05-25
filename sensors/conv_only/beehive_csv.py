

from read_data import read_data
from chemsense import import_data


if __name__ == '__main__':
	xl_data = {}
	xl_data = import_data(xl_data)

	read_data(xl_data)