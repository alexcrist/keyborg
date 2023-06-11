#include <Audio.h>

#include "audio.h"

AudioSynthWaveformSine   sine2;          //xy=207,260
AudioSynthWaveformSine   sine3;          //xy=207,294
AudioSynthWaveformSine   sine4;          //xy=208,334
AudioSynthWaveformSine   sine1;          //xy=211,222
AudioMixer4              mixer1;         //xy=440,298
AudioOutputI2S           i2s1;           //xy=610,305
AudioConnection          patchCord1(sine2, 0, mixer1, 1);
AudioConnection          patchCord2(sine3, 0, mixer1, 2);
AudioConnection          patchCord3(sine4, 0, mixer1, 3);
AudioConnection          patchCord4(sine1, 0, mixer1, 0);
AudioConnection          patchCord5(mixer1, 0, i2s1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 1);

int numWaveforms = 4;
AudioSynthWaveformSine* waveforms[] = {
    &sine1,
    &sine2,
    &sine3,
    &sine4
};

void initAudio(int maxNumNotes) {
    AudioMemory(10);
}

void updateWaveforms(float amplitude, float* freqs, int numFreqs) {
    for (int i = 0; i < numWaveforms; i++) {
        if (i < numFreqs && freqs[i] != -1) {
            waveforms[i]->frequency(freqs[i]);
            waveforms[i]->amplitude(amplitude * (1.0 / numWaveforms));
        } else {
            waveforms[i]->amplitude(0);
        }
    }
}
