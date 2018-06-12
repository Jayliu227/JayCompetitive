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

const int N = (int) 1e5 + 10;
string s, t;
int pi[N];

void kmp(string& s){
	pi[0] = 0;
	int n = s.size();
	for(int i = 1; i < n; i++){
		int j = pi[i - 1];
		while(j > 0 && s[j] != s[i]){
			j = pi[j - 1];
		}

		if(s[j] == s[i]) j++;
		pi[i] = j;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> t >> s;

    string ss = s + '#' + t;
    kmp(ss);

    for(int i = 0; i < ss.size(); i++) if(pi[i] == s.size()){
    	/*
			the reason why we choose i - 2n is because
			i is the index of the occurrence's last char
			the length of s is n;
			we need to first substract n + 1 from i because of s + '#'
			and we need to substract (n - 1) from it too because we want to
			get the starting pos of this occurrence
			thus ans = i - (n + 1) - (n - 1)
					 = i - 2n
    	*/
    	cout << (i - 2 * s.size()) << endl;
    }

    return 0;
}