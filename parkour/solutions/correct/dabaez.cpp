#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector< vector<ii> > p(n);
    for (int i=0;i<n;i++){
        int P;
        cin>>P;
        p[i].resize(P);
        for (int j=0;j<P;j++){
            cin>>p[i][j].first;
            p[i][j].second = 1e5;
        }
    }
    p[0] = {ii(m-1,0)};
    for (int i=0;i<n-1;i++){
        for (int j=0;j<p[i].size();j++){
            for (int k=0;k<p[i+1].size();k++){
                if (p[i][j].first >=  p[i+1][k].first) p[i+1][k].second = min(p[i+1][k].second,p[i][j].second);
                else p[i+1][k].second = min(p[i+1][k].second , p[i][j].second + p[i+1][k].first - p[i][j].first );
            }
        }
    }
    int ans = 1e5;
    for (int i=0;i<p[n-1].size();i++) ans = min(ans,p[n-1][i].second);
    cout<<ans<<'\n';
    return 0;
}
