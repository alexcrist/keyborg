#include <Arduino.h>
#include <Wire.h>

#include "distance.h"
#include "VL53L0X.h"

VL53L0X sensor;

void initDistance() {
    Wire1.begin();
    sensor.setBus(&Wire1);
    if (!sensor.init()) {
        Serial.println("Failed to detect and initialize sensor!");
        while (1) {}
    }
    sensor.startContinuous();
}

uint16_t readDistance() {
    return sensor.readRangeContinuousMillimeters();
}