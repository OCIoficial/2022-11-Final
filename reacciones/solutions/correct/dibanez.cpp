#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> v(26, 0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> ans(n, -1);

    for (int i = 0; i < n; ++i) {
        if (v[s[i] - 'a'] >= k) {
            cout << "imposible\n";
            exit(0);
        }
        ans[i] = ++v[s[i] - 'a'];
    }

    for (int i = 0; i < n; ++i)
        // la última parte del cout solo es necesaria si el juez es muy estricto
        cout << ans[i] << " \n"[i==n-1];

    return 0;
}
