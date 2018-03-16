#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define endl '\n'

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;


const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e4;

int arr[1010];

int main(){
    ios::sync_with_stdio(false);
    cout.precision(10);
    cin.tie(0);
//=======GET INPUT HERE============
    int n, l;
    cin >> n >> l;
    int mx = 0;
    forn(i, n){
        int lantern;
        cin >> lantern;
        arr[i] = lantern;
    }
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    sort(arr, arr + n);    
    
    forn(i, n - 1){
        mx = max(mx, arr[i + 1] - arr[i]);
    }
    mx = max(mx, arr[0] * 2);
    mx = max(mx, (l - arr[n - 1]) * 2);
    
    cout << mx / 2.0 << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}