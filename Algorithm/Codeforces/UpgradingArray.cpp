/*
	402D: float Point Exception
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n, m, ans, a[5100], b[5100];

bool nprime[N];
int primes[N], cnt;

void genPrime(){
	cnt = 0;
	memset(nprime, false, sizeof(nprime));
	memset(primes, 0, sizeof(primes));
	for(int i = 2; i < N; i++){
		if(!nprime[i]){
			primes[cnt++] = i;
			for(int j = i * i; j < N; j += i){
				nprime[j] = true;
			}
		}
	}
}

int helper(int x){
	int res = 0;
	for(int i = cnt; i >= 0; i--){
		bool found = binary_search(b, b + m, primes[i]);
		while(x % primes[i] == 0){
			if(found){
				res--;
			}else{
				res++;
			}
			x /= primes[i];
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];

	genPrime();

	ans = 0;
	for(int i = n - 1; i >= 0; i--){
		int gcd = a[i];
		for(int j = i - 1; j >= 0; j--){
			gcd = __gcd(gcd, a[j]);
		}
		if(gcd != 1 && helper(gcd) < 0){
			for(int j = 0; j <= i; j++){
				a[i] /= gcd;
			}
		}
		ans += helper(a[i]);
	}
    cout << ans << endl;
    return 0;
}