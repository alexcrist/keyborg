#include "display.h"
#include "print.h"
#include "audio.h"
#include "knob.h"
#include "keys.h"

void setup() {
    initPrint();
    // initDisplay();
    // initAudio();
    // initKnob();
    initKeys();
}

void loop() {
    // display("hello world");
    
    // audioBoop();
    // readKnob();
    // if (wasKnobTurned()) {
    // }

    // getPressedKeys();

    Serial.println("READ KEYS");
    readKeys();
    printPressedKeys();


    delay(200);
}
