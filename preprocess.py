from scipy.io import wavfile
from scipy.fftpack import fft
from matplotlib import pyplot as plt
print(wavfile.read("Boomdeyada.wav"))
sf, data = wavfile.read("Boomdeyada.wav")
a = data[:319].T[0]
b = [(n/2**16.) * 2-1 for n in a]
print(b[:500])
c = fft(b)
d = len(c)/2
#print(c[:100])

