#include <string.h>

#include "display.h"
#include "print.h"
#include "audio.h"
#include "knob.h"
#include "keys.h"
#include "distance.h"
#include "scales.h"

void setup() {
    initPrint();
    initKeys();
    initAudio(getNumKeys());
    initScales(getNumKeys());
    initDisplay();
    initDistance();
}

void loop() {

    // Update waveforms' amplitudes and frequencies
    float amplitude = readDistance();
    int numPressedKeys = getNumPressedKeys();
    int** pressedKeys = readPressedKeys();
    float* frequencies = getFrequencies(pressedKeys, numPressedKeys);
    updateWaveforms(amplitude, frequencies, numPressedKeys);

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
