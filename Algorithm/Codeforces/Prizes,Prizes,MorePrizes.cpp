#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl

template<typename T> inline bool chkmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

/*
    trap: cant naively decrement one prize at a time;
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    vi days(n);
    forn(i, n) cin >> days[i];
    vector<ll> ans(5, 0);
    vi prizes;
    forn(i, 5){
        int cost;
        cin >> cost;
        prizes.pb(cost);
    }
    ll value = 0;
    forn(i, n){
        value += (ll)days[i];
        int sen = 4;
        while(sen >= 0){
            if(prizes[sen] <= value){
                int times = value / prizes[sen];
                value -= times * prizes[sen];
                ans[sen] += times;
            }else{
                sen--;
            }               
        }
    }
    for(int i = 0; i < 5; i++){
        if(i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << endl;
    cout << value << endl;
#ifdef LOCAL_COMPILATION    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif    
    return 0;
}