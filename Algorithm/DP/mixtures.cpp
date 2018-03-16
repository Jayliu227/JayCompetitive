#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000;

int a[maxn];
int dp[maxn][maxn];

const int mod = 100;

int sum(int i, int j){
	int s = 0;
	for(int d = i; d <= j; d++){
		s += a[d];
		s %= mod;
	}	
	return s;
}

int solveMixture(int s, int e){
	if(s >= e) return 0;
	if(dp[s][e] != -1) return dp[s][e];		

	dp[s][e] = (int)1e9;
	for(int k = s; k <= e; k++){
		dp[s][e] = min(dp[s][e], solveMixture(s, k) + solveMixture(k + 1, e) + sum(s, k) * sum(k + 1, e));	
	}
	return dp[s][e];
}

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) cin >> a[i];

	memset(dp, -1, sizeof(dp));	

	cout << solveMixture(0, n - 1) << endl;

	return 0;
}