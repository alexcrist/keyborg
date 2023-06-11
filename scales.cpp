#include <stdlib.h>
#include "scales.h"
#include "keys.h"

const float cMajor[7][8] = {
    { 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01, 8372.02 },
    { 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.64, 9397.27 },
    { 82.41, 164.81, 329.63, 659.25, 1318.51, 2637.02, 5274.04, 10548.08 },
    { 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83, 5587.65, 11175.30 },
    { 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96, 6271.93, 12543.85 },
    { 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00, 7040.00, 14080.00 },
    { 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.07, 7902.13, 15804.26 }
};

static float* freqs;

void initScales(int maxNumFreqs) {
    freqs = (float*) malloc(maxNumFreqs * sizeof(float));
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
