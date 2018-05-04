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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    forn(i, n) cin >> a[i];
    vector<bool> removed(m, false);
    int ans = 0;
    for(int c = 0; c < m; c++){
        bool alright = true;
        for(int i = 0; i < n - 1; i++){
            string current = "";
            string next = "";
            for(int p = 0; p <= c; p++) if(!removed[p]){
                current += a[i][p];
                next += a[i + 1][p];
            }            
            if(current > next){
                alright = false;
                break;
            }
        }
        if(!alright){
            removed[c] = true;
            ans++;
        }
    }
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}