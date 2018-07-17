#include <bits/stdc++.h>
#define re register
using namespace std;
const int maxn = 1234567;
int n, m, l, r;
bool vis[maxn];
int a[maxn];
void sieve(int m){
	vis[1] = true;	
	for(int i = 2; i <= m; i++){
		if(!vis[i]){
			a[i] = a[i - 1] + 1;
			for(int j = i + i; j <= m; j += i)
				vis[j] = true;
		}else{
			a[i] = a[i - 1];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	sieve(m);
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		if(l < 1 || r > m){
			cout << "Crossing the line" << endl;
		}else{
			cout << a[r] - a[l - 1] << endl;
		}
	}
	return 0;
}
