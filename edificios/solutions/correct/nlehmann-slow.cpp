#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

const int inf = 2000000000;
int main() {
  int N, M;
  scanf("%d%d", &N, &M);

  vector<vector<bool>> safe(N, vector<bool>(M, false));
  for (int i = 0; i < N; ++i) {
    int P;
    scanf("%d", &P);
    for (int j = 0; j < P; ++j) {
      int p;
      scanf("%d", &p);
      safe[i][p] = true;
    }
  }

  vector<vector<int>> dp(N, vector<int>(M, inf));
  dp[0][M - 1] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (safe[i][j]) {
        for (int k = 0; k < M; ++k) {
          dp[i][j] = min(dp[i - 1][k] + max(j - k, 0), dp[i][j]);
        }
      }
    }
  }
  int m = INT_MAX;
  for (int j = 0; j < M; ++j) {
    m = min(m, dp[N - 1][j]);
  }
  printf("%d\n", m);
  return 0;
}
