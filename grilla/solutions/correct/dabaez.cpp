#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
bool valid(int i,int j,int n,int m){
    return 0<=i && i<n && 0<=j && j<m;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    cin>>n>>m>>k;
    vector< vector<int> > gri(n, vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>gri[i][j];
        }
    }
    vector< vector<int> > d(n,vector<int>(m,-1));
    d[0][0] = 0;
    queue<ii> bfs;
    bfs.push(ii(0,0));
    while (!bfs.empty()){
        ii no = bfs.front();
        bfs.pop();
        for (int i=0;i<4;i++){
            int ni = no.first + dx[i];
            int nj = no.second + dy[i];
            if (valid(ni,nj,n,m) && d[ni][nj] == -1 && gri[ni][nj] != gri[no.first][no.second]){
                d[ni][nj] = d[no.first][no.second] + 1;
                bfs.push(ii(ni,nj));
            }
        }
    }
    cout<<d[n-1][m-1]<<'\n';
    return 0;
}