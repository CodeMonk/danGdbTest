
#include "testGdb.h"

int Stupid::square(int arg) {
    return arg*arg;
}

int Stupid::addOneAndSquare(int arg) {
    return square(arg+1);
}

int Stupid::DoMath() {
    return addOneAndSquare(data);
}
