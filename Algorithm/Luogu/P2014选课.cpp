#include <bits/stdc++.h>
using namespace std;

/* ideas
 * dp[i][j] means the max points we can get in the subtree
 * of i if we choose j subjects including i
 * dp[i][j] = max(dp[i][j], dp[i][j - q], dp[child][q]);
 */

int n, k, w[310], dp[310][310];
vector<int> a[310];

void dfs(int cur){
	for(int i = 1; i <= k; i++){
		dp[cur][i] = w[cur];
	}
	for(int i = 0; i < a[cur].size(); i++){
		int to = a[cur][i];
		dfs(to);
		/* the reason why we go backwards is because
		 * we compressed the state:
		 * f[i][j] = max(f[i - 1][j], f[i - i][j - w[i]] + v[i]);
		 */
		for(int j = k + 1; j >= 2; j--){
			for(int q = 1; q < j; q++){
				dp[cur][j] = max(dp[cur][j], dp[cur][j - q] + dp[to][q]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int from;
		cin >> from >> w[i];
		a[from].push_back(i);
	}
	dfs(0);
	cout << dp[0][k + 1] << endl; 
	return 0;
}
