#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

void yes(){
	cout << "posible\n";
	exit(0);
}

void no(){
	cout << "imposible\n";
	exit(0);
}

int winner(vector <string> &grid){
	// Checks if there's 4 in line
	int n = grid.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			bool w = false;
			if(i+3<n and grid[i+1][j] == grid[i][j]
					 and grid[i+2][j] == grid[i][j]
					 and grid[i+3][j] == grid[i][j]) w = true;
			if(j+3<n and grid[i][j+1] == grid[i][j]
					 and grid[i][j+2] == grid[i][j]
					 and grid[i][j+3] == grid[i][j]) w = true;
			if(w and grid[i][j] != '.'){
				return grid[i][j] == 'O' ? 1 : 2;
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	/* some conditions:
	 * #O - #X == (1 | 0)
	 * Winner is O => #O - #X == 1
	 * Winner is X => #O - #X == 0
	 */
	int n; cin >> n;
	vector <string> grid(n);
	int cnt_x=0, cnt_o=0, cnt_dot=0;
	for(int i=0; i<n; i++){
		cin >> grid[i];
		for(char c : grid[i]){
			if(c == 'X') cnt_x++;
			else if(c == 'O') cnt_o++;
			else if(c == '.') cnt_dot++;
		}
	}
	dbg(cnt_o, cnt_x, cnt_dot);
	if(cnt_o-cnt_x != 1 and cnt_o-cnt_x != 0){ // Turns
		dbg("not respecting turns");
		no();
	}
	int w = winner(grid);
	if(w == 0 and cnt_dot != 0){ // Game hasn't ended
		dbg("not ended");
		no();
	}
	if(w == 0 and cnt_dot == 0){ // Draw
		dbg("draw");
		yes();
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			char save = grid[i][j];
			grid[i][j] = '.';
			int new_w = winner(grid);
			if(i == 4 and j == 2) dbg(new_w);
			if(new_w == 0){
				dbg(i, j);
				if(w == 1){
					if(cnt_o - cnt_x == 1) yes();
					else no();
				}
				else if(w == 2){
					if(cnt_o-cnt_x == 0) yes();
					else no();
				}
			}
			grid[i][j] = save;
		}
	}
	no();
	return 0;
}
