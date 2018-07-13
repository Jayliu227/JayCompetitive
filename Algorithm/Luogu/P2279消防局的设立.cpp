#include <bits/stdc++.h>
using namespace std;
/* doesn't work*/
#define PUT 1
#define NOT 0
int n, dp[1010][2], vis[1010];
vector<int> adj[1010];
void dfs(int x){
	vis[x] = 1;
	if(adj[x].size() == 0){	
		dp[x][PUT] = 1;
		dp[x][NOT] = 0;
		return;
	}
	for(int i = 0; i < adj[x].size(); i++){
		if(!vis[adj[x][i]])
			dfs(adj[x][i]);
	}
	dp[x][PUT] = 0x3f3f3f3f;
	dp[x][NOT] = 0x3f3f3f3f;
	// children
	for(int i = 0; i < adj[x].size(); i++){
		int child = adj[x][i];
		for(int j = 0; j < adj[child].size(); j++){
			int grand = adj[child][j];
			dp[x][PUT] = min(dp[x][PUT], dp[grand][PUT]);
			dp[x][PUT] = min(dp[x][PUT], dp[grand][NOT]);
			dp[x][NOT] = min(dp[x][NOT], dp[grand][PUT]);
		}
		dp[x][PUT] = min(dp[x][PUT], dp[child][PUT]);
		dp[x][PUT] = min(dp[x][PUT], dp[child][NOT]);
		dp[x][NOT] = min(dp[x][NOT], dp[child][PUT]);
	}
	dp[x][PUT]++;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x = i, y;
		cin >> y;
		adj[y].push_back(x);
	}
	dfs(1);
	cout << min(dp[1][PUT], dp[1][NOT]) << endl;
	return 0;
}
