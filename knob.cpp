#include <Encoder.h>

#include "knob.h"

static Encoder knob(33, 34);
static bool wasTurned = false;
static long knobTurn = -999;

void readKnob() {
    long newKnobTurn = floor(knob.read() / 4.0);
    wasTurned = (newKnobTurn != knobTurn);
    knobTurn = newKnobTurn;
}

bool wasKnobTurned() {
    return wasTurned;
}

long getKnobTurn() {
    return knobTurn;
}
