#include "workingMode.h"

WorkingMode::WorkingMode(WorkingValues *workingValues)
{
    this->_workingValues = workingValues;

    this->currentValueCounter = 0;
    for (int i = 0; i < LAST_LIGHT_ARRAY_LENGTH; i++)
    {
        this->lastLightValues[i] = 1023;
    }
}

int WorkingMode::getAverageOfLight()
{
    this->lastLightValues[this->currentValueCounter] = this->getWorkingValues()->getLightValue();
    this->currentValueCounter++;
    if (this->currentValueCounter % LAST_LIGHT_ARRAY_LENGTH == 0)
    {
        this->currentValueCounter = 0;
    }

    int sumValues = 0;
    for (int i = 0; i < LAST_LIGHT_ARRAY_LENGTH; i++)
    {
        sumValues += this->lastLightValues[i];
    }

    return sumValues / LAST_LIGHT_ARRAY_LENGTH;
}

WorkingValues *WorkingMode::getWorkingValues()
{
    return this->_workingValues;
}