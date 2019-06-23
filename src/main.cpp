#include "Arduino.h"
#include "workingMode.h"


#define DATA_PIN_WS2812 1

WorkingMode* workingMode;

void setup() {
    pinMode(DATA_PIN_WS2812, OUTPUT);
    workingMode = new WorkingModeNotDark();
}

void loop() {    
    while(true) {        
        workingMode = workingMode->Run();
        delay(workingMode->getDelay());
    }
}