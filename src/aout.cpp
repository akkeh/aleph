


#include "aconv.h"
#include "aout.h"

aOut::aOut() {
};

aOut::~aOut() {
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

void file_aO::add_sample(long sample, unsigned long n) {
    buf[n * chnn] = sample;  
};

// libao_aO ----------------------------------------------------|

