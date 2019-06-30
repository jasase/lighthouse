#include "workingMode.h"

WorkingModeOn::WorkingModeOn(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{
}

WorkingModeOn::~WorkingModeOn() {}

WorkingMode *WorkingModeOn::workingModeSelection()
{    
    if (this->getWorkingValues()->getModeSelector()->isDebugModeActive())
    {
        Serial.println("Debug Mode");
        return new WorkingModeDebug(this->getWorkingValues());
    }    
    if (!this->getWorkingValues()->getLightDetection()->isDark())
    {
        Serial.println("Off Mode");
        return new WorkingModeOff(this->getWorkingValues());
    }    
    if (isCurrentMode())
    {
        return this;
    }    
    if (this->getWorkingValues()->getModeSelector()->isFlashLightModeActive())
    {
        Serial.println("Flashing Light");
        return new WorkingModeOnFlash(this->getWorkingValues());
    }    
    if (this->getWorkingValues()->getModeSelector()->isMovingLightModeActive())
    {
        Serial.println("Moving Light");
        return new WorkingModeOnMovingLight(this->getWorkingValues());
    }    

    Serial.println("Switching to Default Mode");
    return new WorkingModeOff(this->getWorkingValues());
}