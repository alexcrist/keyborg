#include "display.h"
#include "print.h"
#include "audio.h"
#include "knob.h"
#include "keys.h"
#include "distance.h"

using namespace std;

#define MAX_DISTANCE 300.0

void setup() {
    initPrint();
    initAudio();
    initDistance();
}

void loop() {
    int distance = readDistance();
    float amplitude = max(min(1, (MAX_DISTANCE - distance) / MAX_DISTANCE), 0);
    setAudioAmplitude(amplitude);
}
