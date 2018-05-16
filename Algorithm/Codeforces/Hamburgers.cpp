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

inline long long maxx(long long a, long long b){ return a > b ? a : b; }
inline long long minn(long long a, long long b){ return a < b ? a : b; }

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
        
    string formula;
    ll a = 0, b = 0, c = 0;
    ll sa, sb, sc;
    ll pa, pb, pc;
    ll budget;
    cin >> formula;
    cin >> sa >> sb >> sc;
    cin >> pa >> pb >> pc;
    cin >> budget;

    for(auto i : formula) {
        a += i == 'B';
        b += i == 'S';
        c += i == 'C';
    }

    ll ans = 0;

    while((sa > 0 && a != 0) || (sb > 0 && b != 0) || (sc > 0 && c != 0)){
        ll required_a = maxx(0, a - sa);
        ll required_b = maxx(0, b - sb);
        ll required_c = maxx(0, c - sc);
        sa -= a, sb -= b, sc -= c;
        chkmax(sa, 0LL);
        chkmax(sb, 0LL);
        chkmax(sc, 0LL);
        assert(sa >= 0 && sb >= 0 && sc >= 0);
        ll sum = pa * required_a + pb * required_b + pc * required_c; 
        if(sum <= budget){
            ans++;
            budget -= sum;
        }else{
            cout << ans << endl;
            return 0;
        }
    }   

    ll required = pa * a + pb * b + pc * c;
    ans += budget / required;
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif    
    return 0;
}