#include <Arduino.h>
#include <Wire.h>

#include "distance.h"
#include "VL53L0X.h"

static VL53L0X sensor;

static const float minDistanceMM = 50;
static const float maxDistanceMM = 700;
static const float rangeMM = maxDistanceMM - minDistanceMM;

void initDistance() {
    Wire1.begin();
    sensor.setBus(&Wire1);
    if (!sensor.init()) {
        Serial.println("Failed to detect and initialize sensor!");
        while (1) {}
    }
    sensor.startContinuous();
}

// Outputs a distance reading from 0.0 (far) to 1.0 (close)
float readDistance() {
    u_int16_t distanceMM = sensor.readRangeContinuousMillimeters();
    distanceMM = max(minDistanceMM, distanceMM);
    distanceMM = min(maxDistanceMM, distanceMM);
    return 1 - ((distanceMM - minDistanceMM) / rangeMM);
}