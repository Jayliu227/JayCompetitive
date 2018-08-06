#include <bits/stdc++.h>
#define re register
using namespace std;
/* idea:
 * decompose number n into powers of 2;
 * and if the number is smaller than k,
 * we don't need additional cups.
 * otherwise we gradually add cups until
 * the number left is smaller than k.
 */
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, k;
	cin >> n >> k;
	vector<int> a;
	for(re int i = 0; (1LL << i) <= n; i++){
		if(((1 << i) & n) > 0){
			a.push_back(1 << i);
		}
	}
	if(a.size() <= k)
		cout << 0 << endl;
	else{
		int i = 0;
		int ans = 0;
		while(i < a.size() - 1){
			int left = a.size() - i;
			if(left <= k)
				break;
			ans += a[i + 1] - a[i];
			// since we add cups of water
			// the water contained in the next cup
			// would be doubled.
			a[i + 1] *= 2;
			i++;
		}
		cout << ans << endl;
	}
	return 0;
}
