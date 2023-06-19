#include <Audio.h>
#include <string.h>

#include "settings.h"
#include "display.h"
#include "distance.h"
#include "audio.h"
#include "scales.h"

static int waveformTypeIndex = 0;
static const int numWaveformTypes = 12;
static const int waveformTypes[] = {
    WAVEFORM_SINE, WAVEFORM_SAWTOOTH, WAVEFORM_SQUARE, WAVEFORM_TRIANGLE, WAVEFORM_ARBITRARY, WAVEFORM_PULSE,
    WAVEFORM_SAWTOOTH_REVERSE, WAVEFORM_SAMPLE_HOLD, WAVEFORM_TRIANGLE_VARIABLE, WAVEFORM_BANDLIMIT_SAWTOOTH,
    WAVEFORM_BANDLIMIT_SAWTOOTH_REVERSE, WAVEFORM_BANDLIMIT_SQUARE, WAVEFORM_BANDLIMIT_PULSE,
};
static const String waveformTypeNames[] = {
    "SINE", "SAWTOOTH", "SQUARE", "TRIANGLE", "ARBITRARY", "PULSE",
    "SAWTOOTH_REVERSE", "SAMPLE_HOLD", "TRIANGLE_VARIABLE", "BANDLIMIT_SAWTOOTH",
    "BANDLIMIT_SAWTOOTH_REVERSE", "BANDLIMIT_SQUARE", "BANDLIMIT_PULSE",
};

static int volumeIndex = 4;
static const int numVolumes = 10;
static const float volumes[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
static const String volumeNames[] = { "0.1", "0.2", "0.3", "0.4", "0.5", "0.6", "0.7", "0.8", "0.9", "1.0" };

static int distanceRangeIndex = 5;
static const int numDistanceRanges = 12;
static const int distanceRanges[] = { 20, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
static const String distanceRangeNames[] = { "20", "50", "100", "200", "300", "400", "500", "600", "700", "800", "900", "1000" };

static int scaleIndex = 0;
static const int numScales = 12;
static const int scales[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
static const String scaleNames[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

static int settingsIndex = 0;
static const int numSettings = 4;
static const String settingsNames[] = { "Waveform type", "Volume", "Distance range", "Scale" };

void displaySettings() {
    String message = settingsNames[settingsIndex] + ": ";
    if (settingsIndex == 0) {
        message += waveformTypeNames[waveformTypeIndex];
    } else if (settingsIndex == 1) { 
        message += volumeNames[volumeIndex];
    } else if (settingsIndex == 2) { 
        message += distanceRangeNames[distanceRangeIndex] + "mm";
    } else if (settingsIndex == 3) {
        message += scaleNames[scaleIndex] + " major";
    }
    display(message);
}

int updateIndex(int oldIndex, int numOptions, int indexDiff) {
  return (((oldIndex + indexDiff) % numOptions) + numOptions) % numOptions;
}

void initSettings() {
    displaySettings();
}

void changeSettingsIndex(int indexDiff) {
    settingsIndex = updateIndex(settingsIndex, numSettings, indexDiff);
    displaySettings();
}

void changeSettingsValue(int indexDiff) {
    if (settingsIndex == 0) {
        waveformTypeIndex = updateIndex(waveformTypeIndex, numWaveformTypes, indexDiff);
        setWaveformType(waveformTypes[waveformTypeIndex]);
    } else if (settingsIndex == 1) { 
        volumeIndex = updateIndex(volumeIndex, numVolumes, indexDiff);
        setVolume(volumes[volumeIndex]);
    } else if (settingsIndex == 2) { 
        distanceRangeIndex = updateIndex(distanceRangeIndex, numDistanceRanges, indexDiff);
        setDistanceRange(distanceRanges[distanceRangeIndex]);
    } else if (settingsIndex == 3) {
        scaleIndex = updateIndex(scaleIndex, numScales, indexDiff);
        setScale(scales[scaleIndex]);
    }
    displaySettings();
}

