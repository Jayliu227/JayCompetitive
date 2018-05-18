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
    string seat;
    cin >> n >> seat;
    
    int cnt = 0;

    if(n == 1 && seat[0] == '0'){
    	cout << "No" << endl;
    	return 0;
    }

    for(int i = 0; i < n; i++){
        if(seat[i] == '0') cnt++;
        else cnt = 0;
        if(cnt >= 3){
            cout << "No" << endl;
            return 0;
        }
    }

    if(n >= 2){
        if((seat[0] == seat[1] && seat[0] == '0') || (
            seat[n - 1] == seat[n - 2] && seat[n - 1] == '0')){
            cout << "No" << endl;
            return 0;
        }
    }

    for(int i = 0; i < n - 1; i++){
        if(seat[i] == '1' && seat[i] == seat[i + 1]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
#ifdef LOCAL_COMPILATION    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif    
    return 0;
}