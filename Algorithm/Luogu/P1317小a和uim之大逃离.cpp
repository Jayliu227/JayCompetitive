#include <bits/stdc++.h>
using namespace std;
/* since the answer would be mod over some big number
 * it becomes clear that dp must store the number of ways
 * thus dp[....] = number of ways at certain state
 * dp[i][j] would help but we need to consider the points
 * for each of them independently
 * dp[i][j][p][q] would be too much and we need an extra 
 * parameter to keep track of whose turn it is
 * so dp[i][j][p][q][t] can be compressed to dp[i][j][d][t]
 * which means that at point (i, j) the number of ways to
 * maintain a difference of d at t's turn.
 * thus answer would be sum(dp[i][j][0][1]) the last 1 means
 * it ends with the second player
 * transition function:
 * dp[i][j][d][1] = dp[i - 1][j][d - a[i][j]][0] + dp[i][j - 1][d - a[i][j]][0];
 * dp[i][j][d][0] = dp[i - 1][j][d + a[i][j]][1] + dp[i][j - 1][d + a[i][j]][1];
 */
int n, m, k, dp[801][801][20][2], a[801][801];
const int mod = (int)1e9 + 7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	k++;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			dp[i][j][a[i][j] % k][0] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int d = 0; d <= k; d++){
				int v = a[i][j];
				dp[i][j][d][0] = (dp[i][j][d][0] + dp[i - 1][j][(d - v + k) % k][1]) % mod;
				dp[i][j][d][0] = (dp[i][j][d][0] + dp[i][j - 1][(d - v + k) % k][1]) % mod;

				dp[i][j][d][1] = (dp[i][j][d][1] + dp[i - 1][j][(d + v) % k][0]) % mod;
				dp[i][j][d][1] = (dp[i][j][d][1] + dp[i][j - 1][(d + v) % k][0]) % mod;
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans += dp[i][j][0][1];
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}

