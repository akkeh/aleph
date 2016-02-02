#include "aconv.h"

#ifdef __cplusplus
extern "C" {
#endif

class proc_playSine : public proc {
    proc_playSine(double freq);

    void proc();
     
    void remove();

protected:
    long* soundfile;
    unsigned long N;
    int bitdepth;
};


#ifdef __cplusplus
}
#endif

proc_playSine::proc_playSine(char* filename) {
      
 
    // create sub-singl.    
};

void proc_playSound::proc() {
    
};

void proc_playSound::remove() {

};
