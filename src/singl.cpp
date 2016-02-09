#include <iostream>

#include "aconv.h"
#include "atime.h"
#include "singl.h"
#include "aout.h"


//- Singl: ----------------------------------------------------|
Singl::Singl(unsigned long t_t0){
    t0 = t_t0;
    prev = next = NULL;
};

Singl::~Singl() {
    if(prev) prev->set_next(next);
    if(next) next->set_prev(prev);
}

Singl* Singl::add(Singl* newSingl, int dir) {
    const unsigned long new_t0 = newSingl->get_time();

    if(dir == 0) {
        if(new_t0 < t0)
            add(newSingl, -1);
        else
            add(newSingl, 1);
    } else {
        if(dir == 1) {
            if(next)
                next->add(newSingl, 1);
            else
                append(newSingl);
        } else if(dir == -1) {
                if(prev)
                    prev->add(newSingl, -1);
                else
                    prepend(newSingl);
        } else {
            // $TODO$: trow error
            std::cout << "trow error!\n";
        }
    };
};

unsigned long Singl::get_time() {
    return t0;
};

void Singl::prepend(Singl* newSingl) {
    newSingl->set_prev(prev);
    newSingl->set_next(this);
    
    prev = newSingl;
};

void Singl::append(Singl* newSingl) {
    newSingl->set_next(next);
    newSingl->set_prev(this);
    
    next = newSingl;
};

Singl* Singl::set_prev(Singl* new_prev) {
    Singl* old_prev = prev;
    prev = new_prev;
    return old_prev;
};

Singl* Singl::set_next(Singl* new_next) {
    Singl* old_next = next;
    next = new_next;
    return old_next;
};

Singl* Singl::get_prev() {
    return prev;
};

Singl* Singl::get_next() {
    return next;
};

int Singl::process(Time* t) {
    unsigned long n = t->update();
    while(t0 > n) 
        n = t->update();

        proc(); 

    if(next)
        next->process(t);
    return 0;
};

/*
void Singl::add(int argc, void** argv) {
    std::cout << "got " << argc << "arguments\n";
};
*/

//-------------------------------------------------------------|
//- sample: ---------------------------------------------------|
sample::sample(unsigned long t_t0, long* t_val, aOut* t_aout) : Singl(t_t0) {
    val = new long[CHNN];    
    for(unsigned long c=0; c<CHNN; ++c) {
        val[c] = t_val[c];
    }
    aout = t_aout;
};

void sample::proc() {
    aout->add(t0, val);
};
