#include "Arduino.h"
#include "workingValues.h"

WorkingValues::WorkingValues(int ledColumCount, int ledRowCount, CRGB *leds, int lightPin)
{
    this->_ledColumnCount = ledColumCount;
    this->_ledRowCount = ledRowCount;
    this->_leds = leds;
    this->_lightPin = lightPin;
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
    return this->_ledColumnCount + this->_ledRowCount;
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

int WorkingValues::getLightValue() {
    return analogRead(this->_lightPin);
}