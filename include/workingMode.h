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

class WorkingModeOn : public WorkingMode
{
public:
    WorkingModeOn(WorkingValues *workingValues);
    virtual int getDelay();
    virtual WorkingMode *Run();
    virtual ~WorkingModeOn();

protected:
    WorkingMode *workingModeSelection();
    virtual bool isCurrentMode();
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

class WorkingModeOnMovingLight : public WorkingModeOn
{
public:
    WorkingModeOnMovingLight(WorkingValues *workingValues);
    int getDelay();
    WorkingMode *Run();
    virtual ~WorkingModeOnMovingLight();

protected:
    bool isCurrentMode();

private:
    int columnCounter;
    void setColumnTo(int column, CRGB color);
};

class WorkingModeOnFlash : public WorkingModeOn
{
public:
    WorkingModeOnFlash(WorkingValues *workingValues);
    int getDelay();
    WorkingMode *Run();
    virtual ~WorkingModeOnFlash();

protected:
    bool isCurrentMode();

private:
    int _flashCounter;
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