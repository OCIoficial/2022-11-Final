#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int N = inf.readInt(1, 1000000, "N");
  inf.readSpace();
  int K = inf.readInt(2, 2, "K");
  ensure(N >= K);
  inf.readEoln();
  for (int i = 0; i < N; i++) {
    char c = inf.readChar();
    ensure(c >= 'a' && c <= 'z');
  }
  inf.readEoln();
  inf.readEof();
}
