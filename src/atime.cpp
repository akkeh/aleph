#include <ctime>
#include <iostream>

#include "aconv.h"
#include "atime.h"
/*
    mode 0: offline (render)
    mode 1: online (ctime)
*/    

Time::Time(int t_mode) {
    mode = t_mode;
    switch(mode) {
        case 0: // offline:
            n = new sampleClock();
            break;
        case 1: // online
            n = new cpuClock();
            break;

    };
};

Time::~Time() {
    delete n;
};

unsigned long Time::update() {
    return n->update();
};


//-Clocks: ----------------------------------------------------|

// sampleClock:
sampleClock::sampleClock() {
    n = 0;
};

unsigned long sampleClock::update() {
    return n++;
};

// cpuClock:
cpuClock::cpuClock() {
    t0 = clock();
    n = 0;
};

unsigned long cpuClock::update() {
    return n + ((long double)(clock() - t0)) / CLOCKS_PER_SEC * FS;
};


