#ifndef WORKING_MODE_H
#define WORKING_MODE_H

#include "workingValues.h"

class WorkingMode
{
public:
    WorkingMode(WorkingValues *workingValues);
    virtual int getDelay();
    virtual WorkingMode *Run();
    virtual ~WorkingMode();
    

protected:
    WorkingValues *getWorkingValues();
    int getAverageOfLight();    

private:
    WorkingValues *_workingValues;
};

class WorkingModeStart : public WorkingMode
{
public:
    WorkingModeStart(WorkingValues *workingValues);
    int getDelay();
    WorkingMode *Run();
    virtual ~WorkingModeStart();
private:
    int ledCoounter;
    void setIfMatching(int ledNumber, CRGB color);
};

class WorkingModeOff : public WorkingMode
{
public:
    WorkingModeOff(WorkingValues *workingValues);
    int getDelay();
    WorkingMode *Run();
    virtual ~WorkingModeOff();

private:
};

class WorkingModeOnMovingLight : public WorkingMode
{
public:
    WorkingModeOnMovingLight(WorkingValues *workingValues);
    int getDelay();
    WorkingMode *Run();
    virtual ~WorkingModeOnMovingLight();

private:
    int columnCounter;
    void setColumnTo(int column, CRGB color);
};

class WorkingModeDebug : public WorkingMode
{
public:
    WorkingModeDebug(WorkingValues *workingValues);
    int getDelay();
    WorkingMode *Run();
    virtual ~WorkingModeDebug();
private:
    CRGB pinToColor(int pin);
    CRGB boolToColor(bool value);
};

#endif