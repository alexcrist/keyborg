#include <string.h>

#include "src/display.h"
#include "src/print.h"
#include "src/audio.h"
#include "src/knob.h"
#include "src/keys.h"
#include "src/distance.h"
#include "src/scales.h"
#include "src/settings.h"

void setup() {
    initPrint();
    initKeys();
    initKnob();
    initAudio(getNumKeys());
    initScales(getNumKeys());
    initDisplay();
    initDistance();
    initSettings();
}

void loop() {

    // Update waveforms' amplitudes and frequencies
    float amplitude = readDistance();
    int numPressedKeys = getNumPressedKeys();
    int** pressedKeys = readPressedKeys();
    float* frequencies = getFrequencies(pressedKeys, numPressedKeys);
    updateWaveforms(amplitude, frequencies, numPressedKeys);

    // Read knob, update settings
    int knobTurnDiff = readKnobTurnDiff();
    int knobClickDiff = readKnobClickDiff();
    if (knobClickDiff == 1) {
        changeSettingsIndex(1);
    }
    if (knobTurnDiff != 0) {
        changeSettingsValue(knobTurnDiff);
    }
} 
