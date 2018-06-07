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
const int P = 31;

int power[12345];
int h[12345];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    string s;
    cin >> s;
    int n = s.size();

    power[0] = 1;
    for(int i = 1; i < 12345; i++) power[i] = power[i - 1] * P % MOD;
    h[0] = 0;
	for(int i = 0; i < n; i++) h[i + 1] = h[i] + (s[i] - 'a' + 1) * power[i] % MOD;

	int cnt = 0;
	for(int l = 1; l <= n; l++){
		set<int> s;
		for(int i = 0; i <= n - l; i++){
			int cur_h = (h[i + l] + MOD - h[i]) % MOD;
			cur_h = cur_h * power[n - i - 1];
			s.insert(cur_h);
		}
		cnt += s.size();
	}

	cout << "# of Distinct Substring of " << s << endl;
	cout << "is " << cnt << endl;

    return 0;
}