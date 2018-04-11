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

/*
    let the occurence of a number be c;
    then there should be at least c - 1 that many elements different from the number
    so n = c + c - 1 if there is only two elements;
    n >= c + c - 1 if there are more, so 2c - 1 > n would make it impossible to get
    a permutation as required. thus for all c, c <= (n + 1)/2;
*/

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;
int a[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    FILL(a, 0);
    forn(i, n){
        int k = nxt();
        a[k]++;
    }        
    forn(i, 1005){
        if(a[i] > ((n + 1)/2)){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}