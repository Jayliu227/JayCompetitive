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

int const N = 123456;

bool lucky[N];
int a[N];
int t[N];

void add(int i, int x){
	for(; i < N; i += i & -i){
		t[i] += x;
	}
}

int get(int i){
	int res = 0;
	for(; i > 0; i -= i & -i){
		res += t[i];
	}
	return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < N; i++){
    	int num = i; 
    	bool ok = true;
    	while(num){
    		int k = num % 10;
    		if(k != 4 && k != 7){
    			ok = false;
    			break;
    		}
    		num /= 10;
    	}
    	lucky[i] = ok;
    }

    FILL(t, 0);

    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	if(lucky[a[i]]){
    		add(i, 1);
    	}
    }

    string t;
    int l, r, v;
    // 1e5
    forn(k, q){
    	cin >> t;
    	if(t[0] == 'c'){
    		cin >> l >> r;
    		cout << get(r) - get(l - 1) << endl;
    	}else{
    		cin >> l >> r >> v;
    		// 1e4
    		for(int i = l; i <= r; i++){
    			if(lucky[a[i]]){
    				add(i, -1);
    			}
    			a[i] += v;
    			if(lucky[a[i]]){
    				add(i, 1);
    			}
    		}
    	}
    }

    return 0;
}