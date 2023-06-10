#include <Arduino.h>

#include "keys.h"

const int colPins[] = { 28, 27, 26, 12, 9, 6, 4 };
const int rowPins[] = { 32, 31, 30, 29, 3, 2, 1, 0 };
const int numCols = 7;
const int numRows = 8;

int keyValues[numCols][numRows];

void initKeys() {
    for (int i = 0; i < numRows; i++) {
        pinMode(rowPins[i], INPUT);
    }
    for (int i = 0; i < numCols; i++) {
        pinMode(colPins[i], INPUT_PULLUP);
        delayMicroseconds(10);
    }
}

void readKeys() {
    for (int i = 0; i < numCols; i++) {
        int colPin = colPins[i];
        pinMode(colPin, OUTPUT);
        digitalWrite(colPin, LOW);
        for (int j = 0; j < numRows; j++) {
            int rowPin = rowPins[j];
            pinMode(rowPin, INPUT_PULLUP);
            delayMicroseconds(10);
            keyValues[i][j] = digitalRead(rowPin);

            if (keyValues[i][j] == 0) {
              Serial.print("(");
              Serial.print(i);
              Serial.print(",");
              Serial.print(j);
              Serial.println(")");
            }

            pinMode(rowPin, INPUT);
        }
        pinMode(colPin, INPUT);
    }
}
