#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010], dp[1010][10010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i + 1];
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(j >= a[i]){
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
			}else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
