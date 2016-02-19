#include <iostream>

#include "aconv.h"
#include "atime.h"
#include "singl.h"
#include "aout.h"


//- Singl: ----------------------------------------------------|
Singl::Singl(unsigned long t_t0, int argc, void** argv){
    t0 = t_t0;
    prev = next = sub = nsub = psub = NULL;
};

Singl::~Singl() {
    if(prev) prev->set_next(next);
    while(sub) {
        Singl* next_sub = sub->get_nsub();
        delete sub;
        sub = next_sub;
    };
    if(next) next->set_prev(prev);
}

void Singl::removeFromList() {
    if(prev) prev->set_next(next);
    if(next) next->set_prev(prev);
    prev = next = NULL;
};

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
};  // Singl::add();

Singl* Singl::add_sub(Singl* newSub, int dir) {
    const unsigned long new_t0 = newSub->get_time();

    if(dir == 0) {
        if(new_t0 < t0)
            add_sub(newSub, -1);
        else
            add_sub(newSub, 1);
    } else {
        if(dir == 1) {
            if(nsub)
                nsub->add_sub(newSub, 1);
            else
                append_sub(newSub);
        } else if(dir == -1) {
                if(psub)
                    psub->add_sub(newSub, -1);
                else
                    prepend_sub(newSub);
        } else {
            // $TODO$: trow error
            std::cout << "trow error!\n";
        }
    };
};

void Singl::readdSubs() {
    if(sub) {
        Singl* s = sub;
        while(s) {
            s->removeFromList();
            this->add(s);
            s = s->get_nsub();
        };
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

void Singl::prepend_sub(Singl* newSub) {
    newSub->set_psub(psub);
    newSub->set_nsub(this);
    psub = newSub;
};

void Singl::append(Singl* newSingl) {
    newSingl->set_next(next);
    newSingl->set_prev(this);
    
    next = newSingl;
};

void Singl::append_sub(Singl* newSub) {
    newSub->set_nsub(nsub);
    newSub->set_psub(this);
    
   nsub = newSub;
};

Singl* Singl::set_prev(Singl* new_prev) {
    Singl* old_prev = prev;
    prev = new_prev;
    return old_prev;
};

Singl* Singl::set_psub(Singl* new_psub) {
    Singl* old_psub = psub;
    psub = new_psub;
    return old_psub;
};

Singl* Singl::set_next(Singl* new_next) {
    Singl* old_next = next;
    next = new_next;
    return old_next;
};

Singl* Singl::set_nsub(Singl* new_nsub) {
    Singl* old_nsub = nsub;
    nsub = new_nsub;
    return old_nsub;
};

Singl* Singl::get_prev() {
    return prev;
};

Singl* Singl::get_psub() {
    return psub;
};

Singl* Singl::get_next() {
    return next;
};

Singl* Singl::get_nsub() {
    return nsub;
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

//-------------------------------------------------------------|
//- Sample: ---------------------------------------------------|
//Sample::Sample(unsigned long t_t0, long* t_val, aOut* t_aout) : Singl(t_t0, 0, NULL) {
Sample::Sample(unsigned long t_t0, int argc, void** argv) : Singl(t_t0, 0, NULL) {
    if(argc < 2) {
        // $TODO: throw error
        std::cout << "throw error\n";
    } else {
        val = (long*) argv[0];
        aout = (aOut*) argv[1];
    };
};

void Sample::proc() {
    aout->add(t0, val);
};
