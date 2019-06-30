#include "workingMode.h"

WorkingModeOnFlash::WorkingModeOnFlash(WorkingValues *workingValues)
    : WorkingModeOn(workingValues)
{
    this->_flashCounter = 0;
}
WorkingModeOnFlash::~WorkingModeOnFlash() {}

int WorkingModeOnFlash::getDelay()
{
    return 600 / 255;
}
WorkingMode *WorkingModeOnFlash::Run()
{
    if (_flashCounter == 0)
    {
        this->getWorkingValues()->setAllLeds(CRGB::White);
    }

    int cycle = _flashCounter / 255;
    if (cycle == 1)
    {        
        FastLED.setBrightness(255 - (_flashCounter % 255));
    }
    else if (cycle == 2)
    {
        this->getWorkingValues()->setAllLeds(CRGB::Black);
    }
    else
    {        
        FastLED.setBrightness(_flashCounter % 255);
    }

    _flashCounter++;
    if (_flashCounter >= (3 * 255))
    {
        Serial.println("Reset");
        _flashCounter = 0;
    }
    return this->workingModeSelection();
}

bool WorkingModeOnFlash::isCurrentMode()
{
    return this->getWorkingValues()->getModeSelector()->isFlashLightModeActive();
}