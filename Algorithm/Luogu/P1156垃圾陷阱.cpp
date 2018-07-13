#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

/* dp over each trash
 * sort the trashs based on the time at which they are thrown
 * dp[i][j] represents the max health the cow can get at height j by the optimal choices 
 * of the first i trashs
 * if we want to use the ith trash as health, then dp[i - 1][j] must be bigger than the time
 * interval between ith and i - 1th trash because otherwise it would die before the ith one drops
 * thus in this case
 * dp[i][j] = max(dp[i][j], dp[i - 1][j] - (time interval) + health gained)
 * if we want to use the ith trash as a step, then since this step is of height trash[i].height,
 * the max health at height j - trash[i].height must be greater than the time interval between ith and
 * i - 1th trashs, because otherwise it would die before ith trash drops
 * thus in this case
 * dp[i][j] = max(dp[i][j], dp[i - 1][j - trash height gained] - (time interval)]
 * if at some point we reach total height n, we're done
 * otherwise, we need to find the max height over all possible cases:
 * a case is possible only if the max health at that time is greater than 0 
 */

int n, m, dp[110][110];
struct trash{
	int x, t, h;
	bool operator< (const trash a) const{
		return x < a.x;
	}
}trashs[110];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		cin >> trashs[i].x >> trashs[i].t >> trashs[i].h; 
	}
	sort(trashs + 1, trashs + 1 + n);
	trashs[0].x = trashs[0].t = trashs[0].h = 0;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 10;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			// can take this as health
			if(dp[i - 1][j] - (trashs[i].x - trashs[i - 1].x) >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j] - trashs[i].x + trashs[i - 1].x + trashs[i].t);
			}
			// take this as step
			if(j - trashs[i].h >= 0 && dp[i - 1][j - trashs[i].h] - (trashs[i].x - trashs[i - 1].x) >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - trashs[i].h] - trashs[i].x + trashs[i - 1].x);
				if(j == m){
					cout << trashs[i].x << endl;
					return 0;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(dp[i][j] != -INF){
				ans = max(ans, dp[i][j] + trashs[i].x);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
