#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	
	cin >> n >> m;
	int mlen = 1000000000 + 10;
	for(int i = 0; i < m; i++){
	    int l, r;
	    cin >> l >> r;
	    mlen = min(mlen, r - l + 1);
	}
	
	cout << mlen << endl;
	for(int i = 0; i < n; i++){
	    cout << (i % mlen) << " ";
	}
	return 0;
}