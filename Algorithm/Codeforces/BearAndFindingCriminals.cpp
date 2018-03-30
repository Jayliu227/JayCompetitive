#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define RI(x) int (x); cin >> (x)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

template<class T> void LOG(T s){
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
const int MODULO = (int) 1e10 + 7;

int cities[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    RI(n); RI(p);    
    forn(i, n){
        cin >> cities[i];
    }
    
    int res = cities[--p];
    int d = 1;
    int ds = min(p, n - p - 1);
    for(int i = 0; i < ds; i++){
        res += (cities[p - d] == 1 && cities[p + d] == 1) ? 2 : 0;
        d++;
    }

    if(p - d == -1){
        for(int i = p + d; i < n; i++) res += cities[i];
    }else{
        for(int i = p - d; i >= 0; i--) res += cities[i];
    }
    
    cout << res << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}




