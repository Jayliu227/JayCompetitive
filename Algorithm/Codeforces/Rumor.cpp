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
    int n, p;
    cin >> n >> p;
    vi gold(n);
    vvi friends(n);
    forn(i, n) cin >> gold[i];
    forn(i, p){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        friends[a].pb(b);
        friends[b].pb(a);        
    }
    vi heard(n, false);
    ll ans = 0;
    function<int(int)> dfs = [&](int current){
        heard[current] = true;
        int mn = gold[current];
        for(int i = 0; i < friends[current].size(); i++) if(!heard[friends[current][i]]){
            mn = min(mn, dfs(friends[current][i]));
        }
        return mn;
    };
    for(int i = 0; i < n; i++) if(!heard[i]){
        ans += (ll)dfs(i);
    }
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}