#include "Arduino.h"
#include "FastLED.h"

#include "workingMode.h"
#include "workingValues.h"

#define DATA_PIN_WS2812 12 //PD0
#define LIGHT_PIN 0
#define LED_COLUMN_COUNT 12
#define LED_ROW_COUNT 3

WorkingMode *workingMode;
WorkingValues *workingValues;

CRGB leds[LED_COLUMN_COUNT + LED_ROW_COUNT];

void setup()
{
    pinMode(DATA_PIN_WS2812, OUTPUT);
    pinMode(13, OUTPUT);

    FastLED.addLeds<NEOPIXEL,DATA_PIN_WS2812>(leds, LED_COLUMN_COUNT + LED_ROW_COUNT);

    workingValues = new WorkingValues(LED_COLUMN_COUNT, LED_ROW_COUNT, leds, LIGHT_PIN);
    workingMode = new WorkingModeStart(workingValues);

    workingValues->setAllLeds(CRGB::Black);
    FastLED.show();
}

void loop()
{
    bool debugLed = true;
    while (true)
    {
        WorkingMode* old = workingMode;
        workingMode = workingMode->Run();

        if(old != workingMode) {
            delete old;
        }

        FastLED.show();
        digitalWrite(13, debugLed);

        debugLed = !debugLed;

        FastLED.delay(workingMode->getDelay());        
    }
}