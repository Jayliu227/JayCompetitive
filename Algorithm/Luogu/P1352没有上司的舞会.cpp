#include <bits/stdc++.h>
#define re register
using namespace std;
const int maxn = 7000;
vector<int> adj[maxn];
int n, a[maxn], dp[maxn][2], hasBoss[maxn];
void dfs(int u){
	dp[u][1] = a[u];
	dp[u][0] = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		dfs(v);
		dp[u][1] += dp[v][0];
		dp[u][0] += max(dp[v][1], dp[v][0]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> v >> u;
		hasBoss[v] |= 1;
		adj[u].push_back(v);
	}
	int root = 1;
	for(int i = 1; i <= n; i++){
		if(!hasBoss[i]){
			root = i;
			break;
		}
	}
	dfs(root);
	cout << max(dp[root][0], dp[root][1]) << endl;
	return 0;
}
