#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl

template<typename T> inline bool chkmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int a[1000000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
 
 	int k;  
 	cin >> k; 
 	// sum, (which, index)
 	map<int, pair<int, int>> mp;
 	for(int i = 1; i <= k; i++){
 		int n;
 		cin >> n;
 		int sum = 0;
 		for(int j = 1; j <= n; j++){
 			cin >> a[j];
 			sum += a[j];
 		}
 		for(int j = 1; j <= n; j++){
 			int partial = sum - a[j];
 			if(mp[partial].fi > 0 && mp[partial].fi != i){
 				cout << "YES" << endl;
 				cout << i << " " << j << endl;
 				cout << mp[partial].fi << " " << mp[partial].se << endl;
 				return 0;
 			}else{
 				mp[partial] = make_pair(i, j);
 			}
 		}
 	}

 	cout << "NO" << endl;

    return 0;
}