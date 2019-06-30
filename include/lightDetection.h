#ifndef LIGHT_DETECTION_H
#define LIGHT_DETECTION_H

#define BUFFER_LENGTH 30
#define READ_PER_RUN 10

#include <CircularBuffer.h>
#include "Arduino.h"
#include "modeSelector.h"

class LightDetection {
    public: 
        LightDetection(int pin, ModeSelector* modeSelector);
        void doDetection();
        bool isDark();
        float getValue();
    private:    
        float calculateAverage();    
        CircularBuffer<int,BUFFER_LENGTH * READ_PER_RUN> _values;
        unsigned long _lastReadTimestamp;
        int _pin;        
        ModeSelector* _modeSelector;
};

#endif