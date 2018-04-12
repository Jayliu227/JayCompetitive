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

struct exam{
    int g, c;
    operator< (exam& another) { return c < another.c; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    ll n, r, avg; cin >> n >> r >> avg;    
    ll sum = 0;
    vector<exam> E(n);
    forn(i, n){
        int a, b; cin >> a >> b;
        E[i].g = a, E[i].c = b;
        sum += a;
    }      

    sort(ALL(E));
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
        if(sum >= avg * n)
            break;
        ll bk = min(avg*n - sum, r - E[i].g);
        ans += bk * E[i].c;
        sum += bk;
    }
    
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}