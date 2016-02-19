#include <iostream>

#include "aconv.h"
#include "aout.h"



aOut::aOut() {
};

aOut::~aOut() {
};

void aOut::add(unsigned long n, long* val) {
    std::cout << "y[" << n << "] = " << val << std::endl;
};


// file_aO ----------------------------------------------------|
file_aO::file_aO() {
    std::cout << "Initialising output buffer....\n";
    N = OFFLINE_BUFN;
    chnn = CHNN;
    buf = new long[OFFLINE_BUFN * CHNN];
    for(unsigned long n=0; n<N * chnn; ++n)
        buf[n] = 0; // initialise buffer to zeros
};

file_aO::~file_aO() {
    delete[] buf;
};

void file_aO::add(unsigned long n, long* val) {
    for(unsigned int c=0; c<chnn; ++c)
        buf[n * chnn + c] += val[c];
};

int file_aO::write(const char* filename, unsigned long t0, unsigned long t1) {
     for(unsigned long n=t0; n<t1; ++n) {
         std::cout << "y[" << n << "]: ";
        for(unsigned int c=0; c<chnn; c++)
            std::cout << buf[n * chnn + c] << ", ";
        std::cout << std::endl;
    };
};

// libao_aO ----------------------------------------------------|

