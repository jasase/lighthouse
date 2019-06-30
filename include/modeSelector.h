#ifndef MODE_SELECTOR_H
#define MODE_SELECTOR_H

#define MODE_SELECTOR_PIN_COUNTER 6

class ModeSelector {
    public:
        ModeSelector(int pins[MODE_SELECTOR_PIN_COUNTER]);
        bool isLightOverrideActive();
        bool isDebugModeActive();
        bool isMovingLightModeActive();
        bool isFlashLightModeActive();
    private:
        int _pins[MODE_SELECTOR_PIN_COUNTER];
        int getCurrentValue();
};

#endif