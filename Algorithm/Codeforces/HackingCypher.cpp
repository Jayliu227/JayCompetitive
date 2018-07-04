#include<bits/stdc++.h>

using namespace std;

long long pow(long long x, long long b, long long mod){
	long long res = 1;
	while(b){
		if(b & 1) res = (res * x) % mod; 
		x = (x * x) % mod;
		b >>= 1;
	}
	return res;
}

/*
	check divisibility: number and divisor
	O(length[number])
	remainder[i] = (remainder[i - 1] * 10 + number[i]) % divisor;
	or
	remainder[i] = (number[i] * pow(10, length of suffix) + remainder[i + 1]) % divisor;
	divisor divides all prefixes of number if(remainder[i] == 0) for all position i;
 */

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string t;
	long long a, b, n;
	cin >> t >> a >> b;
	n = t.size();

	long long p[n], s[n];

	p[0] = (t[0] - '0') % a;
	for(int i = 0; i < n - 1; i++){
		p[i + 1] = ((p[i] * 10) % a + (t[i + 1] - '0')) % a;
	}

	s[n - 1] = (t[n - 1] - '0') % b;
	for(int i = n - 1; i >= 1; i--){
		int P = pow(10, n - i, b);
		s[i - 1] = (((t[i - 1] - '0') * P) % b + s[i]) % b;
	}

	for(int i = 0; i < n - 1; i++){
		if(p[i] == 0 && s[i + 1] == 0 && t[i + 1] != '0'){
			cout << "YES" << endl;
			cout << t.substr(0, i + 1) << endl;
			cout << t.substr(i + 1, n - i) << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}