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

const int N = (int)2e5 + 10;

struct node{
	int l, r, id;
	operator< (node& b){
		return (l == b.l) ? r < b.r : l < b.l;
	}
};

node tv[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    int n;
    cin >> n;
    for1(i, n + 1){
    	cin >> tv[i].l >> tv[i].r;
    	tv[i].id = i;
    }

    sort(tv + 1, tv + n + 1);
    tv[0].l = -1, tv[0].r = -1;
    tv[n + 1].l = INF, tv[n + 1].r = -1;
    for1(i, n + 1){
    	if(tv[i - 1].r >= tv[i].r || tv[i + 1].l == tv[i].l){
    		cout << tv[i].id << endl;
    		return 0;
    	}
    	if(tv[i - 1].r >= tv[i + 1].l - 1 && tv[i].r <= tv[i + 1].r){
    		cout << tv[i].id << endl;
    		return 0;
    	}
    }
    cout << -1 << endl;
    return 0;
}

