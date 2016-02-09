#include <iostream>
#include <cmath>

#include "aconv.h"


int main() {
    aOut* output = new file_aO();

    sample** samples = new sample*[100];
    for(unsigned long n=0; n<100; ++n) {
        long* vals = new long[CHNN];
        for(unsigned int c=0; c<CHNN; ++c)
             vals[c] = (long)(std::sin((M_PI+M_PI) * (double)n / 44100.0) * 1000);
        samples[n] = new sample(n, vals, output);
        if(n > 0)
            samples[n-1]->add(samples[n]);
    };
    
    Time* t = new Time(1);
    samples[0]->process(t);

    ((file_aO*)output)->write("test", 40, 55);
    std::cout << "succes\n";
};
