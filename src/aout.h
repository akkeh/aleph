/*
    Outputs
*/

#include "aconv.h"


class aOut {
public:
    aOut();
    ~aOut();
    void add_sample(long sample);

private:
    long* buf;          // buffer
    unsigned long N;    // buffer length
    unsigned long n;    // write pointer
};


class offline_aO : public aOut {
    // collect all samples in buffer and ask to save afterwards
};

class libao_aO : public aOut {
    // 'fire' after buf is filled

};
