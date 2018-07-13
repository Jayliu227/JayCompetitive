#include <bits/stdc++.h>
using namespace std;
/* dp[i][j][k] means the min watt in case when laowang is at pos i, and
 * lights at 1 - j and k - n are still not shut down.
 * the total watt that needs to waste for one move is equal to time * total watts
 * of the left lights
 * init all states to the INF except for the start state (which is equal to 0);
 * we can get the transition function using forward dp
 * move to the left
 * dp[l - 1][l - 1][r] = min(dp[l - 1][l - 1][r], dp[pos][l][r] + total watts * (p[pos] - p[l - 1]));
 * move to the right
 * dp[r + 1][l][r + 1] = min(dp[r + 1][l][r + 1], dp[pos][l][r] + total watts * (p[r + 1] - p[pos]));
 * final answer would be min between dp[1][1][n] and dp[n][1][n] meaning standing at 1 or last light
 */
#define INF 0x3f3f3f3f
int n, start, p[60], w[60], dp[60][60][60];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> start;
	for(int i = 1; i <= n; i++){
		cin >> p[i] >> w[i];
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
            	dp[k][i][j] = INF;
	dp[start][start][start] = 0;
	for(int len = 1; len <= n; len++){
		for(int pos = 1; pos <= n; pos++){
			for(int l = 1; l + len - 1 <= n; l++){
				int r = l + len - 1;
				if(l > start || r < start) continue;
				int sum = 0;

				for(int i = 1; i < l; i++)
					sum += w[i];
				for(int i = r + 1; i <= n; i++) 
					sum += w[i];
				if(l - 1 >= 1){
					dp[l - 1][l - 1][r] = min(dp[l - 1][l - 1][r], dp[pos][l][r] + sum * (p[pos] - p[l - 1])); 
				}
				if(r + 1 <= n){
					dp[r + 1][l][r + 1] = min(dp[r + 1][l][r + 1], dp[pos][l][r] + sum * (p[r + 1] - p[pos]));
				}
			}
		}
	}
	cout << min(dp[1][1][n], dp[n][1][n]) << endl;
	return 0;
}
