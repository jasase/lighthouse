#ifndef WORKING_MODE_H
#define WORKING_MODE_H

#include "workingValues.h"

#define LAST_LIGHT_ARRAY_LENGTH 6

class WorkingMode
{
public:
    WorkingMode(WorkingValues *workingValues);
    virtual int getDelay();
    virtual WorkingMode *Run();

protected:
    WorkingValues *getWorkingValues();
    int getAverageOfLight();
private:
    WorkingValues *_workingValues;
    int lastLightValues[LAST_LIGHT_ARRAY_LENGTH];
    int currentValueCounter;
};

class WorkingModeNotDark : public WorkingMode
{
public:
    WorkingModeNotDark(WorkingValues *workingValues);
    int getDelay();
    WorkingMode *Run();

private:
};

class WorkingModeOnMovingLight : public WorkingMode
{
public:
    WorkingModeOnMovingLight(WorkingValues *workingValues);
    int getDelay();
    WorkingMode *Run();

private:
};

#endif