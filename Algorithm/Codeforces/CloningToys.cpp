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

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
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
    int c = nxt(); int o = nxt();
    if(o == 0){
        cout << "No" << endl;
    }else if(o == 1){
        if(c == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        } 
    }else{
        cout << ((c >= (o - 1) && (c - o + 1) % 2 == 0) ? "Yes" : "No") << endl;
    }
    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}