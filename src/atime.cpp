#include <ctime>
#include <iostream>

#include "atime.h"
/*
    mode 0: offline (render)
    mode 1: online (ctime)
*/    

Time::Time(int t_mode) {
    mode = t_mode;
};


unsigned long Time::update() {
    
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


int main() {
    Clock* C = new sampleClock();
    unsigned long n = 0;
    clock_t t0 = clock();
    while(n < 44100) {
        n = C->update();
        std::cout << "t: " << n << std::endl;
    }
    std::cout << "dt: " << ((long double)(clock() - t0)) / CLOCKS_PER_SEC << std::endl;

};
