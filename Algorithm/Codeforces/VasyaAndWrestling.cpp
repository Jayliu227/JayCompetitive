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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    vi a, b;
    int n = nxt();
    ll acc = 0;
    int last;
    forn(i, n){        
        int m = nxt();
        if(m > 0){
            a.pb(m);
        }else{
            b.pb(-m);
        }
        
        acc += m;
        last = m;
    }
    
    if(acc > 0){
        cout << "first" << endl;
    }else if(acc < 0){
        cout << "second" << endl;
    }else{
        int i = 0;
        for(; i < min(a.size(), b.size()); i++){
            if(a[i] < b[i]){
                cout << "second" << endl;
                return 0;
            }else if(a[i] > b[i]){
                cout << "first" << endl;
                return 0;
            }
        }
        if(i == min(a.size(), b.size())){
            if(a.size() != b.size()){
                cout << ((a.size() > b.size())? "first" : "second") << endl;
            }else{
                cout << ((last > 0) ? "first" : "second") << endl;
            }
        }        
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}













