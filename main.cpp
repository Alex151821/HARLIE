#include <iostream>
#include "AudioFile/AudioFile.h" 
#include <vector>
using namespace std;
int main(){
    AudioFile<double> boom;
    boom.load("Boomdeyada.wav");
    cout << "Sample rate: " << boom.getSampleRate();
    int numSamples = boom.getNumSamplesPerChannel();
    int channel = 0;
    vector<double> samples;
    for (int i = 0; i < numSamples; i++){
      cout << boom.samples[channel][i] << ", ";
    }
    cout << "\n";
    return 0;
}