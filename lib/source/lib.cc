#include <iostream>

using namespace std;

#include "lib.hh"

void sayHello(void) {
    constexpr msg = R"__(Hello, world!)__";
    cout << msg << endl;
}
