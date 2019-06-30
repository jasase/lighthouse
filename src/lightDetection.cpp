#include "lightDetection.h"

#define TIME_30_SECONDS 10000

LightDetection::LightDetection(int pin, ModeSelector* modeSelector)
{
    _pin = pin;
    _modeSelector = modeSelector;
    _lastReadTimestamp = TIME_30_SECONDS * -1;
}

void LightDetection::doDetection()
{
    unsigned long cur = millis();

    if (cur - _lastReadTimestamp > TIME_30_SECONDS)
    {
        for (int i = 0; i < READ_PER_RUN; i++)
        {
            int value = analogRead(_pin);
            _values.unshift(value);
        }
        _lastReadTimestamp = cur;
    }
}

float LightDetection::calculateAverage()
{
    float avg = 0.0;

    for (unsigned int i = 0; i < _values.size(); i++)
    {
        avg += _values[i];
    }

    return avg / _values.size();
}

bool LightDetection::isDark()
{    
    return _modeSelector->isLightOverrideActive() || this->calculateAverage() < 155.0;
}

float LightDetection::getValue()
{
    float avg = 0.0;

    for (int i = 0; i < READ_PER_RUN; i++)
    {
        int value = analogRead(_pin);
        avg += value;
    }

    return avg / READ_PER_RUN;
}