#ifndef KEYBORG_SCALES_H
#define KEYBORG_SCALES_H

#include "keys.h"

void initScales(int maxNumFreqs);

float* getFrequencies(int** pressedKeys, int numPressedKeys);

#endif
