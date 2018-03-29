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

void LOG(string s){
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
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e4;

int n, m;
int res;
vector<int> g[100020];
int cat[100020];

/*
    key point here is, if a leaf's only neighbor is its parent!
*/

void dfs(int u, int prev, int c){
    if(c > m) return;
    int ok = 1;
    for(int v = 0; v < g[u].size(); v++) if(g[u][v] != prev){
        ok = 0;
        dfs(g[u][v], u, c * cat[g[u][v]] + cat[g[u][v]]);
    }
    res += ok;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> n >> m;
    forn(i, n) cin >> cat[i];
    forn(i, n - 1){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    res = 0;
    dfs(0, -1, cat[0]);
    cout << res << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}










