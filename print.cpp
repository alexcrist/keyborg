#include <Arduino.h>

#include "print.h"

void initPrint() {
    Serial.begin(9600);
    while (!Serial) {
        delay(1);
    }
}

void print(String message) {
    Serial.println(message);
}

void print(long message) {
    Serial.println(message);
}