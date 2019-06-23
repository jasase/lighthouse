#include "workingMode.h"

WorkingModeNotDark::WorkingModeNotDark(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{ }

int WorkingModeNotDark::getDelay()
{
    return 10000; //Wait 30 seconds for next check
}

WorkingMode *WorkingModeNotDark::Run()
{
    this->getWorkingValues()->setAllLeds(CRGB::Black);

    if(this->getAverageOfLight() < 500) //Average lower than 500
    {
        return new WorkingModeOnMovingLight(this->getWorkingValues());
    }

    return this;
}