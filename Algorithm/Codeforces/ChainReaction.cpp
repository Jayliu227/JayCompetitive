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
    use dp: dp[i] means the max # of beacons that won't get
    destroyed in range [0, i]
    thus dp[i] = dp[i - 1] + 1 if there is no beacon at ith position
               = dp[i - range[i] - 1] + 1 if there is a beacon
    ans = n - max(dp[i]) for all i               
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    vii pos;
    vi range;
    forn(i, n){
        int p, r;
        cin >> p >> r;
        pos.emplace_back(p, i);        
        range.push_back(r);
    }
    sort(ALL(pos));
    int ans = n - 1;
    vi broken(n);
    broken[0] = n - 1;
    for(int i = 1; i < n; i++){
        auto lpos = *lower_bound(pos.begin(), pos.begin() + i, make_pair(pos[i].fi - range[pos[i].se], -1));
        int index = lower_bound(ALL(pos), lpos) - pos.begin();        

        if(index - 1 >= 0){
            broken[i] = broken[index - 1] - 1;
        }else{
            broken[i] = n - 1;
        }
        //debug2(i, broken[i]);
        chkmin(ans, broken[i]);
    }
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif    
    return 0;
}