#include "workingMode.h"

WorkingModeOnFlash::WorkingModeOnFlash(WorkingValues *workingValues)
: WorkingModeOn(workingValues)
{
    this->_flashCounter = 0;
}
WorkingModeOnFlash::~WorkingModeOnFlash(){}

int WorkingModeOnFlash::getDelay()
{
    return 1000;
}
WorkingMode *WorkingModeOnFlash::Run()
{
    this->getWorkingValues()->setAllLeds(CRGB::Green);

    return this->workingModeSelection();
}

bool WorkingModeOnFlash::isCurrentMode()
{
    return this->getWorkingValues()->getModeSelector()->isFlashLightModeActive();
}