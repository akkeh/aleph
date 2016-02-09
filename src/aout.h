#ifndef AOUT_H_
#define AOUT_H_

/*
    Outputs
*/
#include "aconv.h"

class aOut {    // dummy output
public:
    aOut();
    ~aOut();

    virtual void add(unsigned long t, long* val);    // add sample

protected:
    long* buf;          // buffer
    unsigned long N;    // buffer length
    unsigned long chnn; // number of channels
    //unsigned long wp;    // write pointer

};  // aOut

//-offline ----------------------------------------------------|
class file_aO : public aOut {
    // collect all samples in buffer and write to file
public:
    file_aO();
    ~file_aO();

    void add(unsigned long n, long* val);
    int write(const char* filename, unsigned long t0, unsigned long t1);
};  // file_aO

//-online -----------------------------------------------------|
class libao_aO : public aOut {
    // 'fire' after buf is filled
public:
    libao_aO();
    ~libao_aO();


private:
    unsigned long n0;   // start time of current buffer
};  // libao_aO

#endif  // AOUT_H_
