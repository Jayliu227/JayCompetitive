#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl

inline int nxt(){ int x; cin >> x; return x; }

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
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
    int n;
    cin >> n;
    vvi a(n, vi());
    forn(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--,v--;
        a[v].pb(u);
        a[u].pb(v);
    }
    vi c(n, -1);
    int ccnt = 0;
    function<void(int)> dfs = [&](int current){
        vi used;
        used.pb(c[current]);
        for(int i = 0; i < a[current].size(); i++) if(c[a[current][i]] != -1){
            used.pb(c[a[current][i]]);
        }    
        sort(ALL(used));
        int k = 1;
        for(int i = 0; i < a[current].size(); i++) if(c[a[current][i]] == -1){
            while(binary_search(ALL(used), k)) k++;
            ccnt = max(k, ccnt);
            c[a[current][i]] = k;
            dfs(a[current][i]);
            k++;
        }
    };
    for(int i = 0; i < n; i++) if(c[i] == -1){ 
        c[i] = 1;
        dfs(i); 
    }
    cout << ccnt << endl;
    for(int i = 0; i < n; i++){
        if(i == 0){
            cout << c[i];
        }else{
            cout << " " << c[i];
        }
    }
    cout << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}