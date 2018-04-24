#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'

using namespace std;

inline int nxt(){ int x; cin >> x; return x; }

template<class T> inline void LOG(T s){
#ifdef LOCAL_COMPILATION
    cout << "DEBUG: " << s << endl;
#endif
}

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    vector<pair<int, int>> dp(n);
    dp[0].fi = 1;
    dp[0].se = 1;
    int mx = max(dp[0].fi, dp[0].se);
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]){
            dp[i].fi = dp[i - 1].fi + 1;
            dp[i].se = dp[i - 1].se + 1;
        }else if(a[i] > a[i - 1]){
            dp[i].fi = dp[i - 1].se + 1;
            dp[i].se = 1;
        }else{
            dp[i].fi = 1;
            dp[i].se = dp[i - 1].fi + 1;
        }
        mx = max(mx, dp[i].fi);
        mx = max(mx, dp[i].se);
    }    
    cout << mx << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}