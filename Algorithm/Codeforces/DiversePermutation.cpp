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
const int MODULO = (int) 1e9 + 7;

/*
    a better, easier to think about idea is to first construct a sequence
    with k distinct difference. and then we take the first k elements, and
    the rest should be in order because the difference between the rest of 
    the sequence should be equal to 1.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    vector<int> res;
    RI(n); RI(k);

    for(int i = 0; i < n - k; i++){
        res.pb(i + 1);
    }    
    
    int h = n, l = n - k + 1;
    while(h >= l){
        res.pb(h--);
        res.pb(l++);
    }
    res.resize(n);
    
    for(int i = 0; i < n; i++){
        if(i == 0)
            cout << res[i];
        else
            cout << " " << res[i];
    }

    cout << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}