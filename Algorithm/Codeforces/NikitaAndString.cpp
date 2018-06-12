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

typedef long long ll;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;
const int N = 6000;

string s;
int n, b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> s;
    n = s.size();

    b[0] = 0;
    for(int i = 1; i <= n; i++){
    	b[i] = b[i - 1] + (s[i - 1] == 'a');
    }

    int ans = 0;
    
    for(int l1 = 0; l1 <= n; l1++){
    	for(int l2 = 0; l2 + l1 <= n; l2++){
    		int l3 = n - l1 - l2;
    		// a1 = [1, l1]
    		int a1 = b[l1];
    		// b1 = [l1 + 1, l1 + 1 + l2]
    		int b1 = l2 - b[l1 + l2] + b[l1];
    		// a2 = [l1 + l2, n]
    		int a2 = b[n] - b[l1 + l2];
    		chkmax(ans, a1 + b1 + a2);
    	}
    }

    cout << ans << endl;
    return 0;
}