#ifndef KEYBORG_SCALES_H
#define KEYBORG_SCALES_H

void initScales(int maxNumFreqs);

float* getFrequencies(int** pressedKeys, int numPressedKeys);

void setScale(int noteIndex);

#endif
