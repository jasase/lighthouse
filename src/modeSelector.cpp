#include "workingMode.h"

ModeSelector::ModeSelector(int pins[MODE_SELECTOR_PIN_COUNTER])
{

    for (int i = 0; i < MODE_SELECTOR_PIN_COUNTER; i++)
    {
        this->_pins[i] = pins[i];
        pinMode(this->_pins[i], INPUT);
    }
}

bool ModeSelector::isLightOverrideActive()
{
    return (this->getCurrentValue() & 1) == 1;
}
bool ModeSelector::isDebugModeActive()
{
    return (this->getCurrentValue() & 2) == 2;
}
bool ModeSelector::isMovingLightModeActive()
{
    return (this->getCurrentValue() & 60) == 0;
}
bool ModeSelector::isFlashLightModeActive()
{
    return (this->getCurrentValue() & 60) == 4;
}

int ModeSelector::getCurrentValue()
{    
    int curValue = 0;

    for (int i = 0; i < MODE_SELECTOR_PIN_COUNTER; i++)
    { 
        int pinValue = digitalRead(this->_pins[i]);     
        curValue += pinValue << i;        
    }

    return curValue;
}