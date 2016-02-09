#include <iostream>

#include "aconv.h"


int main() {

    sample e1(44100, -1, new aOut());
    sample e2(50000, 1, new aOut());
    
    e1.append(&e2);
    Time* t = new Time(1);
    e1.process(t);
    
    std::cout << "succes\n";
};
