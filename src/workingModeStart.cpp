#include "workingMode.h"

WorkingModeStart::WorkingModeStart(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{
    this->_ledCounter = -2;
    this->_internalLoop = 0;
}

WorkingModeStart::~WorkingModeStart() {}

int WorkingModeStart::getDelay()
{
    if (_internalLoop > 3)
    {
        return 20;
    }
    return 4000;
}

WorkingMode *WorkingModeStart::Run()
{
    if (_internalLoop == 0)
    {
        this->getWorkingValues()->setAllLeds(CRGB::Green);
        _internalLoop++;
    }
    else if (_internalLoop == 1)
    {
        this->getWorkingValues()->setAllLeds(CRGB::Red);
        _internalLoop++;
    }
    else if (_internalLoop == 2)
    {
        this->getWorkingValues()->setAllLeds(CRGB::Blue);
        _internalLoop++;
    }
    else if (_internalLoop == 3)
    {
        this->getWorkingValues()->setAllLeds(CRGB::Blue);
        _internalLoop++;
    }
    else if (_internalLoop > 3)
    {
        CRGB color = CRGB::White;

        color = color.fadeLightBy(_ledCounter);

        this->getWorkingValues()->setAllLeds(color);

        _ledCounter++;
        if (_ledCounter > 255)
        {
            return new WorkingModeOff(this->getWorkingValues());
        }
    }

    return this;
}

void WorkingModeStart::setIfMatching(int ledNumber, CRGB color)
{
    if (ledNumber >= 0 && ledNumber < this->getWorkingValues()->getLedCount())
    {
        this->getWorkingValues()->setLed(ledNumber, color);
    }
}