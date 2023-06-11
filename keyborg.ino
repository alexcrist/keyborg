#include <Arduino.h>
#include <string.h>

#include "display.h"
#include "print.h"
#include "audio.h"
#include "knob.h"
#include "keys.h"
#include "distance.h"
#include "scales.h"

#define MAX_DISTANCE 200.0

void setup() {
    initPrint();
    initKeys();
    initAudio(getNumKeys());
    initScales(getNumKeys());
    initDisplay();
    initDistance();
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

    // Read knob
    readKnob();
    bool wasTurned = wasKnobTurned();
    long knobValue = getKnobTurn();

    // If knob was changed, update waveform type
    if (wasTurned) {
        int numTypes = getNumWaveformTypes();
        int waveformTypeIndex = ((knobValue % numTypes) + numTypes) % numTypes;
        setWaveformTypeIndex(waveformTypeIndex);
        display(getWaveformTypeName(waveformTypeIndex));
    }
} 
