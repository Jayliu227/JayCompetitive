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
    map<int, int> cnt;

    forn(i, n*n){
        int k;
        cin >> k;
        ++cnt[-k];
    }

    vi ans(n);
    int pos = n - 1;
    for(auto i = cnt.begin(); i != cnt.end(); i++){
    	int x = -i->fi;
    	while(i->se--){
    		ans[pos] = x;
    		for(int j = pos + 1; j < n; j++){
    			cnt[-__gcd(ans[j], ans[pos])] -=2;
    		}
    		pos--;
    	}
    }

    for(int i = 0; i < n; i++){
        if(i == 0){
            cout << ans[i];
        }else{
            cout << " " << ans[i];
        }
    }
    cout << endl;
    return 0;
}