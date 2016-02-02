#include <iostream>

#include "aconv.h"


int main() {
    Singl e1(44100);
    Singl e2(50000);
    
    e1.append(&e2);
    Time* t = new Time(1);
    e1.process(t);
    
    std::cout << "succes\n";
};
