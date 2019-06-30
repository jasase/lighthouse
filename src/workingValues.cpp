#include "Arduino.h"
#include "workingValues.h"

WorkingValues::WorkingValues(int ledColumCount, int ledRowCount, CRGB *leds, int lightPin, LightDetection *lightDetection)
{
    this->_ledColumnCount = ledColumCount;
    this->_ledRowCount = ledRowCount;
    this->_leds = leds;
    this->_lightPin = lightPin;
    this->_lightDetection = lightDetection;
}

int WorkingValues::getLedColumCount()
{
    return this->_ledColumnCount;
}
int WorkingValues::getLedRowCount()
{
    return this->_ledRowCount;
}
int WorkingValues::getLedCount()
{
    return this->_ledColumnCount * this->_ledRowCount;
}

void WorkingValues::setLed(int ledNumber, CRGB color)
{
    if (ledNumber < 0 || ledNumber >= this->getLedCount())
    {
        //TODO write error
        return;
    }

    this->_leds[ledNumber] = color;
}
void WorkingValues::setAllLeds(CRGB color)
{
    for (int i = 0; i < this->getLedCount(); i++)
    {
        this->setLed(i, color);
    }
}

bool WorkingValues::isDark() {
    return this->_lightDetection->isDark();
}

LightDetection *WorkingValues::getLightDetection() {
    return this->_lightDetection;
}