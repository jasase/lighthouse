#include "workingMode.h"

WorkingModeOff::WorkingModeOff(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{ }

int WorkingModeOff::getDelay()
{
    return 10000; //Wait 30 seconds for next check
}

WorkingMode *WorkingModeOff::Run()
{
    this->getWorkingValues()->setAllLeds(CRGB::Black);

    if(this->getAverageOfLight() < 500) //Average lower than 500
    {
        return new WorkingModeOnMovingLight(this->getWorkingValues());
    }

    return this;
}