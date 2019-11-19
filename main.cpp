#include <iostream>
#include "AudioFile/AudioFile.h" 
using namespace std;
int main(){
  AudioFile<double> boom;
  boom.load("Boomdeyada.wav");
  cout << "Sample rate: " << boom.getSampleRate();
  int numSamples = boom.getNumSamplesPerChannel();
  int channel = 0;

  for (int i = 0; i < numSamples; i++){
      cout << boom.samples[channel][i];
  }
  return 0;
}