#ifndef WORKING_VALUES_H
#define WORKING_VALUES_H

#include "FastLED.h"
#include "lightDetection.h"
#include "modeSelector.h"

class WorkingValues
{
public:
    WorkingValues(int ledColumCount, int ledRowCount, CRGB *leds, LightDetection *lightDetection, ModeSelector *modeSelector);
    int getLedColumCount();
    int getLedRowCount();
    int getLedCount();

    void setLed(int ledNumber, CRGB color);
    void setAllLeds(CRGB color);

    LightDetection *getLightDetection();
    ModeSelector *getModeSelector();

private:
    int _ledColumnCount;
    int _ledRowCount;
    CRGB *_leds;
    LightDetection *_lightDetection;
    ModeSelector *_modeSelector;
};

#endif