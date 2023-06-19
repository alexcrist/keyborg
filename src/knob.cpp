#include <Encoder.h>

#include "knob.h"

#define ROTARY_PIN_A 33
#define ROTARY_PIN_B 34
#define BUTTON_PIN 35

static Encoder knob(ROTARY_PIN_A, ROTARY_PIN_B);
static int knobTurn = 0;
static int knobClick = 0;

void initKnob() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

int readKnobClickDiff() {
    int newKnobClick = (digitalRead(BUTTON_PIN) == LOW) ? 1 : 0;
    int knobClickDiff = newKnobClick - knobClick;
    knobClick = newKnobClick;
    return knobClickDiff;
}

int readKnobTurnDiff() {
    int newKnobTurn = floor(knob.read() / 4.0);
    int knobTurnDiff = newKnobTurn - knobTurn;
    knobTurn = newKnobTurn;
    return knobTurnDiff;
}
