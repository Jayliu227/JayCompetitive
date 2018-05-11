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
    key observation: flipping a segment is equal to
    flipping the whole prefix up to the end of this segment
    in terms of the length of the alternating digits.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n; 
    cin >> n;
    string s;
    cin >> s;
    vi a(n);
    forn(i, n) a[i] = s[i] == '1';
    int zs = 0, os = 0;
    int zsc = 0, osc = 1;
    for(int i = 0; i < n; i++){
        if(a[i] == 0 && zsc == 0) zs++, zsc = 1 - zsc;
        else if(a[i] == 1 && zsc == 1) zs++, zsc = 1 - zsc;
        if(a[i] == 1 && osc == 1) os++, osc = 1 - osc;
        else if(a[i] == 0 && osc == 0) os++, osc = 1 - osc;
    }
    int ans = max(os, zs);
    int ones = 0, zeros = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]){
            ones += a[i] == 1;
            zeros += a[i] == 0;
        }
    }      
    cout << ans + min(ones + zeros, 2) << endl;
#ifdef LOCAL_COMPILATION    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif    
    return 0;
}