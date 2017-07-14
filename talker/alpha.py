
import struct

class Alphasensor:

	config_data_structs = [
		('bin boundaries', '<16H'),
		('bin particle volume', '<16f'),
		('bin particle density', '<16f'),
		('bin particle weighting', '<16f'),
		('gain scaling coefficient', '<f'),
		('sample flow rate', '<f'),
		('laser dac', '<B'),
		('fan dac', '<B'),
		('tof to sfr factor', '<B'),
	]

	def alphaDecode(self, cmd, line):
		data = [int(x, 16) for x in line]
		bytearray_data = bytearray(data)

		if cmd == 'config':
			return self.unpack_structs(self.config_data_structs, bytearray_data)
		elif cmd == 'histogram':
			return self.decode17(bytearray_data)

		elif cmd == 'serial':
			print (data)
			return
		elif cmd == 'version':
			print (data)
			return
		elif len(data) < 3:
			return
		elif data[0] == 0xf3 and data[1] == 0x03:
			return "power on/off"
		else:
			print(data)
			return

	def unpack_structs(self, structs, data):
		results = {}

		offset = 0

		for key, fmt in structs:
			values = struct.unpack_from(fmt, data, offset)
			
			if len(values) == 1:
				results[key] = values[0]
			else:
				results[key] = values
			offset += struct.calcsize(fmt)

		return results


	def decode17(self, data):
		bincounts = struct.unpack_from('<16H', data, offset=0)
		mtof = [x / 3 for x in struct.unpack_from('<4B', data, offset=32)]
		sample_flow_rate = struct.unpack_from('<f', data, offset=36)[0]
		pressure = struct.unpack_from('<I', data, offset=40)[0]
		temperature = pressure / 10.0
		sampling_period = struct.unpack_from('<f', data, offset=44)[0]
		checksum = struct.unpack_from('<H', data, offset=48)[0]
		pmvalues = struct.unpack_from('<3f', data, offset=50)

		assert pmvalues[0] <= pmvalues[1] <= pmvalues[2]

		values = {
			'bins': bincounts,
			'mtof': mtof,
			'sample flow rate': sample_flow_rate,
			'sampling period': sampling_period,
			'pm1': pmvalues[0],
			'pm2.5': pmvalues[1],
			'pm10': pmvalues[2],
			'error': sum(bincounts) & 0xFFFF != checksum,
		}

		if temperature > 200:
			values['pressure'] = pressure
		else:
			values['temperature'] = temperature

		return values
