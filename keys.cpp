#include <Arduino.h>

#include "keys.h"

// const int rowPins[] = { 28, 27, 26, 12, 9, 6, 4 };
// const int colPins[] = { 32, 31, 30, 29, 3, 2, 1, 0 };

const int colPins[] = { 28, 27 };
const int rowPins[] = { 32, 31 };
const int numRows = 2;
const int numCols = 2;

int keyValues[numCols][numRows];

void initKeys() {
    // TODO - is this necessary?
    for (int i = 0; i < numRows; i++) {
        pinMode(rowPins[i], INPUT);
    }
    for (int i = 0; i < numCols; i++) {
        pinMode(colPins[i], INPUT_PULLUP);
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
            keyValues[i][j] = digitalRead(rowPin);

            Serial.print("(");
            Serial.print(i);
            Serial.print(",");
            Serial.print(j);
            Serial.print(") = ");
            Serial.println(keyValues[i][j]);

            pinMode(rowPin, INPUT);
        }
        pinMode(colPin, INPUT);
    }
}

void printPressedKeys() {
    // for (int i = 0; i < numCols; i++) {
    //     for (int j = 0; j < numRows; j++) {
    //         if (keyValues[i][j] == HIGH) {
    //             Serial.print("(");
    //             Serial.print(i);
    //             Serial.print(",");
    //             Serial.print(j);
    //             Serial.print(") is pressed\n");
    //         }
    //     }
    // }
}