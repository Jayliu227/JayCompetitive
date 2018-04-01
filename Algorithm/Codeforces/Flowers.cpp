#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define RI(x) int (x); cin >> (x)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

template<class T> void LOG(T s){
#ifdef LOCAL_COMPILATION
    cout << "DEBUG: " << s << endl;
#endif
}

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

int dp[100010];
vii ab;
int t, k, a, b;

int solve(int r){
    if(r == 0)
        return 1;
    if(r < 0) 
        return 0;
    if(dp[r] != -1) return dp[r];
    
    int ways = 0;
    ways += solve(r - 1) % MODULO;
    ways %= MODULO;
    ways += solve(r - k) % MODULO;
    ways %= MODULO;
    return dp[r] = ways;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    FILL(dp, -1);
    cin >> t >> k;
    ab.resize(t);
    int mx = 0;
    forn(i, t){
        cin >> a >> b;
        mx = max(mx, b);
        ab[i] = mp(a,b);
    }        
    solve(mx);
    dp[0] = 0;    
    for(int i = 1; i <= mx; i++){
        dp[i] += dp[i - 1] % MODULO;
        dp[i] %= MODULO;
        LOG(dp[i]);
    }
    
    for(auto i : ab){
        int a = i.fi, b = i.se;
        if(a == 1){
            cout << dp[b] << endl;
        }else{
            if(dp[b] > dp[a - 1]){
                cout << dp[b] - dp[a - 1] << endl;
            }else{
                cout << (dp[b] - dp[a - 1] + MODULO) % MODULO << endl;
            }
        }
    }
        
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}






