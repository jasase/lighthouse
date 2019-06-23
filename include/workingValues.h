#ifndef WORKING_VALUES_H
#define WORKING_VALUES_H

#include "FastLED.h"

class WorkingValues
{
public:
    WorkingValues(int ledColumCount, int ledRowCount, CRGB *leds, int lightPin);
    int getLedColumCount();
    int getLedRowCount();
    int getLedCount();

    void setLed(int ledNumber, CRGB color);
    void setAllLeds(CRGB color);

    int getLightValue();

private:
    int _ledColumnCount;
    int _ledRowCount;
    int _lightPin;
    CRGB *_leds;
};

#endif