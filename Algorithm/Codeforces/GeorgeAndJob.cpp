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

/*
    First we need to identify its max complexity, and in this case, it should be n^2;
    and i shouldve figured out that one dp structure is enough because we can always
    just consider it as the maximum we can get when we end at this index, kth group.
*/

ll dp[5010][5010];
ll a[5010];
int n, m, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> n >> m >> k;
    forn(i, n) cin >> a[i + 1];
    a[0] = 0;
    FILL(dp, 0);
    for1(i, n + 1){
        a[i] += a[i - 1];
    }
    ll ans = 0;         
    for(int i = m; i <= n; i++){
        for(int j = 1; j <= k; j++){
            ll current = a[i] - a[i - m];
            dp[i][j] = dp[i - m][j - 1] + current;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);          
            ans = max(ans, dp[i][j]);
        }
    }    
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}













