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

template<class T> void LOG(T s){
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
vvi adjList;
vi color;
int n, e;
vi green, red;
bool ok = true;

void dfs(int i){
    for(int j = 0; j < adjList[i].size(); j++){
        int next = adjList[i][j];
        if(color[next] == -1){
            color[next] = 1 - color[i];
            if(color[next] == 1)
                red.pb(next);
            else
                green.pb(next);
            dfs(next);                
        }else if(color[next] == color[i]){
            ok = false;
            return;
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
    cin >> n >> e;
    adjList.resize(n);
    color.resize(n);
    forn(i, n) color[i] = -1;
    int u, v;
    forn(i, e){
        cin >> u >> v;
        u--, v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }            

    forn(i, n) if(color[i] == -1){
        color[i] = 1;
        red.pb(i);
        dfs(i);
    }
    
    if(ok){
        cout << red.size() << endl;
        for(int i = 0; i < red.size() ; i++){
            if(i == 0)
                cout << (red[i] + 1);
            else
                cout << " " << (red[i] + 1);
        }
        cout << endl;
        cout << green.size() << endl;
        for(int i = 0; i < green.size(); i++){
            if(i == 0)
                cout << (green[i] + 1);
            else
                cout <<  " " << (green[i] + 1);
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}