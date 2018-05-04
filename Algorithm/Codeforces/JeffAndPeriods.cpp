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
    int n = nxt();
    map<int, vi> m;
    forn(i, n){
        int c = nxt();
        m[c].pb(i);
    }
    vii res;
    for(auto &n : m){
        bool ok = true;
        int diff = -1;
        for(int i = 0; i < n.second.size() - 1; i++){
            int ndiff = n.second[i + 1] - n.second[i];
            if(diff == -1){ 
                diff = ndiff;
                continue;
            }    
            if(diff != ndiff) ok = false;
        }
        if(ok){
            res.emplace_back(n.first, max(diff, 0));
        }
    }
    cout << res.size() << endl;
    for(auto i : res){
        cout << i.fi << " " << i.se << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}