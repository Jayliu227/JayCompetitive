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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;    
    bool ok = true;
    
    vi a(n);
    forn(i, n) cin >> a[i];

    for(int i = 1; i < n; i++){
    	int x1, y1;
    	if(a[i - 1] < a[i]){
    		x1 = a[i - 1], y1 = a[i];
    	}else{
    		x1 = a[i], y1 = a[i - 1];
    	}
    	for(int j = i + 1; j < n; j++){
    		int x2, y2;
    		if(a[j - 1] < a[j]){
    			x2 = a[j - 1], y2 = a[j];
    		}else{
    			x2 = a[j], y2 = a[j - 1];
    		}
    		if((x1 < x2 && y1 > x2 && y1 < y2) || (x2 < x1 && y2 > x1 && y1 > y2)){
    			ok = false;
    			break;
    		}
    	}
    }

    if(ok){
        cout << "no" << endl;
    }else{
        cout << "yes" << endl;
    }
    return 0;
}