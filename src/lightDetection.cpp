#include "lightDetection.h"
#include "Arduino.h"

#define TIME_30_SECONDS 10000

LightDetection::LightDetection(int pin, int pinoverride)
{
    _pin = pin;
    _pinOverride = pinoverride;
    _lastReadTimestamp = TIME_30_SECONDS * -1;
}

void LightDetection::doDetection()
{
    unsigned long cur = millis();

    if (cur - _lastReadTimestamp > TIME_30_SECONDS)
    {
        Serial.print("Read light: ");

        for (int i = 0; i < READ_PER_RUN; i++)
        {
            int value = analogRead(_pin);
            _values.unshift(value);    

            Serial.print(value);        
            Serial.print(" "); 
        }        
        _lastReadTimestamp = cur;

        Serial.print(" Avg: "); 
        Serial.println(calculateAverage());
    }
}

float LightDetection::calculateAverage() {
    float avg = 0.0;

    for (unsigned int i = 0; i < _values.size(); i++)
    {
        avg += _values[i];
    }

    return avg / _values.size();
}

bool LightDetection::isDark()
{
    int override = digitalRead(_pinOverride);    
    return override > 0 || this->calculateAverage() < 300.0;
}