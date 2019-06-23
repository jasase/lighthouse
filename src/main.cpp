#include "Arduino.h"
#include "FastLED.h"

#include "workingMode.h"
#include "workingValues.h"

#define DATA_PIN_WS2812 0 //PD0
#define LIGHT_PIN 0
#define LED_COLUMN_COUNT 23
#define LED_ROW_COUNT 3
#define LED_COUNT (LED_COLUMN_COUNT + LED_ROW_COUNT);

WorkingMode *workingMode;
WorkingValues *workingValues;

CRGB leds[LED_COLUMN_COUNT + LED_ROW_COUNT];

void setup()
{
    pinMode(DATA_PIN_WS2812, OUTPUT);

    FastLED.addLeds<WS2812B, DATA_PIN_WS2812>(leds, LED_COLUMN_COUNT + LED_ROW_COUNT);

    workingValues = new WorkingValues(LED_COLUMN_COUNT, LED_ROW_COUNT, leds, LIGHT_PIN);
    workingMode = new WorkingModeOff(workingValues);
}

void loop()
{
    while (true)
    {
        WorkingMode* old = workingMode;
        workingMode = workingMode->Run();

        if(old != workingMode) {
            delete old;
        }

        FastLED.show();

        delay(workingMode->getDelay());
    }
}