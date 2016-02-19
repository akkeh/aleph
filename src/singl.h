#ifndef SINGL_H_
#define SINGL_H_

/*
    Singularity, a singular point, a point of exception. Both an ending and a new beginning.
*/

#include "aconv.h"


class Singl {
public:
    Singl(unsigned long t_t0, int argc, void** argv);
    ~Singl();
     
    int process(Time* t);

    virtual void proc() = 0;                    // t0
    // virtual void add(int argc, void** argv)= 0; // 'creation' time
    
    unsigned long get_time();  

    // linked list functions:
    Singl* add(Singl* newSingl, int dir=0); 
    void prepend(Singl* newSingl); 
    void append(Singl* newSingl); 
    Singl* set_prev(Singl* new_prev);
    Singl* set_next(Singl* new_next);
    Singl* get_prev();
    Singl* get_next();
    // sub singularities:
    Singl* add_sub(Singl* newSub, int dir=0);
    void prepend_sub(Singl* newSub); 
    void append_sub(Singl* newSub); 
    Singl* set_psub(Singl* new_psub);
    Singl* set_nsub(Singl* new_nsub);
    Singl* get_nsub();
    Singl* get_psub();
    void readdSubs();
    void removeFromList();

protected:
    unsigned long t0;   // start-time

    // linked list stuff:
    Singl* prev;
    Singl* next;
    // sub singularities:    
    Singl* sub;
    Singl* psub;
    Singl* nsub;
}; 

class Sample : public Singl {
public:
    //Sample(unsigned long t_t0, long* val, aOut* aout);
    Sample(unsigned long t_t0, int argc, void** argv);
    void proc(); 
private:
    long* val;
    aOut* aout;

};


// typedefs:
typedef Singl* (*Singl_constr)(unsigned long t0, int argc, void** argv);
typedef void (*Singl_destr)(Singl* singl);

#endif
