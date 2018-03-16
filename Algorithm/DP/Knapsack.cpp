#include<bits/stdc++.h>

using namespace std;
                   
const int maxn = 100;
int v[maxn];
int w[maxn];
int n, s;
int dp[maxn][maxn];

int value(int i, int rw){
	if(i == n) return 0;
	if(rw == 0) return 0;

	if(dp[i][rw] != -1) return dp[i][rw];

	if(w[i] > rw) return dp[i][rw] = value(i + 1, rw);
	
	return dp[i][rw] = max(value(i+1,rw), v[i] + value(i + 1, rw - w[i]));
}


int main(){	
	cin >> n >> s;

	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) cin >> w[i];

	memset(dp, -1, sizeof(dp));	

	cout << value(0,s) << "\n";

	return 0;
}