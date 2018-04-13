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

const ll INF = (ll)(1LL << 60);
const int MODULO = (int) 1e9 + 7;

ll dp[100000 + 5][2];
int cost[100000 + 5];
string s[100000 + 5];
string sr[100000 + 5];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();

    forn(i, n){
        cin >> cost[i];
    }
    forn(i, n){
        string ss; cin >> ss;
        s[i] = ss;
        sr[i] = string(RALL(ss));
    }

    dp[0][0] = 0, dp[0][1] = cost[0];
    
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i][1] = INF;
        if(s[i] >= s[i - 1] && s[i] >= sr[i - 1]){
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
        }else if(s[i] >= s[i - 1]){
            dp[i][0] = dp[i - 1][0];
        }else if(s[i] >= sr[i - 1]){
            dp[i][0] = dp[i - 1][1];
        }
        if(sr[i] >= s[i - 1] && sr[i] >= sr[i - 1]){
            dp[i][1] = cost[i] + min(dp[i - 1][0], dp[i - 1][1]);
        }else if(sr[i] >= s[i - 1]){
            dp[i][1] = cost[i] + dp[i - 1][0];
        }else if(sr[i] >= sr[i - 1]){
            dp[i][1] = cost[i] + dp[i - 1][1];
        }
    }
    
    LOG(dp[n - 1][0]); LOG(dp[n - 1][1]);
    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}



















