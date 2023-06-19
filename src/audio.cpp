#include <Audio.h>
#include <string.h>

#include "audio.h"

AudioSynthWaveform waveform1;
AudioSynthWaveform waveform2;
AudioSynthWaveform waveform3;
AudioSynthWaveform waveform4;
AudioSynthWaveform waveform5;
AudioSynthWaveform waveform6;
AudioSynthWaveform waveform7;
AudioSynthWaveform waveform8;
AudioSynthWaveform waveform9;
AudioSynthWaveform waveform10;
AudioSynthWaveform waveform11;
AudioSynthWaveform waveform12;
AudioSynthWaveform waveform13;
AudioSynthWaveform waveform14;
AudioSynthWaveform waveform15;
AudioSynthWaveform waveform16;
AudioMixer4 mixer1;
AudioMixer4 mixer2;
AudioMixer4 mixer3;
AudioMixer4 mixer4;
AudioMixer4 mixer5;
AudioOutputI2S i2s1;
AudioConnection patchCord1(waveform5, 0, mixer2, 0);
AudioConnection patchCord2(waveform8, 0, mixer2, 3);
AudioConnection patchCord3(waveform6, 0, mixer2, 1);
AudioConnection patchCord4(waveform7, 0, mixer2, 2);
AudioConnection patchCord5(waveform12, 0, mixer3, 3);
AudioConnection patchCord6(waveform11, 0, mixer3, 2);
AudioConnection patchCord7(waveform10, 0, mixer3, 1);
AudioConnection patchCord8(waveform9, 0, mixer3, 0);
AudioConnection patchCord9(waveform2, 0, mixer1, 1);
AudioConnection patchCord10(waveform3, 0, mixer1, 2);
AudioConnection patchCord11(waveform4, 0, mixer1, 3);
AudioConnection patchCord12(waveform1, 0, mixer1, 0);
AudioConnection patchCord13(mixer2, 0, mixer5, 1);
AudioConnection patchCord14(mixer3, 0, mixer5, 2);
AudioConnection patchCord15(waveform13, 0, mixer4, 0);
AudioConnection patchCord16(waveform14, 0, mixer4, 1);
AudioConnection patchCord17(mixer1, 0, mixer5, 0);
AudioConnection patchCord18(waveform15, 0, mixer4, 2);
AudioConnection patchCord19(waveform16, 0, mixer4, 3);
AudioConnection patchCord20(mixer5, 0, i2s1, 0);
AudioConnection patchCord21(mixer5, 0, i2s1, 1);
AudioConnection patchCord22(mixer4, 0, mixer5, 3);
AudioControlSGTL5000 sgtl5000_1;

static float amplitudeModifier = 0.5;
static const int numWaveforms = 16;
static AudioSynthWaveform* waveforms[] = {
    &waveform1,
    &waveform2,
    &waveform3,
    &waveform4,
    &waveform5,
    &waveform6,
    &waveform7,
    &waveform8,
    &waveform9,
    &waveform10,
    &waveform11,
    &waveform12,
    &waveform13,
    &waveform14,
    &waveform15,
    &waveform16
};

void initAudio(int maxNumNotes) {
    AudioMemory(32);
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);
}

void updateWaveforms(float amplitude, float* freqs, int numFreqs) {
    for (int i = 0; i < numWaveforms; i++) {
        if (i < numFreqs && freqs[i] != -1) {
            waveforms[i]->frequency(freqs[i]);
            waveforms[i]->amplitude(amplitude * amplitudeModifier);
        } else {
            waveforms[i]->amplitude(0);
        }
    }
}

void setWaveformType(int waveformType) {
    for (int i = 0; i < numWaveforms; i++) {
        waveforms[i]->begin(waveformType);
    }
}

void setVolume(float volume) {
    amplitudeModifier = volume;
    sgtl5000_1.volume(volume);
}