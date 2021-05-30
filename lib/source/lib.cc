#include <iostream>

using namespace std;

#include "lib.h"

void sayHello(void) {
  constexpr auto msg = R"__(Hello, world!)__";
  cout << msg << endl;
}
