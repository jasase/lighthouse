#include "workingMode.h"

WorkingModeOnMovingLight::WorkingModeOnMovingLight(WorkingValues *workingValues)
    : WorkingModeOn(workingValues)
{
    this->columnCounter = 0;
}

WorkingModeOnMovingLight::~WorkingModeOnMovingLight() {}

bool WorkingModeOnMovingLight::isCurrentMode()
{
    return this->getWorkingValues()->getModeSelector()->isMovingLightModeActive();
}

int WorkingModeOnMovingLight::getDelay()
{
    return 2000 / this->getWorkingValues()->getLedColumCount();
    // 5 second for one complete turn
}

WorkingMode *WorkingModeOnMovingLight::Run()
{
    if (this->columnCounter == 0)
    {
        FastLED.setBrightness(255);
        this->getWorkingValues()->setAllLeds(CRGB::Black);
    }

    CRGB whiteHalf = CRGB::WhiteSmoke;

    whiteHalf = whiteHalf.fadeLightBy(225);

    // for (int i = 0; i < this->getWorkingValues()->getLedRowCount(); i++)
    // {
         int curCounter = this->columnCounter;

        this->setColumnTo((curCounter - 2) % this->getWorkingValues()->getLedColumCount(), CRGB::Black);        
        this->setColumnTo((curCounter - 1) % this->getWorkingValues()->getLedColumCount(), whiteHalf);
        this->setColumnTo(curCounter, CRGB::White);        
        this->setColumnTo((curCounter + 1) % this->getWorkingValues()->getLedColumCount(), whiteHalf);
    // }

    this->columnCounter++;
    if (this->columnCounter % this->getWorkingValues()->getLedColumCount() == 0)
    {
        this->columnCounter = 0;
    }

    return this->workingModeSelection();
}

void WorkingModeOnMovingLight::setColumnTo(int column, CRGB color)
{

    for (int i = 0; i < this->getWorkingValues()->getLedRowCount(); i++)
    {
        int ledPostion = i * this->getWorkingValues()->getLedColumCount() + column;
        this->getWorkingValues()->setLed(ledPostion, color);
    }
}