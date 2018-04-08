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
int a[16];

/*
    when n < 30, 2^n might work.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    forn(i, n) cin >> a[i];
    int res = 0;
    for(int i = 0; i < (1 << n); i++){
        int s = 0;
        int mx = 0;
        int mn = INF;
        for(int j = 0; j < n; j++) if((i & (1 << j)) != 0){
            s += a[j];
            mx = max(a[j], mx);
            mn = min(a[j], mn);
        }
        res += (abs(mx - mn) >= x && s >= l && s <= r);
    }
    
    cout << res << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}