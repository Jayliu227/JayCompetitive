#include <bits/stdc++.h>
/* knapsack dp on tree:
 * we can consider dp[i][j][k] to be the max
 * compensation we can get at node i using the
 * first j children and having k users
 *
 * we can easily write transiton function as follows:
 * dp[i][j][k] = max(dp[to][all_children(to)][t] + dp[i][j - 1][k - t] - w)
 * w here means the money spent on edge i-to
 * the second state can be compressed into
 * dp[i][j] means the max compensate we can get at node i having j users
 * dp[i][j] = max(dp[i][k] + dp[to][j - k] - w)
 * but we have to traverse backwards since every state depends on its
 * previous term;
 */
using namespace std;
const int N = 3010;
int n, m, t[N], dp[N][N];
struct node{ int t, w; };
vector<node> adj[N];
int dfs(int u){
	if(u > n - m){
		dp[u][1] = t[u];
		return 1;
	}
	int sum = 0;
	for(int e = 0; e < adj[u].size(); e++){
		int v = adj[u][e].t;
		int w = adj[u][e].w;
		int sons = dfs(v);
		sum += sons;
		for(int i = sum; i >= 1; i--){
			for(int j = 1; j <= sons; j++){
				dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j] - w);
			}
		}
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(dp, -63, sizeof(dp));
	cin >> n >> m;
	for(int i = 1; i <= n; i++) dp[i][0] = 0;
	for(int i = 1; i <= n - m; i++){
		int k; cin >> k;
		for(int j = 1; j <= k; j++){
			node c; cin >> c.t >> c.w;
			adj[i].push_back(c);
		}
	}
	for(int i = (n - m + 1); i <= n; i++){
		cin >> t[i];
	}
	dfs(1);
	for(int i = m; i >= 0; i--) {
		if(dp[1][i] >= 0){
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
}
