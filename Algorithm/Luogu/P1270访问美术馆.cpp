#include <bits/stdc++.h>
using namespace std;
int tot, times[200], paint[200], dp[200][700];
/* for dp problems involving binary tree
 * it is usually a good idea to try 1D representation
 * using an array, especially when the construction of 
 * the tree is of dfs order
 */

void read(int p){
	int x, y;
	cin >> x >> y;
	if(y){
		paint[p] = y;
		times[p] = x * 2;
	}else{
		times[p] = x * 2;
		read(p << 1);
		read(p << 1 | 1);
	}
}
void dfs(int p){
	if(paint[p]){
		for(int t = times[p]; t <= tot; t++){
			dp[p][t] = min((t - times[p]) / 5, paint[p]);	
		}
	}else{
		dfs(p << 1);
		dfs(p << 1 | 1);
		for(int t = times[p]; t <= tot; t++){
			int left = t - times[p];
			for(int q = 0; q <= left; q++){
				dp[p][t] = max(dp[p][t], dp[p << 1][q] + dp[p << 1 | 1][left - q]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> tot;
	tot--;
	read(1);
	dfs(1);
	cout << dp[1][tot] << endl;
	return 0;
}
