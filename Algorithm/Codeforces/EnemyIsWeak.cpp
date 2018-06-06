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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

const int N = 1234567;

ll a[N], t1[N], t2[N], tot[N], n, sz = 0; 
ll ans = 0;

void add(int which, int i, int v){
	for(; i < N; i += (i & -i)){
		if(which == 1){
			t1[i] += v;
		}else{
			t2[i] += v;
		}		
	}
}

ll get(int which, int i){
	ll res = 0;
	for(; i > 0; i -= (i & -i)){
		res += (which == 1 ? t1[i] : t2[i]);
	}
	return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> n;
    forn(i, n){
    	cin >> a[i];
    	tot[sz++] = a[i];
    }

    sort(tot, tot + sz);
    sz = unique(tot, tot + sz) - tot;
    forn(i, n) a[i] = lower_bound(tot, tot + sz, a[i]) - tot + 5;

    FILL(t1, 0);
    FILL(t2, 0);

    for(int i = n - 1; i >= 0; i--){
    	int p = get(1, a[i] - 1);
    	add(1, a[i], 1);
    	add(2, a[i], p);

    	ans += (ll)get(2, a[i] - 1);    	
    }

    cout << ans << endl;
    return 0;
}