#include <bits/stdc++.h>
using namespace std;
/* used -> number of sticks we've used so far
 * current -> the current big stick we're building
 * pos -> which of the short sticks we are about to 
 * 			choose from
 * when we used a short stick such that it forms a valid long stick
 * we no longer need to try to use more shorter sticks than using a
 * single relatively longer stick
 * when we constructed a long stick, the next long stick should start
 * from the longest stick we havent used so far.
 */

int n, tot, a[65], sum, mx, ok, len, vis[65];

void dfs(int used, int current, int pos){
	if(ok) return;
	if(used == tot && current == 0){
		ok = 1;
		return;
	}
	int last = -1;
	for(int i = pos; i < tot; i++){
		if(vis[i] == 0 && current + a[i] <= len){
			if(current + a[i] == last) continue;
			last = current + a[i];
			vis[i] = 1;
			if(current + a[i] == len)
				dfs(used + 1, 0, 0);
			else
				dfs(used + 1, current + a[i], i + 1);
			vis[i] = 0;
			if(current == 0 || current + a[i] == len) break;
		}
	}
}
int comp(int a, int b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(x > 50) continue;
		a[tot++] = x;
		sum += x;
		mx = max(mx, x);
	}
	sort(a, a + tot, comp);

	for(len = mx; len <= sum; len++){
		if(sum % len == 0){
			ok = 0;
			dfs(0, 0, 0);
			if(ok){
				cout << len << endl;
				return 0;
			}
		}
	}
	return 0;
}
