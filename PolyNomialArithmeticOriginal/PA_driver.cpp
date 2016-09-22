#include <iostream>
#include "PA.h"
using namespace std;

int main(int argc, char *argv[]) {
    PA pa(argv[1]);
    pa.add();
    pa.mult();
    pa.diff();
    return 0;
}