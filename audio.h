#ifndef KEYBORG_AUDIO_H
#define KEYBORG_AUDIO_H

void initAudio(int maxNumNotes);

void updateWaveforms(float amplitude, float* freqs, int numFreqs);

#endif