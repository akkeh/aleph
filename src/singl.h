#ifndef SINGL_H_
#define SINGL_H_

/*
    Singularity, a singular point, a point of exception. Both an ending and a new beginning.
*/

#include "aconv.h"


class Singl {
public:
    Singl(unsigned long t_t0);
    ~Singl();
     
    int process(Time* t);
    unsigned long get_time();  

    // linked list functions:
    Singl* add(Singl* singl, int dir=0); 
    void prepend(Singl* singl); 
    void append(Singl* singl); 
    Singl* set_prev(Singl* new_prev);
    Singl* set_next(Singl* new_next);
    Singl* get_prev();
    Singl* get_next();

protected:
    unsigned long t0;   // start-time

    // linked list stuff:
    Singl* prev;
    Singl* next;
    
}; 
#endif
