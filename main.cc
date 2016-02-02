#include<iostream>
#include "testGdb.h"


int main(void) {
    Stupid *sp = new Stupid(5);

    int ret = sp->DoMath();

    std::cout << "math: " << ret << std::endl;
}

