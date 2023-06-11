#include <Arduino.h>

#include "keys.h"

const int colPins[] = { 28, 27, 26, 12, 9, 6, 4 };
const int rowPins[] = { 32, 31, 30, 29, 3, 2, 1, 0 };
const int numCols = 7;
const int numRows = 8;
const int numKeys = numCols * numRows;

int keyValues[numCols][numRows];
int numPressedKeys;
int** pressedKeys;

// This function is possibly unnecessary
void initKeys() {
    for (int i = 0; i < numRows; i++) {
        pinMode(rowPins[i], INPUT);
    }
    for (int i = 0; i < numCols; i++) {
        pinMode(colPins[i], INPUT_PULLUP);
        delayMicroseconds(10);
    }
    pressedKeys = (int**) malloc(numKeys * sizeof(int*));
    for (int i = 0; i < numKeys; i++) {
        pressedKeys[i] = (int*) malloc(2 * sizeof(int));
    }
}

int getNumKeys() {
    return numKeys;
}

int getNumPressedKeys() {
    return numPressedKeys;
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
            pinMode(rowPin, INPUT);
        }
        pinMode(colPin, INPUT);
    }
}

int** readPressedKeys() {
    readKeys();
    int index = 0;
    for (int i = 0; i < numCols; i++) {
        for (int j = 0; j < numRows; j++) {
            if (keyValues[i][j] == 0) {
                pressedKeys[index][0] = i;
                pressedKeys[index][1] = j;
                index++;
            }
        }
    }
    numPressedKeys = index;
    return pressedKeys;
}
