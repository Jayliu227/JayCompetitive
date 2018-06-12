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
const int N = 1234;

int x[N], y[N], p[N], r[N], n;

int find(int x){
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unite(int a, int b){
	int x = find(a);
	int y = find(b);
	if(x == y) return;
	if(x > y) swap(x, y);
	p[x] = y;
	if(r[x] == r[y]) r[y]++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    cin >> n;
    forn(i, n) p[i] = i, r[i] = 0;
    forn(i, n){
    	cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		if(x[i] == x[j] || y[i] == y[j]){
    			unite(i, j);
    		}
    	}
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
    	if(p[i] == i) ans++;
    }

    cout << (ans - 1) << endl;
    return 0;
}