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
    int vs, ve, t, d;
    cin >> vs >> ve >> t >> d;
    vvi dp(t, vi(10000, -1));
    function<int(int, int)> solve = [&](int second, int speed){
        if(second == t - 1){
            if(speed == ve){
                return ve;
            }else{
                return -1000000;
            }
        }
        if(dp[second][speed] != -1) return dp[second][speed];
        int mx = -1000000;
        for(int i = max(speed - d, 0); i <= speed + d; i++){
            mx = max(mx, solve(second + 1, i) + speed);
        }
        return dp[second][speed] = mx;
    };
    
    cout << solve(0, vs) << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}