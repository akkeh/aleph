#include <cmath>
#include <iostream>

#include "aconv.h"
#include "singl.h"

#define so_simpleSine_ARGCOUNT 3

#ifdef __cplusplus
extern "C" {
#endif

class s_simpleSine : public Singl {
public:
    s_simpleSine(unsigned long t0, int argc, void** argv);
    void proc();
};

s_simpleSine* con_simpleSine(unsigned long t0, int argc, void** argv) {
    return new s_simpleSine(t0, argc, argv);
};
void des_simpleSine(s_simpleSine* obj) {
    delete obj;
};

#ifdef __cplusplus
}
#endif

s_simpleSine::s_simpleSine(unsigned long t0, int argc, void** argv) : Singl(t0, 0, NULL) {
    if(argc < so_simpleSine_ARGCOUNT) {
        // $TODO: throw error:
        std::cout << "throw error\n";
    } else {
        unsigned long N = *((unsigned long*) argv[0]);
        std::cout << "N: " << N << std::endl;
        double freq = *((double*) argv[1]);
        std::cout << "freq: " << freq << std::endl;
        aOut* aout = (aOut*) argv[2];
        for(unsigned long n=0; n<N; ++n) {
            std::cout << "sample: " << n << " / " << N << std::endl;
            void** nargv = new void*[2];
            
            long* val = new long[CHNN];
            for(unsigned long c=0; c<CHNN; ++c)
                val[c] = (long)std::sin((M_PI+M_PI) * freq * (long double)n / (long double)FS);
            nargv[0] = val;
            nargv[1] = argv[2];
            std::cout << "sending to sample\n";
            Sample* sample = new Sample(t0+n, 2, argv);
            if(n == 0) {
                next = sample;
                sub = sample;
            } else {
                this->add(sample);
                sub->add_sub(sample);
            };
        };     
        std::cout << "constructed\n";
    };   
};

void s_simpleSine::proc() {
     
};
