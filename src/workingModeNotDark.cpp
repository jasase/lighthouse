#include "workingMode.h"


int WorkingModeNotDark::getDelay() {
    return 30000; //Wait 30 seconds for next check
}

WorkingMode* WorkingModeNotDark::Run() {


    return this;
}