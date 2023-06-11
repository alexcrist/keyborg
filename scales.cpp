#include <stdlib.h>
#include "scales.h"
#include "keys.h"

static const float cMajor[7][8] = {
    { 15804.26, 7902.13, 3951.07, 1975.53, 987.77, 493.88, 246.94, 123.47 },
    { 14080.00, 7040.00, 3520.00, 1760.00, 880.00, 440.00, 220.00, 110.00 },
    { 12543.85, 6271.93, 3135.96, 1567.98, 783.99, 392.00, 196.00, 98.00 },
    { 11175.30, 5587.65, 2793.83, 1396.91, 698.46, 349.23, 174.61, 87.31 },
    { 10548.08, 5274.04, 2637.02, 1318.51, 659.25, 329.63, 164.81, 82.41 },
    { 9397.27, 4698.64, 2349.32, 1174.66, 587.33, 293.66, 146.83, 73.42 },
    { 8372.02, 4186.01, 2093.00, 1046.50, 523.25, 261.63, 130.81, 65.41 },
};

static float* freqs;

void initScales(int maxNumFreqs) {
    freqs = new float[maxNumFreqs];
}

float* getFrequencies(int** pressedKeys, int numPressedKeys) {
    for (int i = 0; i < numPressedKeys; i++) {
        int index1 = pressedKeys[i][0];
        int index2 = pressedKeys[i][1];
        if (index1 != -1 && index2 != -1) {
            freqs[i] = cMajor[index1][index2];
        } else {
            freqs[i] = -1;
        }
    }
    return freqs;
}
