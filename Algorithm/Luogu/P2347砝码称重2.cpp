#include <bits/stdc++.h>
using namespace std;

int weight[] = {0,1,2,3,5,10,20};
int cnt[7];
int dp[1010][7] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i < 6; i++){
		cin >> cnt[i + 1];
	}

	dp[0][0] = 1;
	for(int i = 1; i <= 6; i++){
		for(int j = 0; j <= cnt[i]; j++){
			for(int w = 0; w <= 1000; w++){
				if(w + j * weight[i] <= 1000){
					dp[w + j * weight[i]][i] |= dp[w][i - 1];
				}
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= 1000; i++){
		ans += dp[i][6];			
	}

	cout << "Total=" << ans << endl;
	return 0;
}