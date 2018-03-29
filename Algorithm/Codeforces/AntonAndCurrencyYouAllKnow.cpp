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
const int maxn = (int) 1e4;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    string n; cin >> n;
    bool ok = false;
    int index = -1;
    for(int i = 0; i < n.size() - 1; i++){
        if((n[i] - '0') % 2 == 0){
            ok = true;
            if((n[i] - '0') < (n[n.size() - 1] - '0')){
                int temp = n[i];
                n[i] = n[n.size() - 1];
                n[n.size() - 1] = temp;
                
                cout << n << endl;
                return 0;
            }else{
                index = i;
            }
        }
    }
    
    if(!ok){
        cout << -1 << endl;
    }else{
        int temp = n[index];
        n[index] = n[n.size() - 1];
        n[n.size() - 1] = temp;
                
        cout << n << endl;
    }
    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}