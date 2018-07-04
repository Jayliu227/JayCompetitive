#include<bits/stdc++.h>

using namespace std;

const int INF = 12345678;

int n, T;
vector<int> a(200), t(200), dp(200);

void add(int p, int x){
	for(; p < 200; p += p & -p)
		t[p] = max(t[p], x);
}

int get(int p){
	int res = -INF;
	for(; p > 1; p -= p & -p)
		res = max(res, t[p]);
	return res;
}

int value(int x){
	int res = 0;
	while(!(x & 1)){
		x >>= 1;
		res++;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--){
		fill(a.begin(), a.end(), 0);
		fill(t.begin(), t.end(), 0);
		fill(dp.begin(), dp.end(), 0);

		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}

		int res = -1;
		dp[1] = value(a[1]);
		add(a[1], dp[1]);
		res = max(res, dp[1]);
		for(int i = 2; i <= n; i++){
			dp[i] = get(a[i] - 1) + value(a[i]);
			add(a[i], dp[i]);
			res = max(res, dp[i]);
		}

		cout << res << endl;
	}
	return 0;
}