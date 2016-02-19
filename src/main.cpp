#include <string.h>
#include <iostream>
#include <cmath>
#include <dlfcn.h>

#include "aconv.h"
#include "singl.h"

int main() {
    aOut* output = new file_aO();
    /*
    sample** samples = new sample*[100];
    for(unsigned long n=0; n<100; ++n) {
        long* vals = new long[CHNN];
        for(unsigned int c=0; c<CHNN; ++c)
             vals[c] = (long)(std::sin((M_PI+M_PI) * (double)n / 44100.0) * 1000);
        samples[n] = new sample(n, vals, output);
        if(n > 0)
            samples[n-1]->add(samples[n]);
    };
    */

    std::string soLibName;
    load:
    std::cout << "Path to shared object file: $ ";
    std::cin >> soLibName;
    std::cout << "loading: " << soLibName << std::endl;   
    void* soHandle = dlopen(soLibName.c_str(), RTLD_NOW);
    if(!soHandle) {
        std::cerr << "\nlib: " << soLibName << " could not be opened: " << dlerror() << std::endl;
        soLibName.clear();
        goto load;
    }    
    dlerror();  // flush errors
    const char* dlerr;
    
    Singl_constr constr = (Singl_constr) dlsym(soHandle, "con_simpleSine"); 
    
    void** argv = new void*[3];
    unsigned long N = 10;
    double freq = 200;
    argv[0] = (void*) &N;
    argv[1] = (void*) &freq;
    argv[2] = (void*) output;

    std::cout << "constructing\n";
    Singl* sine = constr(0, 3, argv);
    Time* t = new Time(1);
    // samples[0]->process(t);
    sine->process(t);

    //((file_aO*)output)->write("test", 40, 55);
    std::cout << "succes\n";
};
