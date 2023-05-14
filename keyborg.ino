#include "display.h"
#include "print.h"

void setup() {
    initDisplay();
}

void loop() {
    // print("hello world!");
    display("hello world");
    delay(1000);
}
