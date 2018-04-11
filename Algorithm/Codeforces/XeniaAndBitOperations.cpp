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

ll a[17][(1 << 17)];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt(); int q = nxt();
    FILL(a, 0);        
    forn(i, (1 << n)) cin >> a[0][i];    
    
    for(int i = 0; i < n; i++){                
        for(int j = 0; j < (1 << (n - i)); j++){
            if(i&1){
                // xor
                a[i+1][j/2] = a[i][j] ^ a[i][j + 1]; 
            }else{
                // or
                a[i+1][j/2] = a[i][j] | a[i][j + 1];
            }
            j++;
        }
    }
    
    while(q--){
        int p, b; cin >> p >> b;
        p--;
        if(p&1){
            a[1][p/2] = (a[0][p] = b) | (a[0][p - 1]);
            
        }else{
            a[1][p/2] = (a[0][p] = b) | (a[0][p + 1]);
        }
        
        p /= 2;
        
        for(int i = 1; i < n; i++){
            if(p&1)
                a[i + 1][p/2] = (i&1) ? (a[i][p] ^ a[i][p - 1]) : (a[i][p] | a[i][p - 1]);
            else    
                a[i + 1][p/2] = (i&1) ? (a[i][p] ^ a[i][p + 1]) : (a[i][p] | a[i][p + 1]);
            
            p /= 2;
        }
        
        cout << a[n][0] << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}