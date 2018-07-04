#include <bits/stdc++.h>
using namespace std;

const int N = 123456;
int dp[N] = {0}, sum[N] = {0}, m[N] = {0};	

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		sum[i] = sum[i - 1] + x;	
	}
	for(int i = 1; i <= n; i++){
		for(int j = i - 1; j >= 0; j--){
			if(sum[i] - sum[j] >= m[j]){
				m[i] = sum[i] - sum[j];
				dp[i] = dp[j] + i - j - 1;
				break;
			}
		}
	}
	
	cout << dp[n] << endl;
	return 0;
}