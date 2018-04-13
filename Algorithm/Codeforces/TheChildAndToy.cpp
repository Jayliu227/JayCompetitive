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

struct Vertex{
    vi adj;
    ll energy = 0;
    ll total = 0;
};

vector<Vertex> vs;
vector<bool> used;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    ll ans = 0;
    int n, m; cin >> n >> m;
    vs.assign(n, Vertex());
    used.assign(n, false);
    forn(i, n){
        cin >> vs[i].energy;
    }     
    forn(i, m){
        int u, v; cin >> u >> v;
        u--, v--;
        vs[u].adj.pb(v);
        vs[v].adj.pb(u);
    }
    forn(i, n){
        forn(j, vs[i].adj.size()){
            vs[vs[i].adj[j]].total += vs[i].energy;
        }
    }
    
    for(int k = 0; k < n - 1; k++){
        int mn = 0, mni = -1, s = 0;
        for(int i = 0; i < n; i++) if(used[i] == false){
            if(vs[i].energy > mn){
                mn = vs[i].energy;
                mni = i;
                s = vs[i].adj.size();
            }else if(vs[i].energy == mn){
                if(vs[i].adj.size() >= s){
                    mn = vs[i].energy;
                    mni = i;
                    s = vs[i].adj.size();
                }
            }
        }            
    
        ans += vs[mni].total;
        used[mni] = true;
        for(int j = 0; j < vs[mni].adj.size(); j++) if(used[vs[mni].adj[j]] == false){
            vs[vs[mni].adj[j]].total -= vs[mni].energy;
        }                        
    }
    
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}



















