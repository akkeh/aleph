#include <iostream>

#include "aconv.h"
#include "aout.h"



aOut::aOut() {
};

aOut::~aOut() {
};

void aOut::add(unsigned long n, long val) {
    std::cout << "y[" << n << "] = " << val << std::endl;
};

// file_aO ----------------------------------------------------|
file_aO::file_aO() {
    N = OFFLINE_BUFN;
    chnn = CHNN;
    buf = new long[OFFLINE_BUFN * CHNN];
    
    
};

file_aO::~file_aO() {
    delete[] buf;
};

void file_aO::add(unsigned long n, long val) {
    buf[n * chnn] += val;  
};


// libao_aO ----------------------------------------------------|

