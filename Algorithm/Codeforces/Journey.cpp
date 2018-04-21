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

int n;
vvi adj_list;
vi dfs_num;

double dfs(int i){    
    int ways = 0;
    double res = 0;
    for(int j = 0; j < adj_list[i].size(); j++) if(dfs_num[adj_list[i][j]] == -1){
        ways++;
        dfs_num[adj_list[i][j]] = dfs_num[i] + 1;
        res += dfs(adj_list[i][j]);
    }
    if(ways == 0){
        return dfs_num[i];
    }else{
        return res / ways;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    n = nxt();
    adj_list.resize(n);
    dfs_num.resize(n);
    forn(i, n) adj_list[i] = vi();
    forn(i, n) dfs_num[i] = -1;
    int u, v;
    forn(i, n - 1){
        cin >> u >> v;
        u--, v--;
        adj_list[v].pb(u);
        adj_list[u].pb(v);
    }
    dfs_num[0] = 0;
    cout << dfs(0) << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}