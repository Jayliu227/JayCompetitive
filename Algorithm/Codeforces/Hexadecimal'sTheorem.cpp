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

/*
    simply output 0 0 n
*/

int fb[10000000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    if(n == 0){
        cout << "0 0 0" << endl;
        return 0;
    }else if(n == 1){
        cout << "1 0 0" << endl;
        return 0;
    }
    fb[0] = 0, fb[1] = fb[2] = 1;
    int i = 2;
    while(fb[i] != n){
        fb[i + 1] = fb[i] + fb[i - 1];
        i++;
    }    
    int a, b, c;
    a = fb[max(i - 2, 0)];
    b = fb[max(i - 2, 0)];
    c = fb[max(i - 3, 0)];
    cout << a << " " << b << " " << c << endl;   

#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}