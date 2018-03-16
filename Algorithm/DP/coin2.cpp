#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;
int c[maxn];
int v, n;
int dp[maxn][maxn];

int ways(int id, int r){
	// when remain is zero, we have successfully encountered a valid solution
	if(r == 0) return 1;
	// either the remaining is below zero or we've tried all coins, we have no way to get v
	if(r < 0 || id == n) return 0;
	// if we've computed before, just return it
	if(dp[id][r] != -1) return dp[id][r];
	// otherwise, we compute it and return
	// the number of combinations if we don't use this coin + that if we use this coin.
	return dp[id][r] = ways(id + 1,r) + ways(id,r - c[id]);	                                     	
}

int main(){
	cin >> v >> n;
	for(int i = 0; i < n; i++) cin >> c[i];
	memset(dp, -1, sizeof(dp));
	cout << ways(0, v) << "\n";

	return 0;
}