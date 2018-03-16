#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;

int n, k;

int dp[maxn][maxn];

int ways(int n, int k){
	if(n == 0) return 1;
	if(k == 0) return 0;

	if(dp[n][k] != -1) return dp[n][k];

	int w = 0;
	for(int i = 0; i <= n; i++){
		w += ways(n - i, k -1);
	}		

	return dp[n][k] = w;
}

int main(){
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));

	cout << ways(n, k) << "\n";

	return 0;
}