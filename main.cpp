#include <iostream>
#include "AudioFile/AudioFile.h" 
#include "apfloat/apfloat.h"
#include <vector>
using namespace std;
int main(){
    AudioFile<double> boom;
    boom.load("Boomdeyada.wav");
    cout << "Sample rate: " << boom.getSampleRate() << "\n";
    int numSamples = boom.getNumSamplesPerChannel();
    int channel = 0;
    cout << numSamples << "\n";
    vector<double> samples;
    double SampArr[320];
    for (int i = 0; i < 320; i++){
        SampArr[i] = boom.samples[channel][i];
    }
    for(double r: SampArr){
        cout << r << ", ";
    }
    cout << "\n";
    return 0;
}