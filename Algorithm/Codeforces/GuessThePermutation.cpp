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
    vi ans(n, 0);
    vi remain(n);
    forn(i, remain.size()) remain[i] = i + 1;
    forn(i, n){
        unordered_map<int, int> freq;
        bool found = false;
        forn(j, n){
            int c = nxt();
            if(!found){
                ++freq[c];
                if(freq[c] > 1){
                    ans[i] = c;
                    remain[c - 1] = 0;                
                    found = true;
                }
            }                
        }
    }    
    sort(RALL(remain));
    int inc = 0;
    for(int i = 0; i < ans.size(); i++) if(ans[i] == 0){
        ans[i] = remain[inc++];
    }        
    for(int i = 0; i < ans.size(); i++){
        if(i == 0)
            cout << ans[i];
        else
            cout << " " << ans[i];            
    }
    cout << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}