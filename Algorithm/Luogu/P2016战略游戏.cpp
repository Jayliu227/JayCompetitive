#include <bits/stdc++.h>
using namespace std;

int n, dp[1600][2], vis[1600];
vector<int> adj[1600];

void dfs(int x){
	vis[x] = 1;
	dp[x][0] = 0;
	dp[x][1] = 1;
	for(int i = 0; i < adj[x].size(); i++){
		int to = adj[x][i];
		if(!vis[to]){
			dfs(to);
			dp[x][0] += dp[to][1];
			dp[x][1] += min(dp[to][1], dp[to][0]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		int num, x;
		cin >> x >> num;
		for(int j = 0; j < num; j++){
			int to;
			cin >> to;
			adj[i].push_back(to);
			adj[to].push_back(i);
		}
	}
	dfs(0);
	cout << min(dp[0][1], dp[0][0]) << endl;
	return 0;
}
