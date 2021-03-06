#include<bits/stdc++.h>

using namespace std;

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
const int MOD = (int) 1e9 + 7;

string s, ok;
int n, k, b[2000] = {0}; 
ll h[2000000];

/*
	use another hash function simply do hs = hs * MOD + s[i];
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    cin >> s >> ok >> k;
    n = s.size();

    b[0] = 0;
    for(int i = 1; i <= n; i++){
    	b[i] = b[i - 1] + (ok[s[i - 1] - 'a'] - '0' + 1) % 2;
    }

    ll next = 0;
    for(int i = 1; i <= n; i++){
    	ll hs = 0;
    	for(int j = i; j <= n; j++){
    		if(b[j] - b[i - 1] > k) break;
    		hs = hs * MOD + s[j - 1];
    		h[next++] = hs;
    	}
    }

    sort(h, h + next);
    int res = unique(h, h + next) - h;
    cout << res << endl;

    return 0;
}