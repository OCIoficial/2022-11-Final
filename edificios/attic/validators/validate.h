#include "testlib.h"
#include <unordered_set>
using namespace std;

void validate(int maxN, int maxM) {
  int N = inf.readInt(2, maxN, "N");
  inf.readSpace();
  int M = inf.readInt(2, maxM, "M");
  inf.readEoln();
  for (int i = 0; i < N; i++) {
    int P = inf.readInt(1, M, "P");
    unordered_set<int> set;
    for (int j = 0; j < P; j++) {
      inf.readSpace();
      int p = inf.readInt(0, M, "p");
      ensure(set.count(p) == 0);
      set.insert(p);
    }
    if (i == 0) {
      ensure(set.count(M - 1));
    }
    inf.readEoln();
  }
  inf.readEof();
}
