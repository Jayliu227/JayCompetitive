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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    vi adj[n];
    ii target = make_pair(-1, -1);
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vi color;
    
    forn(i, n){
        int c;
        cin >> c;
        color.emplace_back(c);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            if(color[i] != color[adj[i][j]]){
                target = make_pair(i, adj[i][j]);
                break;
            }
        }
    }
    
    if(target.fi == -1 && target.se == -1){
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }
    
    vector<bool> visited(n, false);
    
    function<bool(int)> dfs = [&](int from){
        visited[from] = true;
        int c = color[from];
        for(int i = 0; i < adj[from].size(); i++) {
            int to = adj[from][i];            
            if(!visited[to]){
                if(color[to] != c) return false;
                if(!dfs(to)) {
                    return false;
                }                    
            }
        }
        return true;
    };
    
    function<bool(int)> solve = [&](int current){
        forn(i, n) visited[i] = false;
        visited[current] = true;
        for(int i = 0; i < adj[current].size(); i++){
            if(!dfs(adj[current][i])) {
                //cout << i << " " << edges[i].se << endl;
                return false;
            }                
        }
        return true;
    };
    
    if(solve(target.fi)){
        cout << "YES" << endl;
        cout << target.fi + 1 << endl;
    }else if(solve(target.se)){
        cout << "YES" << endl;
        cout << target.se + 1 << endl;
    }else{
        cout << "NO" << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}