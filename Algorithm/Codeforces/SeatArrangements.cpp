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

int a[2010][2010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n, m, k; cin >> n >> m >> k;
    forn(i,n) forn(j,m){
        char c; cin >> c;
        a[i][j] = (c == '*');
    }
    ll ans = 0;
    
    forn(i,n){
        int dots = 0;
        forn(j,m){
            if(a[i][j] == 1){
                ans += max(0, dots - k + 1);
                dots = 0;
            }else{
                dots++;
            }
        }
        ans += max(0, dots - k + 1);
    }

    forn(j,m){
        int dots = 0;
        forn(i,n){
            if(a[i][j] == 1){
                ans += max(0, dots - k + 1);
                dots = 0;
            }else{
                dots++;
            }
        }
        ans += max(0, dots - k + 1);
    }
    
    cout << ((k == 1) ? ans/2 : ans) << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}



















