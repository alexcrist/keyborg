#include <Audio.h>
#include <string.h>

#include "instruments/MidiSynthLarge/bassoon_samples.h"
#include "instruments/MidiSynthLarge/clarinet_samples.h"
#include "instruments/MidiSynthLarge/distortiongt_samples.h"
#include "instruments/MidiSynthLarge/epiano_samples.h"
#include "instruments/MidiSynthLarge/flute_samples.h"
#include "instruments/MidiSynthLarge/frenchhorn_samples.h"
#include "instruments/MidiSynthLarge/glockenspiel_samples.h"
#include "instruments/MidiSynthLarge/gtfretnoise_samples.h"
#include "instruments/MidiSynthLarge/harmonica_samples.h"
#include "instruments/MidiSynthLarge/harp_samples.h"
#include "instruments/MidiSynthLarge/mutedgtr_samples.h"
#include "instruments/MidiSynthLarge/nylonstrgtr_samples.h"
#include "instruments/MidiSynthLarge/oboe_samples.h"
#include "instruments/MidiSynthLarge/overdrivegt_samples.h"
#include "instruments/MidiSynthLarge/piano_samples.h"
#include "instruments/MidiSynthLarge/recorder_samples.h"
#include "instruments/MidiSynthLarge/steelstrgtr_samples.h"
#include "instruments/MidiSynthLarge/strings_samples.h"
#include "instruments/MidiSynthLarge/timpani_samples.h"
#include "instruments/MidiSynthLarge/trombone_samples.h"
#include "instruments/MidiSynthLarge/trumpet_samples.h"
#include "instruments/MidiSynthLarge/tuba_samples.h"
#include "instruments/MidiSynthLarge/vibraphone_samples.h"

#include "settings.h"
#include "display.h"
#include "distance.h"
#include "audio.h"
#include "scales.h"

static int instrumentIndex = 0;
static const int numInstruments = 23;
static const AudioSynthWavetable::instrument_data instruments[] = {
    bassoon,
    clarinet,
    distortiongt,
    epiano,
    flute,
    frenchhorn,
    glockenspiel,
    gtfretnoise,
    harmonica,
    harp,
    mutedgtr,
    nylonstrgtr,
    oboe,
    overdrivegt,
    piano,
    recorder,
    steelstrgtr,
    strings,
    timpani,
    trombone,
    trumpet,
    tuba,
    vibraphone,
};
static const String instrumentNames[] = {
    "bassoon",
    "clarinet",
    "distortiongt",
    "epiano",
    "flute",
    "frenchhorn",
    "glockenspiel",
    "gtfretnoise",
    "harmonica",
    "harp",
    "mutedgtr",
    "nylonstrgtr",
    "oboe",
    "overdrivegt",
    "piano",
    "recorder",
    "steelstrgtr",
    "strings",
    "timpani",
    "trombone",
    "trumpet",
    "tuba",
    "vibraphone",
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
static const String settingsNames[] = { "Instrument", "Volume", "Distance range", "Scale" };

void displaySettings() {
    String message = settingsNames[settingsIndex] + ": ";
    if (settingsIndex == 0) {
        message += instrumentNames[instrumentIndex];
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
    setInstrument(instruments[instrumentIndex]);
}

void changeSettingsIndex(int indexDiff) {
    settingsIndex = updateIndex(settingsIndex, numSettings, indexDiff);
    displaySettings();
}

void changeSettingsValue(int indexDiff) {
    if (settingsIndex == 0) {
        instrumentIndex = updateIndex(instrumentIndex, numInstruments, indexDiff);
        setInstrument(instruments[instrumentIndex]);
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

