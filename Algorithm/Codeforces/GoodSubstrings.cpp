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
const int MOD1 = (int) 1e9 + 9;
const int P = 26;
const int P1 = 37;

const int N = 1500 + 10;
const int K = 24;

ll power[N], h[N];
ll h1[N];
int k;
set<ll> res;
set<ll> res1;
string s, ok;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

	cin >> s >> ok >> k;
	int	n = s.size();  
	
	vector<int> occ(n + 1, 0);
	occ[0] = 0;
	for(int i = 1; i <= n; i++){
		occ[i] = occ[i - 1] + (ok[i - 1] == '0');		
	}

	power[0] = 1;
	for(int i = 1; i < N; i++) 
		power[i] = (power[i - 1] * P) % MOD;
	h[0] = 0;
	for(int i = 0; i < n; i++)
		h[i + 1] = (h[i] + (s[i] - 'a' + 1) * power[i]) % MOD;

	h1[0] = 0;
	for(int i = 0; i < n; i++)
		h1[i + 1] = (h1[i] + (s[i] - 'a' + 1) * power[i]) % MOD1;

	int ans = 0;
	for(int l = 1; l <= n; l++){
		for(int i = 0; i + l - 1 < n; i++){
			int ret = occ[i + l] - occ[i];
			if(ret <= k){
				ll cur_h_1 = (h[i + l] + MOD - h[i]) % MOD;
				cur_h_1 = (cur_h_1 * power[n - i]) % MOD;

				ll cur_h_2 = (h1[i + l] + MOD1 - h1[i]) % MOD1;
				cur_h_2 = (cur_h_2 * power[n - i]) % MOD1;
				
				if(res.find(cur_h_1) == res.end() && res1.find(cur_h_2) == res1.end()){
					ans++;
					res.insert(cur_h_1);
					res1.insert(cur_h_2);
				}
			}
		}
	}

	cout << ans << endl;

    return 0;
}