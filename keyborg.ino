#include <Arduino.h>

#include "display.h"
#include "print.h"
#include "audio.h"
#include "knob.h"
#include "keys.h"
#include "distance.h"
#include "scales.h"

#define MAX_DISTANCE 300.0

void setup() {
    initPrint();
    initDistance();
    initKeys();
    initAudio(getNumKeys());
    initScales(getNumKeys());
}

void loop() {

    // Calculate waveforms' amplitude
    int distance = readDistance();
    float amplitude = max(min(1, (MAX_DISTANCE - distance) / MAX_DISTANCE), 0);

    // Calculate waveforms' frequencies
    int numPressedKeys = getNumPressedKeys();
    int** pressedKeys = readPressedKeys();
    float* freqs = getFrequencies(pressedKeys, numPressedKeys);

    // Update waveforms
    updateWaveforms(amplitude, freqs, numPressedKeys);
}
