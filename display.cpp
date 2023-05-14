#include <TeensyView.h>

#include "display.h"

#define DISPLAY_PIN_RESET 15
#define DISPLAY_PIN_DC 5
#define DISPLAY_PIN_CS 10
#define DISPLAY_PIN_SCK 13
#define DISPLAY_PIN_MOSI 11

TeensyView teensyView(
    DISPLAY_PIN_RESET, 
    DISPLAY_PIN_DC, 
    DISPLAY_PIN_CS, 
    DISPLAY_PIN_SCK, 
    DISPLAY_PIN_MOSI
);

void initDisplay() {
    teensyView.begin();
    teensyView.clear(ALL);
}

void display(String message) {
    teensyView.clear(PAGE);
    teensyView.setCursor(0, 0);
    teensyView.setFontType(1);
    teensyView.print(message);
    teensyView.display();
}