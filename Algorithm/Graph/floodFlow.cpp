#include<bits/stdc++.h>

using namespace std;

/*
	test cases:
	5 5
	2 3
	0 1 1 1 1
	0 1 0 1 1
	1 1 0 1 1
	0 1 1 1 1
*/


const int maxn = 100;
int grid[maxn][maxn];
int R, C;
int sx, sy;

int flood(int sx, int sy){
	if(sx < 0 || sx >= R || sy < 0 || sy >= C)
		return 0;
	if(grid[sx][sy] != 1) return 0;
	int ans = 1;
	grid[sx][sy] = 0;

	int x[] = {0,1,1,1,0,-1,-1,-1};
	int y[] = {1,1,0,-1,-1,-1,0,1};

	for(int i = 0; i < 8; i++){
		ans += flood(sx + x[i], sy + y[i]);	
	}
	return ans;
}

int main(){
	cin >> R >> C;
	cin >> sx >> sy;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			int c;
			cin >> c;
			grid[i][j] = c == 1 ? 1 : 0;
		}
	}
	cout << flood(sx, sy) << '\n';	
}