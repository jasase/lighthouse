#include "workingMode.h"
#include "Arduino.h"

WorkingModeDebug::WorkingModeDebug(WorkingValues *workingValues)
    : WorkingMode(workingValues)
{
}

WorkingModeDebug::~WorkingModeDebug() {}

int WorkingModeDebug::getDelay()
{
    return 500; //Wait 10 seconds for next check
}

WorkingMode *WorkingModeDebug::Run()
{

    this->getWorkingValues()->setLed(0, pinToColor(2));
    this->getWorkingValues()->setLed(1, pinToColor(3));
    this->getWorkingValues()->setLed(2, pinToColor(4));
    this->getWorkingValues()->setLed(3, pinToColor(5));
    this->getWorkingValues()->setLed(4, pinToColor(6));
    this->getWorkingValues()->setLed(5, pinToColor(7));

    this->getWorkingValues()->setLed(7, boolToColor(this->getWorkingValues()->getLightDetection()->isDark()));

    const int ledShift = 9;
    int barLedCount = this->getWorkingValues()->getLedCount() - ledShift;
    Serial.println(barLedCount);
    float curValue = this->getWorkingValues()->getLightDetection()->getValue();
    int bisOn = (barLedCount / 1023.0) * curValue;
    Serial.println(bisOn);
    Serial.println(curValue);
    Serial.println("____________________________________________________");
    for (int i = ledShift; i < this->getWorkingValues()->getLedCount(); i++)
    {
        CRGB color = CRGB::Black;
        if (i - ledShift <= bisOn)
        {
            color = CRGB::White;
        }

        this->getWorkingValues()->setLed(i, color);
    }

    return this;
}

CRGB WorkingModeDebug::pinToColor(int pin)
{
    return boolToColor(digitalRead(pin) == 1);
}

CRGB WorkingModeDebug::boolToColor(bool value)
{
    if (value)
    {
        return CRGB::Green;
    }
    else
    {
        return CRGB::Red;
    }
}
