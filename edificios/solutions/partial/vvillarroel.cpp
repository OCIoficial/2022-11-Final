#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> torres(n);
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        for (int j = 0; j < p; ++j) {
            int aux;
            cin >> aux;
            torres[i].push_back(aux);
        }
    }
    int ans = 0, piso = m-1;
    for (int i = 1; i < n; ++i) {
        sort(torres[i].begin(), torres[i].end());
        vector<int>::iterator it = lower_bound(torres[i].begin(), torres[i].end(), piso);
        if (*it != piso && it != torres[i].begin()) {
            piso = *(it-1);
        }
        else {
            ans += *it - piso;
            piso = *it;
        }
    }
    cout << ans << endl;

}
