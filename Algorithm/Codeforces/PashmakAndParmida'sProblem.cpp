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
const int N = (int)1e6 + 100;

/*
	we need to first calculate pre[i] and suf[i];
	which directly tells us how many occurrences of a[i] appears in the 
	prefix [0, i] and suffix[i, n - 1]
	we can traverse the array and maintain a cnt[a[i]] array that stores the
	number of a[i] we've seen so far, from either direction
*/

int a[N], pre[N], suf[N], tot[N], cnt[N];
int t[N] = {0};
int sz = 0;

void add(int pos, int v){
	for(; pos <= N; pos += pos & - pos){
		t[pos] += v;
	}
}

int get(int pos){
	int res = 0;
	for(; pos > 0; pos -= pos & -pos){
		res += t[pos];
	}
	return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    int n;
    cin >> n;
    forn(i, n){
    	cin >> a[i];
    	tot[sz++] = a[i];
    }

    /*
		dicretization:
		put all of the data into an array and sort them
		iterate over all of them and give them a new label
		O(nlogn)
    */
    sort(tot, tot + sz);
    sz = unique(tot, tot + sz) - tot;
    for(int i = 0; i < n; i++) a[i] = lower_bound(tot, tot + sz, a[i]) - tot;

	FILL(cnt, 0);    	
    for(int i = 0; i < n; i++){
    	cnt[a[i]]++;
    	pre[i] = cnt[a[i]];
    }

    FILL(cnt, 0);
    for(int i = n - 1; i >= 0; i--){
    	cnt[a[i]]++;
    	suf[i] = cnt[a[i]];
    }

    ll ans = 0;
    for(int i = n - 1; i >= 0; i--){
    	ans += (ll)get(pre[i] - 1);
    	add(suf[i], 1);
    }

    cout << ans << endl;
    return 0;
}