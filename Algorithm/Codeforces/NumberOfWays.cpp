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
const int maxn = (int) 1e6;

int arr[maxn];
int cnt[maxn];
int occ[maxn];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    cin >> n;
    ll sum = 0;
    forn(i, n){
        int in; cin >> in;
        sum += in, arr[i] = in;
    }
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    if(sum % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    
    sum /= 3;
    ll partial = 0;
    FILL(cnt, 0);
    FILL(occ, 0);
    
    for(int i = n - 1; i >= 0; i--){
        partial += arr[i];
        if(partial == sum){
            cnt[i] = 1;
        }else{
            cnt[i] = 0;
        }
    }
    
    occ[n - 1] = cnt[n - 1];
    for(int i = n - 2; i >= 0; i--){
        occ[i] = occ[i + 1] + cnt[i];
    }
    
    ll res = 0;
    partial = 0;
    for(int i = 0; i < n - 2; i++){
        partial += arr[i];
        if(partial == sum){
            res += occ[i + 2];
        }
    }
    
    cout << res << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}