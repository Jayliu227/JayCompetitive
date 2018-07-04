#include <bits/stdc++.h>

using namespace std;

const int N = 12345;
const int INF = 123456789;
int n, m, dp[2][N], temp[N];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for(int t = 0; t < n; t++){
		cin >> s;
		string exts = s + s + s;
		int onePos = -1;
		fill(temp, temp + m, INF);
		for(int i = 0; i < m * 3; i++){
			if(exts[i] == '1')
				onePos = i;
			if(i >= m && i < m * 2 && onePos != -1)
				temp[i - m] = min(temp[i - m], i - onePos);
		}

		onePos = -1;
		for(int i = m * 3 - 1; i >= 0; i--){
			if(exts[i] == '1')
				onePos = i;
			if(i >= m && i < m * 2 && onePos != -1)
				temp[i - m] = min(temp[i - m], onePos - i);
		}

		for(int i = 0; i < m; i++){
			int distance = temp[i];
			if(distance == INF){
				dp[t & 1][i] = -1;
			}else{
				if(dp[t & 1 ^ 1][i] == -1){
					dp[t & 1][i] = -1;
				}else{
					dp[t & 1][i] = distance + dp[t & 1 ^ 1][i];
				}
			}
		}
	}

	int res = INF;
	for(int i = 0; i < m; i++){
		res = min(res, dp[(n - 1) & 1][i]);
	}
	if(res == INF){
		cout << -1 << endl;
	}else{
		cout << res << endl;
	}
	return 0;
}