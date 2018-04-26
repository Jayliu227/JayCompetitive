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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

/*
    better way is simply to count number of nodes in two sets, l and r
    ans would be l * r - (n - 1)
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    vi adj[n];
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int color[n];
    FILL(color, -1);
    ll nofz = 0;
    ll nofo = 0;
    function<void(int)> dfs = [&](int u){
        for(int v = 0; v < adj[u].size(); v++){
            if(color[adj[u][v]] == -1){
                color[adj[u][v]] = 1 - color[u];
                if(color[adj[u][v]] == 1) nofo++;
                if(color[adj[u][v]] == 0) nofz++;
                dfs(adj[u][v]);
            }
        }
    };
    for(int i = 0; i < n; i++) if(color[i] == -1){        
        color[i] = 0;
        nofz++;
        dfs(i);
    }
    ll anso = 0;
    ll ansz = 0;
    for(int i = 0; i < n; i++) {
        if(color[i] == 0){
            anso += nofo - adj[i].size();
        }else{
            ansz += nofz - adj[i].size();
        }
    }
    cout << max(ansz, anso) << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}