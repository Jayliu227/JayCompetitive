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
const int N = (int) 1e5 + 100;

vector<ll> tp;
ll a[N], n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    for(ll i = 0; (1LL << i) <= 1e10; i++){
    	tp.emplace_back(1LL << i);
    }

    cin >> n;
    forn(i, n) cin >> a[i];
    ll ans = 0;
    map<ll, int> m;
    for(int i = 0; i < n; i++){
    	for(auto k : tp){
    		if(k < a[i]) continue;
    		ans += m[k - a[i]];
    	}
    	m[a[i]]++;
    }

    cout << ans << endl;
    return 0;
}