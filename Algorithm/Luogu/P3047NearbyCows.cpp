#include <bits/stdc++.h>
/* two rounds of dfs:
 * 1. dp[i][d] represents the sum of values of children whose distance
 * 	  is d;
 * 2. second round is to let father node update children nodes
 * 	  dp[child][d] += dp[father][d - 1] nodes d units away from child is
 * 	  the same as d - 1 units away from father
 * 	  however this would count childrens of the child twice
 * 	  so dp[child][d] -= dp[child][d - 2]
 * 	  the reason why it is d - 2 is because dp[child][d - 2] covers a subset
 * 	  of dp[father][d - 1];
 *    for those who are d - 1 distance away from father, and also locate
 *    below the child, it takes 1 step fewer to get to the child
 *    thus it is d - 1 - 1 distance away from the child, which gives the
 *    above equation
 */
using namespace std;
int n, k, deep[100010], a[100010], dp[100010][21];
vector<int> adj[100010];

void solve(int x){
	for(int i = 0; i < adj[x].size(); i++){
		int to = adj[x][i];
		if(!deep[to]){
			deep[to] = deep[x] + 1;
			solve(to);
			for(int j = 1; j <= k; j++){
				dp[x][j] += dp[to][j - 1];
			}
		}
	}
}
void dfs(int x){
	for(int i = 0; i < adj[x].size(); i++){
		int to = adj[x][i];
		if(deep[to] > deep[x]){
			for(int j = k; j >= 2; j--){
				dp[to][j] -= dp[to][j - 2];
			}
			for(int j = 1; j <= k; j++){
				dp[to][j] += dp[x][j - 1];
			}
			dfs(to);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i][0] = a[i];
	}

	deep[1] = 1;
	solve(1);
	dfs(1);
	for(int i = 1; i <= n; i++){
		int ans = 0;
		for(int d = 0; d <= k; d++){
			ans += dp[i][d];
		}
		cout << ans << endl;
	}
	return 0;
}
