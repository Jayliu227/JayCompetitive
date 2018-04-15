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

int a[100000+5];
int n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    n = nxt(); k = nxt();
    char c;
    forn(i, n){
        cin >> c;
        a[i] = c == 'a';
    }            
    
    int ans = 0;
    int kk = k;
    int s = 0, e = 0;
    while(e < n){
        if(a[e] == 1){
            e++;
        }else{
            if(kk > 0){
                kk--;
                e++;
            }else{
                while(a[s] == 1) s++;
                s++;
                e++;
            }
        }
        ans = max(ans, e - s);
    }
    
    s = 0, e = 0, kk = k;
    while(e < n){
        if(a[e] == 0){
            e++;
        }else{
            if(kk > 0){
                kk--;
                e++;
            }else{
                while(a[s] == 0) s++;
                s++;
                e++;
            }
        }
        ans = max(ans, e - s);
    }
    
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}













