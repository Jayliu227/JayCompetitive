#include<bits/stdc++.h>
using namespace std;

const int maxn = 12345678;

int a[maxn];
int sq[30] = {-1};

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int len = (int) sqrt(n);
	for(int i = 0; i < n; i++){
		sq[i / len] = max(sq[i / len], a[i]);
	}

	while(true){
		int l, r;
		cin >> l >> r;
		if(l == -1 && r == -1)
			break;
		
		int res = -1;
		for(int i = l; i <= r;){
			if(i % len == 0 && i + len - 1 <= r){
				res = max(res, sq[i / len]);
				i += len;
			}else{
				res = max(res, a[i]);
				i++;
			}
		}

		cout << res << endl;
	}
}