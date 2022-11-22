#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &grid[i][j]);
    }
  }

  pair<int, int> dirs[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  queue<pair<int, int>> q;
  vector<vector<int>> dist(n, vector<int>(m, -1));
  dist[0][0] = 0;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (auto [di, dj] : dirs) {
      int vi = i + di;
      int vj = j + dj;
      if (vi < 0 || n <= vi || vj < 0 || m <= vj || grid[i][j] == grid[vi][vj])
        continue;
      if (dist[vi][vj] == -1) {
        q.emplace(vi, vj);
        dist[vi][vj] = dist[i][j] + 1;
      }
    }
  }

  printf("%d\n", dist[n - 1][m - 1]);
}
