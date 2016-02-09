
#include <cmath>

#include "aconv.h"
#include "proc.h"
#include "singl.h"

#define so_playSine_ARGCOUNT 2

#ifdef __cplusplus
extern "C" {
#endif

class p_playSine : public proc {
    p_playSine(double freq, unsigned long length);

    void add(); // add singl
     
    void remove();  // remove singl

protected:
    // stuff for the sine:
    long* data;    // buffer to hold the data
    unsigned long N;
    int bitdepth;
};


#ifdef __cplusplus
}
#endif

p_playSine::p_playSine() {
    bitdepth = std::pow(2, BITDEPTH);
};

void p_playSine::add(int argc, void** argv) {
    /*
        [N, freq]
            variable sinus dmv bus in argv?
    */
    if(argc < so_playSine_ARGCOUNT) {
        return -1;
    };
    N = (unsigned long) argv[0];
    double freq = (double) argv[1];
    data = new long[N];
    for(unsigned long n=0; n<N; ++n) 
        data[n] = (long)(std::sin((M_PI+M_PI) * freq * n / FS) * bitdepth);
};

void p_playSine::remove() {

};
