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
    int n = nxt();
    int l[n + 2], r[n + 2];
    ll a[n + 2];
    l[0] = l[n + 1] = r[0] = r[n + 1] = 0;    
    a[0] = a[n + 1] = 0;    
    int mx = 0;
    for(int i = 1; i <= n; i++){ 
        cin >> a[i];
        if(a[i] > a[i - 1])
            l[i] = l[i - 1] + 1;
        else
            l[i] = 1;            
    }
    
    for(int i = n; i >= 1; i--){
        if(a[i] < a[i + 1])
            r[i] = r[i + 1] + 1;
        else
            r[i] = 1;
    }             
    
    for(int i = 1; i < n + 1; i++){
        if(a[i - 1] + 1 < a[i + 1]){
            mx = max(mx, l[i - 1] + 1 + r[i + 1]);
        }else{
            mx = max(mx, l[i - 1] + 1);
            mx = max(mx, r[i + 1] + 1);
        }
    }
    cout << mx << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}



















