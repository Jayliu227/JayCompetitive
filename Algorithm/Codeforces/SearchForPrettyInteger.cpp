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

int a[10];
int b[10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    RI(n); RI(m);
    forn(i, n) cin >> a[i];
    forn(i, m) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);

    int am = 0, bm = 0;
    if(a[0] == b[0]){
        cout << a[0] << endl;
    }else{
        while(am < n && bm < m){
            if(a[am] < b[bm]){
                am++;
            }else if(a[am] > b[bm]){
                bm++;
            }else{
                break;
            }
        }
        if(a[am] == b[bm])
            cout << min(a[am], min(a[0], b[0]) * 10 + max(a[0], b[0])) << endl;
        else
            cout << min(a[0], b[0]) * 10 + max(a[0], b[0]) << endl;
    }        

#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}