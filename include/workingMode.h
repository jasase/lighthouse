#ifndef WORKING_MODE_H
#define WORKING_MODE_H

class WorkingMode {
    public:
        virtual int getDelay();
        virtual WorkingMode* Run();
};

class WorkingModeNotDark : public WorkingMode {
    public:
        int getDelay();
        WorkingMode* Run();
};


#endif