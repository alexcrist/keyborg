#include <Audio.h>

#include "audio.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

AudioSynthWaveformSine sine1;
AudioSynthWaveformSine sine2;
AudioSynthWaveformSine sine3;
AudioSynthWaveformSine sine4;
AudioSynthWaveformSine sine5;
AudioSynthWaveformSine sine6;
AudioSynthWaveformSine sine7;
AudioSynthWaveformSine sine8;
AudioSynthWaveformSine sine9;
AudioSynthWaveformSine sine10;
AudioSynthWaveformSine sine11;
AudioSynthWaveformSine sine12;
AudioSynthWaveformSine sine13;
AudioSynthWaveformSine sine14;
AudioSynthWaveformSine sine15;
AudioSynthWaveformSine sine16;
AudioMixer4 mixer1;
AudioMixer4 mixer2;
AudioMixer4 mixer3;
AudioMixer4 mixer4;
AudioMixer4 mixer5;
AudioOutputI2S i2s1;
AudioConnection patchCord1(sine5, 0, mixer2, 0);
AudioConnection patchCord2(sine8, 0, mixer2, 3);
AudioConnection patchCord3(sine6, 0, mixer2, 1);
AudioConnection patchCord4(sine7, 0, mixer2, 2);
AudioConnection patchCord5(sine12, 0, mixer3, 3);
AudioConnection patchCord6(sine11, 0, mixer3, 2);
AudioConnection patchCord7(sine10, 0, mixer3, 1);
AudioConnection patchCord8(sine9, 0, mixer3, 0);
AudioConnection patchCord9(sine2, 0, mixer1, 1);
AudioConnection patchCord10(sine3, 0, mixer1, 2);
AudioConnection patchCord11(sine4, 0, mixer1, 3);
AudioConnection patchCord12(sine1, 0, mixer1, 0);
AudioConnection patchCord13(mixer2, 0, mixer5, 1);
AudioConnection patchCord14(mixer3, 0, mixer5, 2);
AudioConnection patchCord15(sine13, 0, mixer4, 0);
AudioConnection patchCord16(sine14, 0, mixer4, 1);
AudioConnection patchCord17(mixer1, 0, mixer5, 0);
AudioConnection patchCord18(sine15, 0, mixer4, 2);
AudioConnection patchCord19(sine16, 0, mixer4, 3);
AudioConnection patchCord20(mixer5, 0, i2s1, 0);
AudioConnection patchCord21(mixer5, 0, i2s1, 1);
AudioConnection patchCord22(mixer4, 0, mixer5, 3);
AudioControlSGTL5000 sgtl5000_1;

float amplitudeModifier = 0.25;
int numWaveforms = 16;
AudioSynthWaveformSine* waveforms[] = {
    &sine1,
    &sine2,
    &sine3,
    &sine4,
    &sine5,
    &sine6,
    &sine7,
    &sine8,
    &sine9,
    &sine10,
    &sine11,
    &sine12,
    &sine13,
    &sine14,
    &sine15,
    &sine16
};

void initAudio(int maxNumNotes) {
    AudioMemory(10);
    sgtl5000_1.enable();
    sgtl5000_1.volume(1);
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
