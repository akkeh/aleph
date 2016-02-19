#include <cmath>
#include <iostream>

#include "aconv.h"
#include "singl.h"

#define so_printName_ARGCOUNT 2

#ifdef __cplusplus
extern "C" {
#endif

class s_printName : public Singl {
public:
    s_printName(unsigned long t0, int argc, void** argv);
    void addSubs();
    void proc();
private:
    unsigned long N;
    int argc;
    void** argv;
    char* name;
};

s_printName* con_printName(unsigned long t0, int argc, void** argv) {
    return new s_printName(t0, argc, argv);
};
void des_printName(s_printName* obj) {
    delete obj;
};

#ifdef __cplusplus
}
#endif

void s_printName::addSubs() {
    for(unsigned long n=0; n<N; ++n) {
        void** nargv = new void*[2];            
        unsigned long i = 0;
        nargv[0] = (void*) &i;
        nargv[1] = argv[1];
        Singl* print = new s_printName(t0+n, 2, nargv);
        if(n == 0) {
            sub = print;
        } else {
            sub->add_sub(print);
        };
    };     


}

s_printName::s_printName(unsigned long t0, int argc, void** argv) : Singl(t0, 0, NULL) {
    if(argc < so_printName_ARGCOUNT) {
        // $TODO: throw error:
        std::cout << "throw error\n";
    } else {
        N = *((unsigned long*) argv[0]);
        this->argc = argc;
        this->argv = argv;
        name = (char*) argv[1];
        
        addSubs();
       std::cout << "constructed\n";
    };   
};

void s_printName::proc() {
    std::cout << "printName: " << name << " (t: " << this->get_time() << "\n";
};
