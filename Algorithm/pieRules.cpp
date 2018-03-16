#include<bits/stdc++.h>

using namespace std;

/*
	a pie with slices whose sizes are stored in p.
	a decider token is given to a player and this player can choose
	if the next slice is given to him or the other player, then this token
	would be given to the one who didn't get the slice this round.
*/

int n;

int main(){
	cin >> n;
	int p[n];
	int dp[n + 1];
	for(int i = 0; i < n; i++) cin >> p[i];
	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		dp[i] = abs(p[i] - dp[i + 1]);
	}

	int sum = accumulate(p, p + n, 0);

	cout << (sum - dp[0]) /2 << " " << (sum + dp[0]) / 2 << '\n';

}