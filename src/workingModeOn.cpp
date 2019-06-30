#include "workingMode.h"

WorkingModeOn::WorkingModeOn(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{
}

WorkingModeOn::~WorkingModeOn() {}

WorkingMode *WorkingModeOn::workingModeSelection()
{
    if (!this->getWorkingValues()->getModeSelector()->isDebugModeActive())
    {
        return new WorkingModeDebug(this->getWorkingValues());
    }
    if (!this->getWorkingValues()->getLightDetection()->isDark())
    {
        return new WorkingModeOff(this->getWorkingValues());
    }
    if (isCurrentMode())
    {
        return this;
    }

    if (!this->getWorkingValues()->getModeSelector()->isFlashLightModeActive())
    {
        return new WorkingModeOnFlash(this->getWorkingValues());
    }
    if (!this->getWorkingValues()->getModeSelector()->isMovingLightModeActive())
    {
        return new WorkingModeOnMovingLight(this->getWorkingValues());
    }

    return new WorkingModeOff(this->getWorkingValues());
}