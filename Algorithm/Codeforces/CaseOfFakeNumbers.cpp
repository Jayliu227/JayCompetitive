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
    there is only one solution in this case,
    so we can simply find such case as we know the initial position and its desired position
    after we go to that stage, we can do a linear time check to see if this works or not.
*/

int gear[1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    RI(n);
    forn(i, n) cin >> gear[i];

    for(int i = 0; i <= n; i++){
        bool ok = true;
        for(int j = 0; j < n; j++){
            if(gear[j] != j){
                ok &= false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
        for(int j = 0; j < n; j++){
            if(j % 2 == 0){
                gear[j] = (gear[j] + 1) % n;
            }else{
                gear[j] = (gear[j] - 1 + n) % n;
            }
        }
    }    

    cout << "No" << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}