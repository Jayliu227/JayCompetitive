#include <bits/stdc++.h>
using namespace std;
int V, n, a[31], dp[20010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i + 1];
	}
	for(int i = 1; i <= V; i++)
		dp[i] = i;

	for(int i = 1; i <= n; i++){
		for(int v = V; v >= 0; v--){
			if(v >= a[i]){
				dp[v] = min(dp[v], dp[v - a[i]]);	
			}
		}
	}
	cout << dp[V] << endl;
	return 0;
}
