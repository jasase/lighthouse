#include "Arduino.h"
#include "FastLED.h"

#include "workingMode.h"
#include "workingValues.h"
#include "lightDetection.h"

#define DATA_PIN_WS2812 12 //PD0

#define LIGHT_PIN 7
#define LIGHT_OVERRIDE_PIN 7

#define DEBUG_MODE_PIN 6

#define LED_COLUMN_COUNT 23
#define LED_ROW_COUNT 3

WorkingMode *workingMode;
WorkingValues *workingValues;
LightDetection *lightDetection;

CRGB leds[LED_COLUMN_COUNT * LED_ROW_COUNT];

void setup()
{
    Serial.begin(9600);

    pinMode(DATA_PIN_WS2812, OUTPUT);
    pinMode(LIGHT_OVERRIDE_PIN, INPUT);
    pinMode(DEBUG_MODE_PIN, INPUT);

    //Currently only used in debug mode
    pinMode(5, INPUT);
    pinMode(4, INPUT);
    pinMode(3, INPUT);
    pinMode(2, INPUT);

    pinMode(13, OUTPUT);

    FastLED.addLeds<NEOPIXEL, DATA_PIN_WS2812>(leds, LED_COLUMN_COUNT * LED_ROW_COUNT);

    lightDetection = new LightDetection(LIGHT_PIN, LIGHT_OVERRIDE_PIN);
    workingValues = new WorkingValues(LED_COLUMN_COUNT, LED_ROW_COUNT, leds, LIGHT_PIN, lightDetection);

    if (digitalRead(DEBUG_MODE_PIN) == 1)
    {
        Serial.println("Go to debug...");
        workingMode = new WorkingModeDebug(workingValues);
    }
    else
    {
        Serial.println("Normal mode...");
        workingMode = new WorkingModeStart(workingValues);
    }

    workingValues->setAllLeds(CRGB::Black);
    FastLED.show();
}

void loop()
{
    bool debugLed = true;
    while (true)
    {
        lightDetection->doDetection();

        WorkingMode *old = workingMode;
        workingMode = workingMode->Run();

        FastLED.show();
        digitalWrite(13, debugLed);
        debugLed = !debugLed;

        if (old != workingMode)
        {
            Serial.println("Switch mode");
            delete old;
        }
        else
        {
            FastLED.delay(workingMode->getDelay());
        }
    }
}