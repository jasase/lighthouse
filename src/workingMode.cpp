#include "workingMode.h"

WorkingMode::WorkingMode(WorkingValues *workingValues)
{
    this->_workingValues = workingValues;    
}

WorkingMode::~WorkingMode() {}

WorkingValues *WorkingMode::getWorkingValues()
{
    return this->_workingValues;
}
