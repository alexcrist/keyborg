#include <Arduino.h>

#include "print.h"

void initPrint() {
    Serial.begin(9600);
    while (!Serial) {
        delay(1);
    }
}
