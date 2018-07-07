#include <bits/stdc++.h>
using namespace std;

int weight[] = {1,2,3,5,10,20};
int num[6];
bitset<1010> dp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i < 6; i++){
		cin >> num[i];
	}

	dp[0] = 1;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < num[i]; j++){
			dp |= dp << weight[i];
		}
	}

	cout << "Total=" << (dp.count() - 1) << endl;
	return 0;
}