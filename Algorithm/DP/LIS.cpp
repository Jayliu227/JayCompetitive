#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	int a[N];
	int dp[N][2];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]); 
	}

	dp[0][0] = 1;
	dp[0][1] = -1;

	for(int i = 1; i < N; i++){
		dp[i][0] = 1;
		dp[i][1] = -1;
		int m = 1;
		for(int j = i - 1; j >= 0; j--){
			if(a[j] <= a[i]){
				if(dp[j][0] + 1 > m){
					m = dp[j][0] + 1;
					dp[i][0] = m;
					dp[i][1] = j;
				}
			}
		}
	}

	int mi = 0;
	int mv = dp[0][0];
	for(int i = 1; i < N; i++){
		if(dp[i][0] > mv){
			mv = dp[i][0];
			mi = i;
		}		
	}	

	cout << dp[mi][0] << endl;

	while(dp[mi][1] != -1){
		cout << a[mi] << " ";
		mi = dp[mi][1];		
	}

	cout << a[mi];

	return 0;
}