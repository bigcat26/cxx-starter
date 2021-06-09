#include <iostream>

using namespace std;

#include "lib.h"

void sayHello(void) {
  constexpr auto msg = R"__(
    Hello, first line!
    Hello, second line!
  )__";
  cout << msg << endl;
}
