#include <bits/stdc++.h>
#define re register
/* we want to count how many pairs of (x, y) are
 * coprime:
 * because for each point(x, y), its slope is y/x
 * if it is nonreducible, it is the first point on
 * the sightline, which is visible, all other points
 * of the form(xt, yt) for t > 1 are nonvisible.
 * thus, assume x >= y, we are considering only the
 * lower triangle, ans = sum(phi[x])
 * and we need to multiple this by 2 and add three
 * special points (1,1) on the main diagonal, (1, 0) and
 * (0, 1) who have special slope values.
 */
using namespace std;
int phi[41000], p[41000], prime[41000], n;
void euler(){
	memset(prime, true, sizeof(prime));
	int cnt = 0;	
	phi[1] = 0;
	for(int i = 2; i <= n; i++){
		if(prime[i]){
			p[cnt++] = i;
			phi[i] = i - 1;
		}
		for(int j = 0; j < cnt; j++){
			if(i * p[j] > n) break;
			prime[i * p[j]] = false;
			if(i % p[j] == 0){
				phi[i * p[j]] = p[j] * phi[i];
				break;
			}else{
				phi[i * p[j]] = phi[i] * phi[p[j]];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> n;
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	euler();
	int ans = 0;
	for(int i = 1; i < n; i++)
		ans += phi[i];
	cout << (ans * 2 + 3) << endl;
	return 0;
}
