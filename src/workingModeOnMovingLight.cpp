#include "workingMode.h"

WorkingModeOnMovingLight::WorkingModeOnMovingLight(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{
    this->columnCounter = 0;
}

WorkingModeOnMovingLight::~WorkingModeOnMovingLight() {}

int WorkingModeOnMovingLight::getDelay()
{
    return 2000 / this->getWorkingValues()->getLedColumCount();
    // 5 second for one complete turn
}

WorkingMode *WorkingModeOnMovingLight::Run()
{
    this->getWorkingValues()->setAllLeds(CRGB::Black);

    if (!this->getWorkingValues()->isDark())
    {
        return new WorkingModeOff(this->getWorkingValues());
    }

    CRGB whiteHalf = CRGB::WhiteSmoke;

    whiteHalf.fadeLightBy(64);

    for (int i = 0; i < this->getWorkingValues()->getLedRowCount(); i++)
    {
        int curCounter = this->columnCounter + i;

        this->setColumnTo((curCounter - 2) % this->getWorkingValues()->getLedColumCount(), CRGB::Black);
        this->setColumnTo((curCounter - 1) % this->getWorkingValues()->getLedColumCount(), whiteHalf);
        this->setColumnTo(curCounter, CRGB::White);
        this->setColumnTo((curCounter + 1) % this->getWorkingValues()->getLedColumCount(), whiteHalf);
    }

    this->columnCounter++;
    if (this->columnCounter % this->getWorkingValues()->getLedColumCount() == 0)
    {
        this->columnCounter = 0;
    }
    return this;
}

void WorkingModeOnMovingLight::setColumnTo(int column, CRGB color)
{

    for (int i = 0; i < this->getWorkingValues()->getLedRowCount(); i++)
    {
        int ledPostion = i * this->getWorkingValues()->getLedColumCount() + column;
        this->getWorkingValues()->setLed(ledPostion, color);
    }
}