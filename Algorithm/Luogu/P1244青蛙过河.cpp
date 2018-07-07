#include<bits/stdc++.h>

using namespace std;

/*
	central ideas:
	1. if there are only h leaves, then there are at most h + 1 frogs
		each leaf has exactly one frog, and the last frog can jump to the end.
	2. if there is 1 stone, then we can treat this stone as the last stone and
		therefore, we know the max number of frogs we can have on this stone.
		the total number would be this number + h + 1.
	3. thus, dp[i] = dp[k] (0 <= k < i) + h + 1;
 */

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, h;
	cin >> s >> h;

	int dp[s + 1];
	dp[0] = h + 1;
	for(int i = 1; i <= s; i++){
		dp[i] = 0;
		for(int j = 0; j < i; j++){
			dp[i] += dp[j];
		}
		dp[i] += h + 1;
	}

	cout << dp[s] << endl;
	return 0;
}