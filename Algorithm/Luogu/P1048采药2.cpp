#include <bits/stdc++.h>
using namespace std;
int T, n, t[200], v[200], dp[1010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T >> n;

	for(int i = 1; i <= n; i++){
		cin >> t[i] >> v[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = T; j >= 0; j--){
			if(j >= t[i])
				dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
		}
	}
	cout << dp[T] << endl;
	return 0;
}
