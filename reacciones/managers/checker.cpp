#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int wrong_ans() {
  cout << "0.0\n";
  return 0;
}

int right_ans() {
  cout << "1.0\n";
  return 0;
}

int main(int argc, char *argv[]) {
  ifstream fin;   // Input
  ifstream fcorr; // Expected
  ifstream ftest; // Submission

  fin.open(argv[1]);
  fcorr.open(argv[2]);
  ftest.open(argv[3]);

  if (argc < 4) {
    cerr << "Missing parameter. Please contact contest administrator.\n";
    return -1;
  }

  if (!fin.is_open()) {
    cerr << "Could not open file \"" << argv[1]
         << "\". Please contact contest administrator.\n";
    return 1;
  }

  if (!fcorr.is_open()) {
    cerr << "Could not open file \"" << argv[2]
         << "\". Please contact contest administrator.\n";
    return 2;
   }

  if (!ftest.is_open()) {
    cerr << "Could not open file \"" << argv[3]
         << "\". Please contact contest administrator.\n";
    return 3;
  }

  int n, k;
  string message;

  // Read input
  fin >> n >> k;
  fin >> message;

  // Read expected
  string expected;
  getline(fcorr, expected);

  // Read submission
  string submission;
  getline(ftest, submission);

  if (expected == "imposible") {
    return (submission == "imposible") ? right_ans() : wrong_ans();
  }

  vector<vector<bool>> usages(26, vector<bool>(k));

  istringstream iss(submission);
  int color;

  for (int i = 0; i < n; ++i) {
    iss >> color;
    if (usages[message[i] - 'a'][color - 1]) {
      return wrong_ans();
    }
    usages[message[i] - 'a'][color - 1] = true;
  }

  return right_ans();
}
