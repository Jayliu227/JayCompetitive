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

/*
    two possible situations: we either start with -1 or 1
    so create two arrays each of which deals with one situation.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    vector<ll> b(n);
    vector<ll> c(n);
    forn(i, n - 1){
        if(i&1){
            b[i] = abs(a[i] - a[i + 1]);
            c[i] = -abs(a[i] - a[i + 1]);
        }else{
            b[i] = -abs(a[i] - a[i + 1]);
            c[i] = abs(a[i] - a[i + 1]);
        } 
    }
    ll ans = 0;
    ll sum1 = 0, sum2 = 0;
    forn(i, n - 1){
        sum1 += b[i];
        if(sum1 > ans) ans = sum1;
        if(sum1 < 0) sum1 = 0;
        sum2 += c[i];
        if(sum2 > ans) ans = sum2;
        if(sum2 < 0) sum2 = 0;
    }
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}