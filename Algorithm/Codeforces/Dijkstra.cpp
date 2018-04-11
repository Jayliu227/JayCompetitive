#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

inline int nxt(){ int x; cin >> x; return x; }

template<class T> inline void LOG(T s){
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

/*
    dist should use ll instead of int to deal with large weight
*/

vector<vector<pair<int,int>>> adjList;
int parent[100010];
ll dist[100010];

void reconstruct(int i){    
    if(parent[i] == -1){
        cout << i + 1;
        return;
    }
    reconstruct(parent[i]);
    cout << " " << i + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n, m; cin >> n >> m;
    forn(i, n) adjList.pb(vector<pair<int,int>>());
    int u, v, w;
    while(m--){
        cin >> u >> v >> w;
        u--, v--;
        adjList[u].pb({v,w});
        adjList[v].pb({u,w});
    }            
    
    for(int i = 0; i < n; i++) dist[i] = (1LL << 60), parent[i] = -1;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[0] = 0;
    
    pq.push({0, 0});
    
    while(!pq.empty()){
        auto c = pq.top(); pq.pop();
        if(c.fi > dist[c.se])
            continue;
        int u = c.se;
        for(int i = 0; i < adjList[u].size(); i++){
            auto j = adjList[u][i];
            int v = j.fi; int w = j.se;
            if(dist[u] + w < dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }            
    }
    
    if(parent[n - 1] == -1)
        cout << -1;
    else
        reconstruct(n - 1);
    cout << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}