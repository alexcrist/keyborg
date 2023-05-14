#include <Encoder.h>

#include "knob.h"

Encoder knob(33, 34);
bool _wasKnobTurned = false;
long _knobTurn = -999;

void initKnob() {
    _knobTurn = knob.read();
}

void readKnob() {
    long newKnobTurn = knob.read();
    _wasKnobTurned = (newKnobTurn != _knobTurn);
    _knobTurn = newKnobTurn;
}

bool wasKnobTurned() {
    return _wasKnobTurned;
}

long getKnobTurn() {
    return _knobTurn;
}
