#include<bits/stdc++.h>

using namespace std;

int n, m, mod = (int) 1e9;
int field[20][20], F[20] = {0}, dp[20][(1 << 20)], state[(1 << 20)];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> field[i][j];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			F[i] = (F[i] << 1) + field[i][j];
		}
	}

	int stateSize = (1 << m);

	for(int i = 0; i < stateSize; i++){
		state[i] = ((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0);
	}

	dp[0][0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < stateSize; j++){
			if(state[j] && ((j & F[i]) == j)){
				for(int k = 0; k < stateSize; k++){
					if((j & k) == 0){
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
					}
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < stateSize; i++){
		ans = (ans + dp[n][i]) % mod;
	}

	cout << ans << endl;
	return 0;
}