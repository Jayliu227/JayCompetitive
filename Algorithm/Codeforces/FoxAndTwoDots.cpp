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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

int a[51][51];
int dfs_num[51][51];
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

bool ok = false;
int n, m;
int ti, tj;

void dfs(int i, int j){    
    for(int k = 0; k < 4; k++){
        int ni = i + x[k];
        int nj = j + y[k];
        
        if(ni >= 0 && ni < n && nj >= 0 && nj < m){
            if(a[i][j] != a[ni][nj])
                continue;
            
            if(dfs_num[ni][nj] != -1 && dfs_num[i][j] - dfs_num[ni][nj] >=3){
                ok = true;
                return;
            }                
        
            if(dfs_num[ni][nj] == -1){
                dfs_num[ni][nj] = dfs_num[i][j] + 1;
                dfs(ni, nj);
            }
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
    n = nxt(); m = nxt();
    forn(i,n) forn(j, m){
        char c; cin >> c;
        a[i][j] = (c - 'A') + 1;
    }        
    FILL(dfs_num, -1);
    
    forn(i, n) forn(j, m){
        if(dfs_num[i][j] == -1){
            dfs_num[i][j] = 1;
            dfs(i, j);
        }
    }
    
    cout << (ok? "Yes" : "No") << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}