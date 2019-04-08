# ANL:waggle-license
# This file is part of the Waggle Platform.  Please see the file
# LICENSE.waggle.txt for the legal details of the copyright and software
# license.  For more details on the Waggle project, visit:
#          http://www.wa8.gl
# ANL:waggle-license
import subprocess

def collect_data():
	node_list = "./live_nodes.txt"
	with open(node_list) as lst:
		for row in lst:
			subprocess.call(['./getdatasets', row, str(0), str(1)])
			result = check()
			print(result)


def check():
	try:
		theCheck = False
		datafile = "./sensor_data_set.csv"
		with open(datafile) as df:
			for line in df:
				name_check = line.strip().split(';')[-3]
				if "SPV1840" in name_check:
					theCheck = True
		return theCheck
	except:
		pass

if __name__ == '__main__':
	collect_data()
