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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int m, n; int a, b, c, d;
    cin >> m >> n;
    cin >> a >> b;
    cin >> c >> d;

    bool ok = false;
    
    if((a + d) <= n && (max(b, c) <= m)) ok = true;
    if((a + c) <= n && (max(b, d) <= m)) ok = true;
    if((b + c) <= m && (max(a, d) <= n)) ok = true;
    if((b + d) <= m && (max(a, c) <= n)) ok = true;
    
    if((b + d) <= n && (max(a, c) <= m)) ok = true;
    if((b + c) <= n && (max(a, d) <= m)) ok = true;
    if((a + c) <= m && (max(b, d) <= n)) ok = true;
    if((a + d) <= m && (max(b, c) <= n)) ok = true;
    
    cout << (ok? "YES" : "NO") << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}