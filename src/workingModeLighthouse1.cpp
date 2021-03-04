#include "workingMode.h"

CRGB positions [100] = {

//0
    CRGB::Green,
    CRGB::Green,    
    CRGB::Black,
    CRGB::Black,
    CRGB::Green,

//1    
    CRGB::Green,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,

//2    
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,

//3    
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Green,

//4   
    CRGB::Green,
    CRGB::Green,
    CRGB::Green,
    CRGB::Green,
    CRGB::Green,

//5    
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,

//6 
    CRGB::Red,
    CRGB::Red,
    CRGB::Red,
    CRGB::Red,
    CRGB::Red,

//7    
    CRGB::Red,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,

//7    
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,

//9    
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,

//10
    CRGB::Red,
    CRGB::Red,
    CRGB::Black,
    CRGB::Black,
    CRGB::Red,

//11    
    CRGB::Red,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
//12
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
//13  
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
//14  
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
//15  
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
//16  
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
//17  
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
//18  
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
//19  
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black,
    CRGB::Black

};

workingModeLighthouse1::workingModeLighthouse1(WorkingValues *workingValues)
    : WorkingModeOn(workingValues)
{ }

workingModeLighthouse1::~workingModeLighthouse1() {}

bool workingModeLighthouse1::isCurrentMode()
{
    return this->getWorkingValues()->getModeSelector()->isLighthouse1ModeActive();
}

int workingModeLighthouse1::getDelay()
{
    return 200;
}

WorkingMode *workingModeLighthouse1::Run()
{   
    Serial.print(this->_position);
    Serial.print(" - ");
    Serial.println(positions[this->_position]);
    this->getWorkingValues()->setAllLeds(positions[this->_position]);

    this->_position++;
    if(this->_position >= 100) {
        FastLED.setBrightness(255);
        this->_position = 0;
    }
    return this->workingModeSelection();
}


