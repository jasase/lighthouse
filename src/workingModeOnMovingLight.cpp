#include "workingMode.h"

WorkingModeOnMovingLight::WorkingModeOnMovingLight(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{  }

int WorkingModeOnMovingLight::getDelay()
{
    return 10000; //Wait 30 seconds for next check
}

WorkingMode *WorkingModeOnMovingLight::Run()
{
    this->getWorkingValues()->setAllLeds(CRGB::Black);
        
    if(this->getAverageOfLight() > 500) //Average lower than 500
    {
        return new WorkingModeOnMovingLight(this->getWorkingValues());
    }

    return this;
}