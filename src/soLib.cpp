
#include <cmath>

#include "aconv.h"
#include "proc.h"
#include "singl.h"

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


class s_sample : public singl {
public:
    s_sample(long val, aOut* t_aout);
    ~s_sample();

    void proc();

protected:
    long val;
    aOut* aout;
};

#ifdef __cplusplus
}
#endif

p_playSine::p_playSine(double freq, unsigned long length) {
    N = length;
    bitdepth = std::pow(2, BITDEPTH);
    data = new long[N];
    for(unsigned long n=0; n<N; ++n) 
        data[n] = (long)(std::sin((M_PI+M_PI) * freq * n / FS) * bitdepth);


};

void p_playSine::add() {
    
};

void p_playSine::remove() {

};
