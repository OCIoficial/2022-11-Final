#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define iii tuple<int,int,int>

int dijkstra(ii inicio, ii fin, vector<vector<int>> &torres) {
    vector<map<int, int>> distancias(torres.size());
    for (int i = 0; i < torres.size(); ++i) {
        for (int j = 0; j < torres[i].size(); ++j) {
            distancias[i][torres[i][j]] = INT_MAX/2;
        }
    }

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, inicio.first, inicio.second});
    distancias[inicio.first][inicio.second] = 0;

    while (!pq.empty()) {
        iii actual = pq.top();
        pq.pop();

        int distancia, torre, piso;
        tie(distancia, torre, piso) = actual;

        if (distancia > distancias[torre][piso]) continue;

        if (torre == fin.first) {
            return distancia;
        }
        for (int i = 0; i < torres[torre+1].size(); ++i) {
            int nuevopiso = torres[torre+1][i];

            if (piso < nuevopiso) {
                if ((distancia + (nuevopiso - piso)) < distancias[torre+1][nuevopiso]) {
                    pq.push({distancia + (nuevopiso - piso), torre+1, nuevopiso});
                }
            }
            else {
                if (distancia < distancias[torre+1][nuevopiso]) {
                    pq.push({distancia, torre+1, nuevopiso});
                }
            }
        }
    }
    return -1;
}

int main () {
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
    cout << dijkstra({0, m-1}, {n-1, 0}, torres) << endl;
    return 0;
}
