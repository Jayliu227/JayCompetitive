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

/*
    to check whether a given undirected graph is a clique.
    we can simply run dfs to count edges and vertices
    if vertices * (vertices - 1) == edges * 2
    then it is a clique;
    overflow might happen in large graph
    remember to count the back edges
*/

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

int n, m;
int dfs_num[150000];
vvi adjList;
int edge_count, vertex_count;

void dfs(int i){
    vertex_count++;
    forn(j, adjList[i].size()){        
        if(dfs_num[adjList[i][j]] == -1){            
            dfs_num[adjList[i][j]] = dfs_num[i] + 1;
            edge_count++;
            dfs(adjList[i][j]);
        }else if(dfs_num[adjList[i][j]] < (dfs_num[i] - 1)){
            edge_count++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> n >> m;    
    adjList.resize(n);
    forn(i, n) adjList[i] = vi();
    forn(i, m){
        int u, v; cin >> u >> v;
        u--, v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    FILL(dfs_num, -1);
    
    forn(i,n) if(dfs_num[i] == -1){
        edge_count = 0, vertex_count = 0;
        dfs_num[i] = 0;
        dfs(i);
        if(((ll)vertex_count * ((ll)vertex_count - 1LL)) != (ll)edge_count * 2LL){
            cout << "NO" << endl;
            return 0;            
        }
    }    
    cout << "YES" << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}