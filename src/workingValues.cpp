#include "Arduino.h"
#include "workingValues.h"

WorkingValues::WorkingValues(int ledColumCount, int ledRowCount, CRGB *leds, LightDetection *lightDetection, ModeSelector *modeSelector)               
{
    this->_ledColumnCount = ledColumCount;
    this->_ledRowCount = ledRowCount;
    this->_leds = leds;
    this->_lightDetection = lightDetection;
    this->_modeSelector = modeSelector;
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

LightDetection *WorkingValues::getLightDetection() {
    return this->_lightDetection;
}

ModeSelector *WorkingValues::getModeSelector() {
    return this->getModeSelector();
}