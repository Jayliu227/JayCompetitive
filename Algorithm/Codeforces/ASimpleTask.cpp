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
const int MODULO = (int) 1e9 + 7;

/*
	1. remember the index of each char in a different vector
	2. everytime when we want to sort a certain interval, we
		can simply do lower_bound and upper_bound in each char
		vector and use counting sort because there are only 26
		objects.
	3. after all update queries, we can restore the result array
		by simply traversing all the char vector and get the final
		char at each position in the original string.
*/

vector<int> v[26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    int n, q, l, r, k;
    string str;
    cin >> n >> q >> str;

    for(int i = 0; i < n; i++) v[str[i] - 'a'].push_back(i);

    while(q--){
    	cin >> l >> r >> k;
    	l--, r--;
    	int pos = l;
    	if(k){
    		for(int i = 0; i < 26; i++){
    			int interval_left = lower_bound(ALL(v[i]), l) - v[i].begin();
    			int interval_right = upper_bound(ALL(v[i]), r) - v[i].begin();
    			for(int j = interval_left; j < interval_right; j++){
    				v[i][j] = pos++;
    			}
    		}
    	}else{
    		for(int i = 25; i >= 0; i--){
    			int interval_left = lower_bound(ALL(v[i]), l) - v[i].begin();
    			int interval_right = upper_bound(ALL(v[i]), r) - v[i].begin();
    			for(int j = interval_left; j < interval_right; j++){
    				v[i][j] = pos++;
    			}
    		}
    	}
    }

    for(int i = 0; i < 26; i++){
    	for(int j = 0; j < v[i].size(); j++){
    		str[v[i][j]] = (char)(i + 'a');
    	}
    }

    cout << str << endl;
    return 0;
}