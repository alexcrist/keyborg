#ifndef KEYBORG_AUDIO_H
#define KEYBORG_AUDIO_H

#include <Audio.h>

void initAudio(int maxNumNotes);

void updateWavetables(float amplitude, float* freqs, int numFreqs);

void setInstrument(const AudioSynthWavetable::instrument_data& instrument);

void setVolume(float volume);

#endif