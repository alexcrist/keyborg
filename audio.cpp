#include <Audio.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Bounce.h>

#include "audio.h"

AudioSynthWaveform waveform1;
AudioOutputI2S i2s1;
AudioConnection patchCord1(waveform1, 0, i2s1, 0);
AudioConnection patchCord2(waveform1, 0, i2s1, 1);
AudioControlSGTL5000 sgtl5000_1;

void initAudio() {
    AudioMemory(10);
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);
    waveform1.frequency(440);
    waveform1.amplitude(0.9);
}

void setAudioAmplitude(float amplitude) {
    waveform1.amplitude(amplitude);
}
