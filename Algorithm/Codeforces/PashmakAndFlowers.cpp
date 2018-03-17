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
const int maxn = (int) 1e7 + 10;

int arr[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    ll n;
    int mx = 0, mn = INF;
    cin >> n;
    forn(i, n){
        int in; cin >> in;
        arr[i] = in;
        mx = max(mx, in);
        mn = min(mn, in);
    }
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    cout << mx - mn << " ";
    ll mxc = 0, mnc = 0;
    forn(i, n){
        if(arr[i] == mx) mxc++;
        if(arr[i] == mn) mnc++;
    }
    
    if(mx == mn)
        cout << (n * (n - 1) / 2) << endl;
    else
        cout << mxc * mnc << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}