#ifndef KEYBORG_AUDIO_H
#define KEYBORG_AUDIO_H

#include <string.h>

void initAudio(int maxNumNotes);

void updateWaveforms(float amplitude, float* freqs, int numFreqs);

void setWaveformType(int waveformType);

void setVolume(float volume);

#endif