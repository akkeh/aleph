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

    std::string soLibName = "./soLib.so";
    load:
    std::cout << "Path to shared object file: $ ";
    if(soLibName.empty())
        std::cin >> soLibName;
    else
        std::cout << soLibName << std::endl;
    std::cout << "loading: " << soLibName << std::endl;   
    void* soHandle = dlopen(soLibName.c_str(), RTLD_NOW);
    if(!soHandle) {
        std::cerr << "\nlib: " << soLibName << " could not be opened: " << dlerror() << std::endl;
        soLibName.clear();
        goto load;
    }    
    dlerror();  // flush errors
    const char* dlerr;
    
    Singl_constr constr = (Singl_constr) dlsym(soHandle, "con_printName");
    
    void** argv = new void*[2];
    unsigned long N = 10;
    const char* name = "test";
    argv[0] = (void*) &N;
    argv[1] = (void*) name;

    std::cout << "constructing\n";
    Singl* pName = constr(0, 2, argv);
    Time* t = new Time(0);
    // samples[0]->process(t);
    Singl* s = pName;
    while(s) {
        std::cout << "next: " << s->get_time() << std::endl;
        s = s->get_next();
    }
    
    void** argv2 = new void*[2];
    unsigned long N2 = 2;
    const char* name2 = "test2";
    argv2[0] = (void*) &N2;
    argv2[1] = (void*) name2;
    Singl* pName2 = constr(5, 2, argv2); 

    pName->readdSubs();
    pName->add(pName2);
    pName->readdSubs();
    pName2->readdSubs();

    Singl* n = pName;
    while(n) {
        std::cout << "n: " << n->get_time() << std::endl;
        n = n->get_next();
    }; 
    
    pName->process(t);

    ((file_aO*)output)->write("test", 0, 10);
    std::cout << "succes\n";
    delete output;
    delete pName;
};
