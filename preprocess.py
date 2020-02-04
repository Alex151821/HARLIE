from scipy.io import wavfile
from scipy.fftpack import fft
from matplotlib import pyplot as plt
print(wavfile.read("New Recording 6 trimmed.wav"))
sf, data = wavfile.read("New Recording 6 trimmed.wav")

a = data.T[:319]
b = [(n/2**16.) * 2-1 for n in data]
print(b[:20])

c = fft(b)
d = len(c)/2
#print(c[:100])
plt.specgram(b, Fs=sf, NFFT = 320)
plt.show()
