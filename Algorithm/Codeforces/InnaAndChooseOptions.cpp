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
    int tc = nxt();
    while(tc--){
        string s;
        cin >> s;
        vi ans;
        for(int i = 1; i <= 12; i++) if(12 % i == 0){
            int R = i;
            int C = 12 / i;            
            // check columns
            for(int c = 0; c < C; c++){
                bool ok = true;
                for(int r = 0; r < R; r++){
                    ok &= s[r * C + c] == 'X';
                }
                if(ok){
                    ans.pb(R);
                    break;
                }
            }
        }
        cout << ans.size() << " ";
        for(auto i : ans){
            cout << i << "x" << 12/i << " ";
        }
        cout << endl;
    }        
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}