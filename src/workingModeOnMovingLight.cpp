#include "workingMode.h"

WorkingModeOnMovingLight::WorkingModeOnMovingLight(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{  
    this->columnCounter = 0;
}

int WorkingModeOnMovingLight::getDelay()
{
    return 7500 / this->getWorkingValues()->getLedColumCount(); 
    // 7.5 second for one complete turn
}

WorkingMode *WorkingModeOnMovingLight::Run()
{
    this->getWorkingValues()->setAllLeds(CRGB::Black);        

    if(this->getAverageOfLight() > 500) //Average lower than 500
    {
        return new WorkingModeOff(this->getWorkingValues());
    }

    CRGB whiteHalf = CRGB::WhiteSmoke;
    
    whiteHalf.fadeLightBy(64);

    this->setColumnTo((this->columnCounter - 2) % this->getWorkingValues()->getLedColumCount(),CRGB::Black);
    this->setColumnTo((this->columnCounter - 1) % this->getWorkingValues()->getLedColumCount(),whiteHalf);
    this->setColumnTo(this->columnCounter,CRGB::White);
    this->setColumnTo((this->columnCounter + 1) % this->getWorkingValues()->getLedColumCount(),whiteHalf);

    this->columnCounter++;
    if(this->columnCounter % this->getWorkingValues()->getLedColumCount() == 0) {
        this->columnCounter = 0;
    }
    return this;
}

void WorkingModeOnMovingLight::setColumnTo(int column, CRGB color) {

    for (int i = 0; i < this->getWorkingValues()->getLedRowCount(); i++)
    {
        int ledPostion = i * this->getWorkingValues()->getLedColumCount() + column;
        this->getWorkingValues()->setLed(ledPostion, color);
    }
}