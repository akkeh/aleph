#include "aconv.h"

#ifdef __cplusplus
extern "C" {
#endif

class proc_playSound : public proc {
    proc_playSound(char* filename);

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

proc_playSound::proc_playSound(char* filename) {
    // read soundfile
   
    // create sub-singl.    
};

void proc_playSound::proc() {
    
};

void proc_playSound::remove() {

};
