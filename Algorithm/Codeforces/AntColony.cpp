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

const int N = 1234567;

struct node{
	int mn, gcd, cnt;
	node(){
		mn = INF;
		gcd = -1;
		cnt = 0;
	}
	node(int a, int b, int c) {
		mn = a; 
		gcd = b;
		cnt = c;
	}	
};

int n, q, a[N];
node sg[4 * N];

node resolve_node(node a, node b){
	int ngcd;
	if(a.gcd != -1 && b.gcd != -1){
		ngcd = __gcd(a.gcd, b.gcd);
	}else if(a.gcd == -1){
		ngcd = b.gcd;
	}else{
		ngcd = a.gcd;
	}

//	debug2(a.gcd, b.gcd);
//	debug(ngcd);
	if(a.mn < b.mn){
		return node(a.mn, ngcd, a.cnt);
	}else if(a.mn > b.mn){
		return node(b.mn, ngcd, b.cnt);
	}else{
		return node(a.mn, ngcd, a.cnt + b.cnt);
	}
}

void build(int v, int tl, int tr){
	if(tl == tr){
		sg[v].mn = a[tl];
		sg[v].gcd = a[tl];
		sg[v].cnt = 1;
	}else{
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		sg[v] = resolve_node(sg[v * 2], sg[v * 2 + 1]);
	}
}

node get(int v, int tl, int tr, int l, int r){
	if(l > r){
		return node(INF, -1, 0);
	}
	if(tl == l && tr == r){
		return sg[v];
	}else{
		int tm = (tl + tr) / 2;
		return resolve_node(get(v * 2, tl, tm, l, min(tm, r)),
							get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> n;
    forn(i, n) cin >> a[i];
    build(1, 0, n - 1);
    cin >> q;
    int l, r;


    while(q--){
    	cin >> l >> r;
    	l--, r--;
    	auto ans = get(1, 0, n - 1, l, r);
    	int eat = r - l + 1;
    	if(ans.mn == ans.gcd){
    		eat -= ans.cnt;
    	}
    	cout << eat << endl;
    }

    return 0;
}



