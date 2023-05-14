#include "display.h"
#include "print.h"
#include "audio.h"
#include "knob.h"

void setup() {
    initPrint();
    initDisplay();
    initAudio();
    initKnob();
}

void loop() {
    print("hello world!");
    display("hello world");
    // audioBoop();
    readKnob();
    if (wasKnobTurned()) {
        print(getKnobTurn());
    }
    delay(200);
}
