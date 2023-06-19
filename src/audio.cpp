#include <Audio.h>
#include <string.h>

#include "audio.h"

AudioSynthWavetable      wavetable1;
AudioSynthWavetable      wavetable2;
AudioSynthWavetable      wavetable3;
AudioSynthWavetable      wavetable4;
AudioMixer4              mixer1;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(wavetable1, 0, mixer1, 0);
AudioConnection          patchCord4(wavetable2, 0, mixer1, 1);
AudioConnection          patchCord2(wavetable3, 0, mixer1, 2);
AudioConnection          patchCord3(wavetable4, 0, mixer1, 3);
AudioConnection          patchCord5(mixer1, 0, i2s1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;

static float amplitudeModifier = 0.5;
static const int numWavetables = 4;
static AudioSynthWavetable* wavetables[] = {
    &wavetable1,
    &wavetable2,
    &wavetable3,
    &wavetable4
};

void initAudio(int maxNumNotes) {
    AudioMemory(32);
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);
    mixer1.gain(0, 0.5);
}

void updateWavetables(float amplitude, float* freqs, int numFreqs) {
    for (int i = 0; i < numWavetables; i++) {
        if (i < numFreqs && freqs[i] != -1) {
            wavetables[i]->setFrequency(freqs[i]);
            wavetables[i]->amplitude(amplitude * amplitudeModifier);
        } else {
            wavetables[i]->amplitude(0);
        }
    }
}

void setInstrument(const AudioSynthWavetable::instrument_data& instrument) {
    for (int i = 0; i < numWavetables; i++) {
        wavetables[i]->setInstrument(instrument);
        wavetables[i]->playFrequency(440);
        wavetables[i]->amplitude(0);
    }
}

void setVolume(float volume) {
    amplitudeModifier = volume;
    sgtl5000_1.volume(volume);
}