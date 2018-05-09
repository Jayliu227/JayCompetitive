#include<bits/stdc++.h>

using namespace std;

#define pb push_back
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

inline int nxt(){ int x; cin >> x; return x; }

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
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
    int n, m, t;
    cin >> n >> m >> t;
    ll dp[100][100];
    FILL(dp, -1);
    function<ll(int,int)> bi = [&](int n, int k){
        if(k == 0 || k == n) return 1LL;
        if(dp[n][k] != -1) return dp[n][k];
        return dp[n][k] = bi(n - 1, k - 1) + bi(n - 1, k);    
    };    
    ll ans = 0;
    for(int i = 4; i <= t - 1; i++){
        int j = t - i;
        if(i >= i && i <= n && j >= 0 && j <= m)
            ans += (ll)bi(n, i) * (ll)bi(m, j);
    }
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}