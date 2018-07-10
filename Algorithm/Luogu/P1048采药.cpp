#include <bits/stdc++.h>
using namespace std;
int T, n, t[200], v[200], dp[200][1010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T >> n;

	for(int i = 1; i <= n; i++){
		cin >> t[i] >> v[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= T; j++){
			dp[i][j] = dp[i - 1][j];
			if(j >= t[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i]] + v[i]);
			}
		}
	}
	cout << dp[n][T] << endl;
	return 0;
}
