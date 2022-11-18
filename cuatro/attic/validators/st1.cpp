#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int N = inf.readInt(4, 10, "N");
  inf.readEoln();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; ++j) {
      char c = inf.readChar();
      ensure(c == '.' || c == 'O' || c == 'X');
    }
    inf.readEoln();
  }
  inf.readEof();
}
