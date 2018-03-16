#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

using namespace std;

const int maxn = (int) 1e2;
int N;
int maze[maxn][maxn];
int result[maxn][maxn];

bool canReach(int x, int y){
	if(x == (N - 1) && y == (N - 1)) {
		result[x][y] = 1;
		return true;
	}
	
	if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1){		
		result[x][y] = 1;
		if(canReach(x + 1, y)){
			return true;
		}

		if(!canReach(x, y + 1)){
			return true;
		}
		result[x][y] = 0;
		return false;
	}
	return false;
}

int main(){
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> maze[i][j];
		}
	}

	memset(result, 0, sizeof(result));

	cout << canReach(0,0) << '\n';
	
	return 0;
}