#ifndef ATIME_H_
#define ATIME_H_

#include <ctime>

#include "aconv.h"

class Clock {
public:
    virtual unsigned long update() = 0;
    unsigned long n;
};

class sampleClock : public Clock {
public:
    unsigned long update();

    sampleClock();
};

class cpuClock : public Clock {
public:
    unsigned long update();

    cpuClock();
    ~cpuClock();
private:
    clock_t t;
    unsigned long t0;   // creation time
};


class Time{
/*
    mode 0: offline (render)
    mode 1: online (ctime CPU clock)
*/    
Time(int t_mode);
~Time();
unsigned long update();

private:
    unsigned long t0;   // creation time
    
     
    int mode;
    Clock* n;
};

#endif
