#ifndef PROC_H_
#define PROC_H_

#include "aconv.h"

class proc {
public:
    proc();
    ~proc();
    void func(void** argv);

protected:
    void** argv;
    int argc;

};

#endif
