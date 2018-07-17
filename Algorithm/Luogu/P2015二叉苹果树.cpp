#include <bits/stdc++.h>
/*
 * knapsack dp on tree:
 * dp[i][j] means the max amount of apples we
 * can get at node i with j branches
 * u->v
 * dp[u][j] = max(dp[u][j - k - 1] + dp[v][k] + w);
 * j - k - 1 means that we use k for this children
 * and 1 for this branch
 * we need to iterate backwards because when we consider
 * the second child, we want to include answers for the 
 * first child, which is stored in dp[u][j] current. 
 * and since dp[u][j] depends on dp[u][j - k - 1], as
 * we compressed the state, we need to iterate backwards;
 * or equivalently, we can add a state dp[i][j][k], which
 * means at node i, the max apples we can get if we have k
 * branches left and have already considered j children.
 * */
using namespace std;
const int maxn = 110;

int n, q, dp[maxn][maxn];
struct edge{ int to, w; };
vector<edge> adj[maxn];
int dfs(int cur, int fa){
	int sum = 0;
	for(int i = 0; i < adj[cur].size(); i++){
		int to = adj[cur][i].to;
		int w = adj[cur][i].w;
		if(to == fa) continue;
		int sons = dfs(to, cur);
		sum += sons + 1;
		for(int j = sum; j >= 1; j--)
			for(int k = j - 1; k >= 0; k--)
				dp[cur][j] = max(dp[cur][j],
								dp[cur][j - k - 1] + dp[to][k] + w);
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i < n; i++){
		int u, v, w;
		edge a, b;
		cin >> u >> v >> w;
		a.to = v, a.w = w;
		b.to = u, b.w = w;
		adj[u].push_back(a);
		adj[v].push_back(b);
	}
	dfs(1, -1);
	cout << dp[1][q] << endl;
	return 0;
}
