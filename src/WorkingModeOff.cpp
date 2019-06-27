#include "workingMode.h"

WorkingModeOff::WorkingModeOff(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{
}

WorkingModeOff::~WorkingModeOff() {}

int WorkingModeOff::getDelay()
{
    return 10000; //Wait 10 seconds for next check
}

WorkingMode *WorkingModeOff::Run()
{
    this->getWorkingValues()->setAllLeds(CRGB::Black);

    if (this->getWorkingValues()->isDark())
    {
        return new WorkingModeOnMovingLight(this->getWorkingValues());
    }

    return this;
}