#include "Arduino.h"
#include "FastLED.h"

#include "workingMode.h"
#include "workingValues.h"
#include "lightDetection.h"

#define DATA_PIN_WS2812 12 //PD0

#define LIGHT_PIN 7

#define LED_COLUMN_COUNT 23
#define LED_ROW_COUNT 3

WorkingMode *workingMode;
WorkingValues *workingValues;
LightDetection *lightDetection;
ModeSelector *modeSelector;

CRGB leds[LED_COLUMN_COUNT * LED_ROW_COUNT];
int mode_selector_pins[MODE_SELECTOR_PIN_COUNTER];

void setup()
{
    Serial.begin(9600);

    mode_selector_pins[0] = 7;
    mode_selector_pins[1] = 6;
    mode_selector_pins[2] = 5;
    mode_selector_pins[3] = 4;
    mode_selector_pins[4] = 3;
    mode_selector_pins[5] = 2;

    pinMode(DATA_PIN_WS2812, OUTPUT);

    pinMode(13, OUTPUT);

    FastLED.addLeds<NEOPIXEL, DATA_PIN_WS2812>(leds, LED_COLUMN_COUNT * LED_ROW_COUNT);


    modeSelector = new ModeSelector(mode_selector_pins);
    lightDetection = new LightDetection(LIGHT_PIN, modeSelector);
    workingValues = new WorkingValues(LED_COLUMN_COUNT, LED_ROW_COUNT, leds, lightDetection, modeSelector);

    if (modeSelector->isDebugModeActive())
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