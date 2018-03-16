#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;
int c[maxn];
int v, n;
int dp[maxn];

int change(int r){
	if(r == 0) return 0;
	if(r < 0) return 1e9;
	if(dp[r] != -1) return dp[r];
	int m = 1e9;
	for(int i = 0; i < n; i++){
		m = min(m, change(r - c[i]));
	}	
	return dp[r] = m + 1;
}

int main(){
	cin >> v >> n;
	for(int i = 0; i < n; i++) cin >> c[i];
	memset(dp, -1, sizeof(dp));
	cout << change(v) << "\n";

	return 0;
}