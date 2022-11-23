#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

const int INF = 1e9;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector <vector <int>> mat(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
	queue<pair<int,int>> q;
	vector <vector <int>> dist(n, vector<int>(m, INF));
	dist[0][0] = 0;
	q.push({0, 0});
	const int dx[] = {1, -1, 0, 0};
	const int dy[] = {0, 0, 1, -1};
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		for(int d=0; d<4; d++){
			int nx = x+dx[d];
			int ny = y+dy[d];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || dist[nx][ny] < INF || mat[x][y] == mat[nx][ny]) continue;
			q.push({nx,ny});
			dist[nx][ny] = dist[x][y]+1;
		}
	}
	cout << (dist[n-1][m-1] >= INF ? -1 : dist[n-1][m-1]) << '\n';
	return 0;
}
