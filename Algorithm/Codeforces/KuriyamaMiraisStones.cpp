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

ll an[100010];
ll ai[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    RI(n);
    forn(i,n){
        int in; cin >> in;
        an[i + 1] = (ll)in;
        ai[i + 1] = (ll)in;
    }            
    
    an[0] = ai[0] = 0;
    sort(ai + 1, ai + n + 1);
    
    for(int i = 1; i <= n; i++){
        an[i] += an[i - 1];
        ai[i] += ai[i - 1];
    }

    RI(q);
    
    int t, l, r;
    while(q--){
        cin >> t >> l >> r;
        if(t == 1){
            cout << an[r] - an[l - 1] << endl;                
        }else{
            cout << ai[r] - ai[l - 1] << endl;
        }
    }
    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}









