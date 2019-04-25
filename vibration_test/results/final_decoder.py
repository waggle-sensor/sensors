import sys
import numpy as np

if len(sys.argv) < 2:
    sys.argv.append('09C-vib-data.txt')

a = []
b = []

ax = []
ay = []
az = []

vib = []

with open(sys.argv[1], 'r') as f:
    for line in f:
        if '#' in line:
            continue

        a.append(line.split()[0].strip())  ## save time stamp
        temp = line.split()[-1].strip()  ## raw data
        b.append(temp)  ## save the raw data
        data = int(temp, 16)  ## convert raw str to int16

        separated = [temp[:4], temp[4:8], temp[8:12]]  ## separate raw data into three parts in which Ax, Ay, Az
        splitted = [data & 0xFFFF, (data>> 16) & 0xFFFF, (data >> 32) & 0xFFFF]  ## split in16 data into three parts in which Ax, Ay, Az
        raw = [0,0,0]  ## init array

        for i in range(len(splitted)):  ## for length of splitted array
            gcount = splitted[i] >> 4  ## calculate gcount
            if (splitted[i] >> 8) > 0x7F:  ## if each raw value of Ax and Ay and Az are greater then 0x7F
                # print('(splitted[i] >> 8) > 0x7F')
                gcount -= 0x1000  ## subtract 1000 from gcount
            raw[i] = gcount / ((1 << 12) / 4)  ## calculate Ax, Ay, Az with the calculated gcount and the raw value
            raw[i] = round(raw[i]*1000, 3)  ## translate the calculated value to mg (milli gravity) and print three decimal points

            if i == 0:
                ax.append(raw[i])
            elif i == 1:
                ay.append(raw[i])
            else:
                az.append(raw[i])

        ### calculate magnitude of vibration
        A = np.sqrt(raw[0]**2+raw[1]**2+raw[2]**2)  ## calculate total accelerorated value
        vib.append(A)


import matplotlib
import matplotlib.pyplot as plt

# Data for plotting
t = np.array([x for x in range(len(vib))])

# Create figure
fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2)

s = np.array(vib)
ax1.plot(t, s)
ax1.set(xlabel='time (1/800 s)', ylabel='gravity (mg)',
        title='Euclidean norm of accelerometer data')
ax1.grid()

s = np.array(ax)
ax2.plot(t, s)
ax2.set(xlabel='time (1/800 s)', ylabel='gravity (mg)',
        title='ax')
ax2.grid()

s = np.array(ay)
ax3.plot(t, s)
ax3.set(xlabel='time (1/800 s)', ylabel='gravity (mg)',
        title='ay')
ax3.grid()

s = np.array(az)
ax4.plot(t, s)
ax4.set(xlabel='time (1/800 s)', ylabel='gravity (mg)',
        title='az')
ax4.grid()

fig.tight_layout()
plt.show()


from scipy.fftpack import fft

# Sampling rate and time vector
start_time = 0 # seconds
end_time = 1775 # seconds
sampling_rate = 800 # Hz
N = (end_time - start_time)*sampling_rate # array size

# Nyquist Sampling Criteria
T = 1/sampling_rate # inverse of the sampling rate
x = np.linspace(0.0, 1.0/(2.0*T), int(N/2))

# FFT algorithm
yr_vib = fft(np.array(vib)) # "raw" FFT with both + and - frequencies
y_vib = 2/N * np.abs(yr_vib[0:np.int(N/2)]) # positive freqs only

yr_ax = fft(np.array(ax)) # "raw" FFT with both + and - frequencies
y_ax = 2/N * np.abs(yr_ax[0:np.int(N/2)]) # positive freqs only

yr_ay = fft(np.array(ay)) # "raw" FFT with both + and - frequencies
y_ay = 2/N * np.abs(yr_ay[0:np.int(N/2)]) # positive freqs only

yr_az = fft(np.array(az)) # "raw" FFT with both + and - frequencies
y_az = 2/N * np.abs(yr_az[0:np.int(N/2)]) # positive freqs only

# Create figure
fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2)

ax1.plot(x[1:], y_vib[1:])
ax1.set(xlabel='frequency (Hz)', ylabel='magnitude (mg)',
        title='Euclidean norm of accelerometer data')
ax1.grid()

ax2.plot(x[1:], y_ax[1:])
ax2.set(xlabel='frequency (Hz)', ylabel='magnitude (mg)',
        title='ax')
ax2.grid()

ax3.plot(x[1:], y_ay[1:])
ax3.set(xlabel='frequency (Hz)', ylabel='magnitude (mg)',
        title='ay')
ax3.grid()

ax4.plot(x[1:], y_az[1:])
ax4.set(xlabel='frequency (Hz)', ylabel='magnitude (mg)',
        title='az')
ax4.grid()

fig.tight_layout()
plt.show()
