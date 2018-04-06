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
vi visited;
bool ok = false;
int n, l;

void dfs(int i){
    if(i < n)
        visited[i] = true;
    ok |= (adjList[i].size() > 0);
    for(int j = 0; j < adjList[i].size(); j++) if(adjList[i][j] >= n || visited[adjList[i][j]] == false){
        dfs(adjList[i][j]);
    }   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> n >> l;
    adjList.resize(n + l);
    forn(i, n + l) adjList[i] = vector<int>();
    visited.resize(n);
    forn(i, n) visited[i] = false;
    int nol, lan;
    forn(i, n){
        cin >> nol;
        forn(j, nol){
            cin >> lan;
            lan--;
            adjList[i].pb(lan + n);
            adjList[lan + n].pb(i);
        }
    }            

    int res = 0;
    
    for(int i = 0; i < n; i++) if(visited[i] == false){
        res++;
        dfs(i);
    }
    
    if(ok){
        cout << res - 1 << endl;
    }else{
        cout << n << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}