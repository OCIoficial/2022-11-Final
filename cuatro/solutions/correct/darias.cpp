#include <bits/stdc++.h>
using namespace std;

char game[20][20];
char active[20][20];

struct win_state {
    bool x;
    bool o;
};

win_state who_wins(int n) {
    win_state state = { 0, 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game[i][j] == 'X') {
                // col
                if (i < n - 3 && game[i+1][j] == 'X' && game[i+2][j] == 'X' && game[i+3][j] == 'X') {
                    active[i][j] = 1;
                    active[i+1][j] = 1;
                    active[i+2][j] = 1;
                    active[i+3][j] = 1;
                    state.x = 1;
                }
                // hor
                if (j < n - 3 && game[i][j+1] == 'X' && game[i][j+2] == 'X' && game[i][j+3] == 'X') {
                    active[i][j] = 1;
                    active[i][j+1] = 1;
                    active[i][j+2] = 1;
                    active[i][j+3] = 1;
                    state.x = 1;
                }
            }
            if (game[i][j] == 'O') {
                // col
                if (i < n - 3 && game[i+1][j] == 'O' && game[i+2][j] == 'O' && game[i+3][j] == 'O') {
                    active[i][j] = 1;
                    active[i+1][j] = 1;
                    active[i+2][j] = 1;
                    active[i+3][j] = 1;
                    state.o = 1;
                }
                // hor
                if (j < n - 3 && game[i][j+1] == 'O' && game[i][j+2] == 'O' && game[i][j+3] == 'O') {
                    active[i][j] = 1;
                    active[i][j+1] = 1;
                    active[i][j+2] = 1;
                    active[i][j+3] = 1;
                    state.o = 1;
                }
            }
        }
    }
    return state;
}

int main() {
    memset(active, 0, sizeof active);

    int n; cin >> n;
    int n_o = 0, n_x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> game[i][j];
            if (game[i][j] == 'O') {
                n_o++;
            }
            if (game[i][j] == 'X') {
                n_x++;
            }
        }
    }
    if (n_o != n_x && n_o != n_x + 1) {
        cout << "imposible" << endl;
        return 0;
    }

    win_state winner = who_wins(n);
    if (not winner.x && not winner.o) {
        if (n % 2 == 0 && n_o == n_x) { 
            cout << "posible" << endl;
        } else if (n % 2 == 1 && n_o == n_x + 1) {
            cout << "posible" << endl;
        } else {
            cout << "imposible" << endl;
        }
        return 0;
    }

    if (n_o == n_x && winner.o) {
        cout << "imposible" << endl;
        return 0;
    }
    if (n_o == n_x + 1 && winner.x) {
        cout << "imposible" << endl;
        return 0;
    }

    bool valid = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!active[i][j]) {
                continue;
            }
            if (winner.x && game[i][j] == 'X') {
                game[i][j] = '.';
                win_state state = who_wins(n);
                game[i][j] = 'X';
                if (not state.x) {
                    valid = 1;
                }
            } else if (winner.o && game[i][j] == 'O') {
                game[i][j] = '.';
                win_state state = who_wins(n);
                game[i][j] = 'O';
                if (not state.o) {
                    valid = 1;
                }
            }
        }
    }

    if (valid) {
        cout << "posible" << endl;
    } else {
        cout << "imposible" << endl;
    }
}

