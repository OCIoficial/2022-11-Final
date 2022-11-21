#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> counts(26);

  int n, k;
  string message;

  cin >> n >> k;
  cin >> message;

  vector<int> output(n);

  for (int i = 0; i < n; ++i) {
    char c = message[i];

    if (++counts[c - 'a'] > k) {
      cout << "imposible" << endl;
      return 0;
    }

    output[i] = counts[c - 'a'];
  }

  for (int i = 0; i < n; ++i) {
    cout << output[i];
    if (i == n - 1) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}
