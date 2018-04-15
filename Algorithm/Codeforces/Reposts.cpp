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

unordered_map<string, int> index_map;
int res = 1, n, r, cnt = 0;
vii indegree;
int relation[210][210];

dfs(int u, int c){
    res = max(res, c);    
    for(int v = 0; v < cnt; v++){
        if(relation[u][v] == 1){
            dfs(v, c + 1);
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
    r = nxt();
    FILL(relation, 0);
    
    forn(i, r){
        string u, kk, v; cin >> u >> kk >> v;
        for(int i = 0; i < u.size(); i++) u[i] = tolower(u[i]);
        for(int i = 0; i < v.size(); i++) v[i] = tolower(v[i]);
        
        if(index_map[u] == 0){
            index_map[u] = ++cnt;
            indegree.pb(ii(0, index_map[u] - 1));
        }
        
        if(index_map[v] == 0){
            index_map[v] = ++cnt;
            indegree.pb(ii(0, index_map[v] - 1));
        }        
        
        ++indegree[index_map[v] - 1].fi;
        relation[index_map[u] - 1][index_map[v] - 1] = 1;
    }    

    sort(ALL(indegree));    
    
    for(int i = 0; i < indegree.size(); i++) if(indegree[i].fi == 0){
        dfs(indegree[i].se, 1);
    }
    cout << res << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}













