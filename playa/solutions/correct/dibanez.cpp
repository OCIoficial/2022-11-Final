#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<int,int>> par;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    
    vector<vector<int>> mapa(n, vector<int>(m));

    for (auto &v: mapa)
        for (int &x:v)
            cin >> x;

    vector<vector<ll>> d(n, vector<ll>(m, 1e18));
    priority_queue<par, vector<par>, greater<par>> pq;
    d[0][0] = 0;
    pq.push({0,{0,0}});
    
    while (!pq.empty()) {
        auto [dist, p] = pq.top(); pq.pop();
        auto [x, y] = p;

        if (dist != d[x][y])
            continue;

        for (int dir = 0; dir < 4; ++dir) {
            if (x+dx[dir] < 0 || x+dx[dir] >= n || y+dy[dir] < 0 || y+dy[dir] >= m)
                continue;
            if (mapa[x][y] != mapa[x+dx[dir]][y+dy[dir]])
                if (dist + 1 < d[x+dx[dir]][y+dy[dir]]) {
                    pq.push({dist+1, {x+dx[dir], y+dy[dir]}});
                    d[x+dx[dir]][y+dy[dir]] = dist+1;
                }
        }
    }

    if (d[n-1][m-1] == 1e18)
        cout << -1 << '\n';
    else
        cout << d[n-1][m-1] << '\n';

}
