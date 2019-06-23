#include "workingMode.h"

WorkingModeStart::WorkingModeStart(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{
    this->ledCoounter = -2;
}

int WorkingModeStart::getDelay()
{
    return 500; //Wait 30 seconds for next check
}

WorkingMode *WorkingModeStart::Run()
{
    setIfMatching(this->ledCoounter, CRGB::Red);
    setIfMatching(this->ledCoounter + 1, CRGB::Green);
    setIfMatching(this->ledCoounter + 2, CRGB::Blue);

    this->ledCoounter++;
    if (this->ledCoounter < this->getWorkingValues()->getLedCount())
    {
        return this;
    }
    return new WorkingModeOff(this->getWorkingValues());
}

void WorkingModeStart::setIfMatching(int ledNumber, CRGB color)
{
    if (ledNumber >= 0 && ledNumber < this->getWorkingValues()->getLedCount())
    {
        this->getWorkingValues()->setLed(ledNumber, color);
    }
}