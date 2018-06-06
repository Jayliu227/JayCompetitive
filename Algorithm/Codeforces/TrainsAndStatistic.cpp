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
const int N = 123456;
const int K = 24;

/*
    dp[i] means sum of p(i, j) where j is in range of (i + 1, n - 1);
    so the answer would be sum of dp[i] for i in range of (0, n - 1);
    transition func:
    define m as where a[m] is maximal in range (i + 1, a[i]);
    since we want to do greedy algorithm, we need to move to the place with maximal a[i];
    p(i, m) = 1;
    p(i, a[i]) = 1;
    p(m, a[i]) = 1; because a[m] >= a[i] since otherwise, we could've chosen a[i] as m and a[a[i]] >= a[i] + 1;
    therefore, dp[i] consists of three segments;
    i-----m-----a[i]-----(n-1)
    1. dp[m] includes segment[m + 1, n - 1];
    2. segment[i, m] would be m - i since all of p(i, j) where j is in (i + 1, m) is 1;
    3. but if we want to get to any station in range (a[i], n - 1), we need to take one more step to
        any position in (m + 1, a[i]), so we need n - 1 - a[i] that many extra steps;
    sum all of them up: dp[i] = dp[m] + m - i + n - 1 - a[i];
*/

int n;
int s[N];
// pair<a[m], m>
pair<int, int> st[N][K + 1];
ll dp[N] = {0};
int lg[N];

void init(){
    for(int i = 0; i < n; i++){
        st[i][0] = make_pair(s[i], i);
    }

    for(int j = 1; j <= K; j++){
        for(int i = 0; i + (1 << j) < N; i++){
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    lg[1] = 0;
    for(int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
}

int getmax(int l, int r){
    int j = lg[r - l + 1];
    auto a1 = st[l][j];
    auto a2 = st[r - (1 << j) + 1][j];
    return max(a1, a2).se;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cin >> n;
    forn(i, n - 1) {
        cin >> s[i];
        s[i]--;
    }
    s[n - 1] = n - 1;
    dp[n - 1] = 0LL;
    init();    
    ll ans = 0;
    for(int i = n - 2; i >= 0; i--){
        int m = getmax(i + 1, s[i]);
        dp[i] = dp[m] - (s[i] * 1LL - m) + n - i - 1;        
        ans += dp[i];       
    }
    cout << ans << endl;
    return 0;    
}