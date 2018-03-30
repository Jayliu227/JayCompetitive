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

int h[100010];
int a[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    RI(n);
    forn(i, n){
        cin >> h[i];
    }        

    int mx = 0;
    for(int i = n - 1; i >= 0; i--){
        if(h[i] > mx){
            a[i] = 0;
            mx = h[i];
        }else{
            a[i] = mx - h[i] + 1;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(i == 0){
            cout << a[i];
        }else{
            cout << " " << a[i];
        }
    }
    
    cout << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}