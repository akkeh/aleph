/*
    Outputs
*/

#include "aconv.h"


class aOut {
public:
    aOut();
    ~aOut();

protected:
    long* buf;          // buffer
    unsigned long N;    // buffer length
    unsigned long chnn; // number of channels
    //unsigned long wp;    // write pointer

};

//-offline ----------------------------------------------------|
class file_aO : public aOut {
    // collect all samples in buffer and write to file
public:
    file_aO();
    ~file_aO();
    void add_sample(long sample, unsigned long n);
};

//-online -----------------------------------------------------|
class libao_aO : public aOut {
    // 'fire' after buf is filled
public:
    libao_aO();
    ~libao_aO();

    void add_sample(long sample, unsigned long n);

private:
    unsigned long n0;   // start time of current buffer
};
